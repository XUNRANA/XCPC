#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
// #include<unordered_map>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
#include<climits>
#include<iomanip>
using namespace std;
#define rep(i,from,to) for(int i=(int)(from);i<=(int)(to);++i)
#define rev(i,from,to) for(int i=(int)(from);i>=(int)(to);--i)
#define For(i,to) for(int i=0;i<(int)(to);++i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define printCase(i) printf("Case %d: ", i)
#define endl '\n'
#define coutP(i) cout<<fixed<<setprecision(i)
#ifdef D
    void dbg() {cerr << "\n";}
    template<typename T, typename... A> void dbg(T a, A... x) {cerr << a << ' '; dbg(x...);}
    #define logs(x...) {cerr << #x << " -> "; dbg(x);}
#else
    #define logs(...) {}
#endif
#define mmst(a,x) memset(a, x, sizeof(a))
typedef long long ll; typedef long double ld; typedef double db;
typedef pair<ll,ll> pll; typedef pair<int,int> pii; typedef vector<ll> vll; typedef vector<int> vint;
template <typename T> vector<T>& operator<< (vector<T> &v, T &x) { v.emplace_back(x); return v; }
struct MyIn { 
    template <typename T> MyIn& operator>> (T &x) { x=0;bool s=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')s=1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}if(s)x=-x;return (*this); } 
} rin;

const int N = 1e5 + 100;

struct Edge {
    ll u, v;
    ll x, y, z;
    ll i; 
};

struct MergeSet {
    int pa[N];

    void init(int m) {
        rep(i,1,m) pa[i] = i;
    }

    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]); 
    }

    void merge(int x, int y) {
        pa[find(x)] = find(y); 
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
} ms;

ll n, m;
ll x[N], y[N], z[N];
vector<Edge> edges;
vector<tuple<ll, ll, ll>> groups;

bool cmp_x(const Edge &e1,  const Edge &e2) {
    return e1.x < e2.x;
}
bool cmp_y(const Edge &e1, const Edge &e2) {
    return e1.y < e2.y;
}
bool cmp_z(const Edge &e1, const Edge &e2) {
    return e1.z < e2.z;
}


ll cost(Edge &e1, Edge &e2) {
    return min(abs(e1.x - e2.x), min(abs(e1.y - e2.y), abs(e1.z - e2.z)));
}


void solve() {
    edges.clear();
    groups.clear();

    cin >> n >> m;
    rep(i, 1, n) {
        cin >> x[i] >> y[i] >> z[i]; 
    }
    rep(i, 1, m) {
        ll u, v; 
        cin >> u >> v; 
        edges.push_back((Edge){u, v, x[u] + x[v], y[u] + y[v], z[u] + z[v], i});
    }


    sort(edges.begin(), edges.end(), cmp_x);
    For(i, edges.size() - 1) {
        Edge &e1 = edges[i];
        Edge &e2 = edges[i + 1];
        groups.push_back(make_tuple(cost(e1, e2), e1.i, e2.i));
    }

    sort(edges.begin(), edges.end(), cmp_y);
    For(i, edges.size() - 1) {
        Edge &e1 = edges[i];
        Edge &e2 = edges[i + 1];
        groups.push_back(make_tuple(cost(e1, e2), e1.i, e2.i));
    }

    sort(edges.begin(), edges.end(), cmp_z);
    For(i, edges.size() - 1) {
        Edge &e1 = edges[i];
        Edge &e2 = edges[i + 1];
        groups.push_back(make_tuple(cost(e1, e2), e1.i, e2.i));
    }

    ms.init(m);
    sort(groups.begin(), groups.end());
    ll cost_sum = 0;
    for (auto &[c, i1, i2]: groups) {
        if (ms.same(i1, i2)) continue;
        cost_sum += c;
        ms.merge(i1, i2);
    }

    cout << cost_sum << endl;
}

int main() {
// #ifdef D
//     freopen("sample/1.in", "r", stdin);
//     clock_t TIMEA = clock();
// #else

    // freopen("star.out", "w", stdout);
// #endif

    int T; cin >> T; 
     while (T--) solve();
// #ifdef D
//     float TIMEUSED = (float)(clock()-TIMEA)/CLOCKS_PER_SEC;
//     if (TIMEUSED > 1e-3) printf("\n# Time consumed: %.3fs.\n", TIMEUSED);
// #endif
    return 0;
}