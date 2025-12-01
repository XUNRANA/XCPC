/*
    Author : Sparkle_ZH & Spark1037
    Right Output ! & Accepted !
*/

#include <bits/stdc++.h>
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define pii pair<int, int>
#define ll long long
#define pb push_back
#define fir first
#define sec second
using namespace std;

namespace fast_IO {
    template<typename T> inline void read(T &x, bool g = 0) {
        x = 0; bool f = 0; char ch = getchar();
        while (! isdigit(ch)) f |= (ch == '-'), ch = getchar();
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + ch - '0';
            if (g) break; ch = getchar();
        } x = (f ? - x : x);
    }
    
    template<typename T, typename... Args> inline void read(T &first, Args& ... args) {
        read(first);
        read(args...);
    }

    template<typename T> inline void write(T x, int f = -1) {
        if (x < 0) x = -x, putchar('-'); static short Stack[50], top(0);
        do Stack[++ top] = x % 10, x /= 10; while (x);
        while (top) putchar(Stack[top --] | 48);
        if (~ f) (f ? putchar('\n') : putchar(' '));
    }
} using namespace fast_IO;

const int N = 5e3 + 5, P = 1e9 + 7;
int n, k, fa, a[N], t[N], f[N], g[N][2];
vector<int> e[N];

int mod(int x) { return x < P ? x : x - P; }
void add(int &x, int y) { x = mod(x + y); }

void dfs(int u, int mx, int mn) {
    g[u][0] = 1, g[u][1] = 0;
    if (a[u] > mn + k || a[u] < mx - k) { g[u][0] = f[u]; return ; }

    for (int i : e[u])
        dfs(i, max(mx, a[u]), min(mn, a[u])),
        t[i] = 1ll * g[u][0] * g[i][1] % P,
		g[u][0] = 1ll * g[u][0] * g[i][0] % P;
		
	reverse(e[u].begin(), e[u].end());
	
	ll cur = 1;
	for (int i : e[u])
		add(g[u][1], 1ll * t[i] * cur % P),
		cur = 1ll * cur * g[i][0] % P;
        
    add(g[u][1], g[u][0]), add(g[u][0], f[u]);
}

void solve(int u) {
    for (int i : e[u]) solve(i);
    dfs(u, a[u], a[u]), f[u] = g[u][1];
}

signed main() {
	int T; read(T);
	while(T --) {
		memset(t, 0, sizeof(t));
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
	    read(n, k);
	    for (int i = 1; i <= n; i ++) e[i].clear();
	    for (int i = 1; i <= n; i ++) read(a[i]);
	    for (int i = 2; i <= n; i ++) read(fa), e[fa].pb(i);
	    
	    solve(1); write(f[1], 1);
	}
    return 0;
}
