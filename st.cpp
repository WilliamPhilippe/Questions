#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class SegmentTree
{

private:
    vll st;
    ll arr_size;

public:
#define LEFT(idx) (idx << 1)
#define RIGHT(idx) ((idx << 1) | 1)
#define MID(id, ix) ((id + ix) >> 1)
    ll lambda(ll first, ll second)
    {
        return first + second;
    }
    void build(ll idx, ll left, ll right, vll &arr)
    {
        if (left == right)
        {
            st[idx] = arr[left];
            return;
        }
        ll mid = MID(left, right);
        build(LEFT(idx), left, mid, arr);
        build(RIGHT(idx), mid + 1, right, arr);
        st[idx] = lambda(st[LEFT(idx)], st[RIGHT(idx)]);
    }
    ll query(ll idx, ll left, ll right, ll L, ll R)
    {
        if (left > R || right < L)
            return 0;
        if (left >= L && right <= R)
            return st[idx];
        ll mid = MID(left, right);
        return lambda(query(LEFT(idx), left, mid, L, R),
                      query(RIGHT(idx), mid + 1, right, L, R));
    }
    void update(ll idx, ll left, ll right, ll pos, ll value)
    {
        if (left > pos || right < pos)
            return;
        if (left == right)
        {
            st[idx] = value;
            return;
        }
        ll mid = MID(left, right);
        update(LEFT(idx), left, mid, pos, value);
        update(RIGHT(idx), mid + 1, right, pos, value);
        st[idx] = lambda(st[LEFT(idx)], st[RIGHT(idx)]);
    }
    ll query(ll L, ll R)
    {
        if (L > R)
            swap(L, R);
        return query(1, 0, arr_size - 1, L, R);
    }
    ll update(ll pos, ll value)
    {
        update(1, 0, arr_size - 1, pos, value);
    }

public:
    SegmentTree(vll &arr)
    {
        arr_size = arr.size();
        st.assign(4 * arr_size, 0);
        build(1, 0, arr_size - 1, arr);
    }
};

int main()
{
    vll A = {2, 0, 1, 9};
    SegmentTree st(A);
    cout << st.query(0, A.size() - 1);
    return 0;
}
