#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegmentTree{
private:
    struct node{
        int l, r;
        ll cnt, s, laz;
        node(int l = 0, int r = 0, ll cnt = 0, ll s = 0, ll laz = 0): l(l), r(r), cnt(cnt),
        s(s), laz(laz){}
    };


    #define ls (i << 1)
    #define rs (i << 1 | 1)
    #define mid (l + r >> 1)

    vector<node> tr;

    void pushUp(int i) {
        tr[i].s = tr[ls].s + tr[rs].s;
        tr[i].cnt = tr[ls].cnt + tr[rs].cnt;
    }

    void pushDown(int i) {
        auto laz = tr[i].laz;
        tr[i].laz = 0;
        if (laz) {
            tr[ls].s += laz * tr[ls].cnt;
            tr[rs].s += laz * tr[rs].cnt;
            tr[ls].laz += laz;
            tr[rs].laz += laz;
        }
    }

    void build(int i, int l, int r, vector<ll>& a, vector<ll>& s) {
        tr[i] = {l, r, 0, 0, 0};
        if (l == r) {
            tr[i].cnt += s[l];
            tr[i].s += a[l];
            return;
        }

        build(ls, l, mid, a, s);
        build(rs, mid + 1, r, a, s);
        pushUp(i);
    }

public:

    SegmentTree(int n, vector<ll>& a, vector<ll>& s): tr(n * 4) {
        build(1, 1, n, a, s);
    }

    void add(int i, int x, int y, ll k) {
        if (x <= tr[i].l and tr[i].r <= y) 
        {   
            tr[i].s += tr[i].cnt * k;
            tr[i].laz += k;
            return;
        }

        pushDown(i);

        int m = tr[i].l  + tr[i].r >> 1;
        if (x <= m) add(ls, x, y, k);
        if (y > m) add(rs, x, y, k);

        pushUp(i);
    }

    void udt(int i, int x, int y) 
    {
        if (tr[i].l == x and tr[i].r == y) {
            tr[i].cnt ^= 1; 

            return;
        }
        pushDown(i);
        int m = tr[i].l  + tr[i].r >> 1;
        if (x <= m) udt(ls, x, y);
        if (y > m) udt(rs, x, y);

        pushUp(i);
    }

    ll query(int i, int x, int y) {
        if (y < tr[i].l or x > tr[i].r) return 0;
        if (x <= tr[i].l and tr[i].r <= y) return tr[i].s;

        pushDown(i);
        ll res = 0;
        int m = tr[i].l + tr[i].r >> 1;
        if (x <= m) res += query(ls, x, y);
        if (y > m) res += query(rs, x, y);
        return res;
    }
};


void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> s(n + 1);    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> s[i];

    SegmentTree tr(n, a, s);
    
    while (q--) {
        
        int op; cin >> op;
        if (op == 1 or op == 2) {
            int x; cin >> x;
            tr.udt(1, x, x);
        } else if (op == 3) {
            ll x, y, k; cin >> x >> y >> k;
            tr.add(1, x, y, k);
        } else {
            int x, y; cin >> x >> y;
            cout << tr.query(1, x, y) << '\n';
        } 
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}