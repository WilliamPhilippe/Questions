#include <bits/stdc++.h>

using namespace std;
typedef long int ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vp;
typedef vector<ll> vll;

class SegmentTree
{

private:
  vp st;
  ll arr_size;

public:
#define LEFT(idx) (idx << 1)
#define RIGHT(idx) ((idx << 1) | 1)
#define MID(id, ix) ((id + ix) >> 1)
  ll par(ll x)
  {
    return x % 2 == 0 ? 1 : 0;
  }
  ll impar(ll x) { return x % 2 == 0 ? 0 : 1; }
  void build(ll idx, ll left, ll right, vll &arr)
  {
    if (left == right)
    {
      st[idx] = make_pair(par(arr[left]), impar(arr[left]));
      return;
    }

    ll mid = MID(left, right);
    build(LEFT(idx), left, mid, arr);
    build(RIGHT(idx), mid + 1, right, arr);
    st[idx] = make_pair(st[LEFT(idx)].first + st[RIGHT(idx)].first,
                        st[LEFT(idx)].second + st[RIGHT(idx)].second);
  }

  pll query(ll idx, ll left, ll right, ll L, ll R)
  {
    if (left > R || right < L)
    {
      return make_pair(0, 0);
    }
    if (left >= L && right <= R)
    {
      return st[idx];
    }

    ll mid = MID(left, right);
    pll pairLeft = query(LEFT(idx), left, mid, L, R);
    pll pairRight = query(RIGHT(idx), mid + 1, right, L, R);

    return make_pair(pairLeft.first + pairRight.first,
                     pairLeft.second + pairRight.second);
  }

  pll query(ll L, ll R)
  {
    if (L > R)
      swap(L, R);
    return query(1, 0, arr_size - 1, L, R);
  }

  void update(ll idx, ll left, ll right, ll pos, ll value)
  {
    if (left > pos || right < pos)
    {
      return;
    }
    if (left == right)
    {
      st[idx] = make_pair(par(value), impar(value));
      return;
    }

    ll mid = MID(left, right);
    update(LEFT(idx), left, mid, pos, value);
    update(RIGHT(idx), mid + 1, right, pos, value);
    st[idx] = make_pair(st[LEFT(idx)].first + st[RIGHT(idx)].first,
                        st[LEFT(idx)].second + st[RIGHT(idx)].second);
  }

  void update(ll pos, ll value)
  {
    update(1, 0, arr_size - 1, pos, value);
  }

public:
  SegmentTree(vll &arr)
  {
    arr_size = arr.size();
    st.assign(4 * arr_size, make_pair(0, 0));
    build(1, 0, arr_size - 1, arr);
  }
};

int main()
{
  ll var, N, Q;
  cin >> N;

  vll L;

  for (int i = 0; i < N; i++)
  {
    cin >> var;
    L.push_back(var);
  }

  SegmentTree st(L);

  cin >> Q;

  ll op, a, b;

  for (int i = 0; i < Q; i++)
  {
    cin >> op >> a >> b;

    switch (op)
    {
    case 0:
      st.update(a - 1, b);
      break;
    case 1:
      cout << st.query(a - 1, b - 1).first << endl;
      break;
    case 2:
      cout << st.query(a - 1, b - 1).second << endl;
      break;
    }
  }

  return 0;
}