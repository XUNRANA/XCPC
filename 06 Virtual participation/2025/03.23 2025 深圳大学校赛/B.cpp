#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

template<class T>
class SegmentTree {
public:
#define lt (i << 1)
#define rt ((i << 1) | 1)
#define mid ((l + r) >> 1)
    struct node {
        int l, r;
        T tag;
        array<ll, 2> val;
        node(int l = 0, int r = 0, array<ll, 2> val = {LLONG_MAX, LLONG_MAX}, T tag = 0): l(l), r(r), val(val), tag(tag) {}
    };

    vector<node> tr;

    SegmentTree(int n, vector<T> &w): tr(n << 2) {
        build(1, 1, n, w);
    }

    void pushUp(int i) {
        tr[i].val = min(tr[lt].val, tr[rt].val);
    }

    void pushDown(int i) {
        if (tr[i].tag) {
            T t = tr[i].tag;
            tr[i].tag = 0;
            tr[lt].tag += t;
            tr[rt].tag += t;
            tr[lt].val[0] += t;
            tr[rt].val[0] += t;
        }
    }

    void build(int i, int l, int r, vector<T>& w) {
        tr[i] = node(l, r);
        if (l == r) {
            tr[i].val = {w[l], l};
            return;
        }

        build(lt, l, mid , w);
        build(rt, mid + 1, r, w);
        pushUp(i);
    }

    void add(int i, int l, int r, T k) {
        if (l <= tr[i].l and tr[i].r <= r) {
            tr[i].val[0] += k;
            tr[i].tag += k;
            return;
        }

        pushDown(i);
        int m = tr[i].l + tr[i].r >> 1;
        if (l <= m) add(lt, l, r, k);
        if (r > m) add(rt, l, r, k);
        pushUp(i);
    }

    array<ll, 2> query(int i, int l, int r) {
        if (l <= tr[i].l and tr[i].r <= r) return tr[i].val;
        if (tr[i].r < l || tr[i].l > r) return {LLONG_MAX, LLONG_MAX};

        pushDown(i);
        array<ll, 2> res = {LLONG_MAX, LLONG_MAX};
        int m = tr[i].l + tr[i].r >> 1;
        if (l <= m) res = min(res, query(lt, l, r));
        if (r > m) res = min(res, query(rt, l, r));
        return res;
    }
};

auto getOddL(int l) {
    return (l + 2) / 2;
}

auto getOddR(int r) {
    return (r + 1) / 2;
}

auto getEvenL(int l) {
    return (l + 1) / 2;
}

auto getEvenR(int r) {
    return r / 2;
}

void solve() {
    int n, m; cin >> n >> m;
    if (n == 1) {
        ll x; cin >> x;
        while (m--) {
            ll l, r, k; cin >> l >> r >> k;
            x += k;
            if(!x) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        return;
    }


    vector<ll> w1(n + 1), w2(n + 1); // odd, even
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (i & 1) w1[++cnt1] = x;
        else w2[++cnt2] = x;
    }
    // int n1 = (n + 1) / 2, n2 = n / 2;
    SegmentTree<ll> odd(cnt1, w1), even(cnt2, w2);
    ll idx = -1;

    while (m--) {
        int l, r;
        ll k;
        cin >> l >> r >> k;
        auto L = getOddL(l), R =  getOddR(r);
        if (L <= R) odd.add(1, L, R, k);
        L = getEvenL(l);
        R = getEvenR(r);
        if (L <= R) even.add(1, L, R, k);
        array<ll, 2> res = odd.query(1, 1, cnt1);
        idx = res[1] - 1;
        if (res[0] != 0) {
            if (n & 1) cout << 0 << '\n';
            else cout << even.query(1, 1, cnt2)[0] << '\n';
        }
        else {
            if (idx < 1) cout << -1 << '\n';
            else cout << even.query(1, 1, idx)[0] << '\n';
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}