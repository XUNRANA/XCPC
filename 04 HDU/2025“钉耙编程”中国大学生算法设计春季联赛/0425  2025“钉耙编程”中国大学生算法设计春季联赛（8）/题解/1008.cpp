#include<bits/stdc++.h>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define endl '\n'
#ifdef D
    void dbg() {cerr << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cerr << a << ' '; dbg(x...);}
    #define logs(x...) {cerr << #x << " -> "; dbg(x);}
#else
    #define logs(...) {}
#endif
typedef long long ll; 
const int N = 1e5 + 555;
const ll INF = 1e18;
ll w[N], sum_w;
int n, k; 
vector<int> g[N];
ll s[N];
int fa[N];
ll f[N][22];
int h[N][22][2]; // h[u][j][0] = v means v is the heaviest son of u s.t. f[v][j] = true 
// h[u][j][1] = the 2nd heaviest 

#define forSon(v, u) for(auto v: g[u])if(v!=fa[u])

int num_of_sons(int u) {
    return u == 1 ? g[u].size() : g[u].size() - 1;
}

void dfs_one(int u) {
    s[u] = w[u];
    forSon(v, u) {
        fa[v] = u;
        dfs_one(v);
        s[u] += s[v];
    }
}

void dfs_two(int u) {
    f[u][0] = s[u];
    forSon(v, u) {
        dfs_two(v);
        rep(j,1,k-1) {
            f[u][j] = min(f[u][j], max(s[u] - s[v], f[v][j - 1]));
        }
    }
}


void update_best(int* b, int v) {
    if (s[v] > s[b[0]]) {
        b[1] = b[0];
        b[0] = v;
    } else if (s[v] > s[b[1]]) {
        b[1] = v;
    }
}

bool check(ll mid, int u, int a, int b) {
    int besta[2] = {0, 0}, vb = 0;
    forSon(v, u) {
        if (f[v][a - 1] <= mid) {
            update_best(besta, v);
        }
        if (f[v][b - 1] <= mid && s[v] > s[vb]) {
            vb = v;
        }
    }
    int va = besta[0] == vb ? besta[1] : besta[0];
    return va && vb && s[1] - s[va] - s[vb] <= mid;
}

void solve() {
    cin >> n >> k; 
    sum_w = 0;
    rep(i,1,n) {
        g[i].clear();
        fa[i] = 0;
        cin >> w[i];
        sum_w += w[i];
    }
    rep(i,1,n-1) {
        int x, y; 
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs_one(1);

    ll ans = INF;
    rep(u,1,n) rep(j,0,k-1) f[u][j] = INF;
    dfs_two(1);

    rep(u,1,n) if (num_of_sons(u)) {
        // try cut one child
        forSon(v, u) {
            ans = min(ans, max(s[1] - s[v], f[v][k - 1]));
        }
        // at least two children
        if (num_of_sons(u) == 1) continue;
        
        // cut two different children 
        // use binary search here
        rep(a, 1, k - 1) {
            int b = k - a;
            // cut a-1 in the first child,
            // b-1 in the second child
            // what's the min of max
            ll l = 0, r = s[u];
            if (!check(r, u, a, b)) continue;
            while (l < r) {
                ll mid = l + (r - l) / 2;
                int c = check(mid, u, a, b);
                if (check(mid, u, a, b)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, l);
        }
    }

    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}