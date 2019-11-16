#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
  ll lambdaSum(ll first, ll second)
  {
    return first + second;
  }

  void build(ll idx, ll left, ll right, vll &arr)
  {
    if (left == right)
    {
      st[idx] = make_pair(arr[left], arr[left]);
      return;
    }

    ll mid = MID(left, right);
    build(LEFT(idx), left, mid, arr);
    build(RIGHT(idx), mid + 1, right, arr);
    st[idx] = make_pair(st[LEFT(idx)].first + st[RIGHT(idx)].first,
                        min(st[LEFT(idx)].second, st[RIGHT(idx)].second));
  }

  pll query(ll idx, ll left, ll right, ll L, ll R)
  {
    if (left > R || right < L)
    {
      return make_pair(0, INT_MAX);
    }
    if (left >= L && right <= R)
    {
      return st[idx];
    }

    ll mid = MID(left, right);
    pll pairLeft = query(LEFT(idx), left, mid, L, R);
    pll pairRight = query(RIGHT(idx), mid + 1, right, L, R);

    return make_pair(pairLeft.first + pairRight.first, min(pairLeft.second, pairRight.second));
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
      st[idx] = make_pair(value, value);
      return;
    }

    ll mid = MID(left, right);
    update(LEFT(idx), left, mid, pos, value);
    update(RIGHT(idx), mid + 1, right, pos, value);
    st[idx] = make_pair(st[LEFT(idx)].first + st[RIGHT(idx)].first,
                        min(st[LEFT(idx)].second, st[RIGHT(idx)].second));
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
  int n, x, q;
  char c;
  cin >> n;

  vll A;

  for (int i = 0; i < n; i++)
  {
    cin >> x;

    A.push_back(x);
  }

  SegmentTree st(A);

  cin >> q;
  getchar();

  for (int i = 0, l, r, p, v; i < q; i++)
  {
    c = getchar();

    if (c == 'Q')
    {
      cin >> l >> r;
      pll par = st.query(l, r);

      cout << par.first << " " << par.second << endl;
    }
    if (c == 'U')
    {
      cin >> p >> v;
      st.update(p, v);
    }

    getchar();
  }

  return 0;
}