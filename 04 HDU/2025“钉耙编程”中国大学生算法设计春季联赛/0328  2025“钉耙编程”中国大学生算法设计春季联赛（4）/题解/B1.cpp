#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

const int P = 1e9 + 7;
inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}
inline void add(int &x, int y) {x = plu(x, y);}
inline void sub(int &x, int y) {x = del(x, y);}
inline int qpow(int a, int b) {int s = 1; for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) s = 1ll * s * a % P; return s;}

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 5010;
int n, k, a[N], par[N];
vector<int> g[N];

int d[N], h[N];
void dfs1(int u, int cur) {
	d[u] = cur;
	h[u] = cur;
	for(int o = par[u], i = cur - 1; i >= 1; i --, o = par[o])
		if(abs(a[u] - a[o]) <= k) h[u] = i; else break;
	for(auto v : g[u]) dfs1(v, cur + 1);
}

int f[N][N][2];

int s[N][2];
int t[N][2];

void dfs2(int u) {
	
	f[u][h[u]][0] = 1;
	f[u][h[u]][1] = 1;
	
	for(auto v : g[u]) {
		dfs2(v);
		rep(o, 0, 1) {
			rep(i, 1, d[v]) s[i][o] = plu(s[i - 1][o], f[v][i][o]);
			rep(i, 1, d[u]) t[i][o] = plu(t[i - 1][o], f[u][i][o]);
		}
		
		rep(i, h[u], d[u]) {
			int a = f[u][i][1]; f[u][i][1] = 0;
			int b = f[u][i][0]; f[u][i][0] = 0;

			add(f[u][i][1], 1ll * a * plu(s[i][0], s[d[v]][1]) % P);
			add(f[u][i][1], 1ll * b * s[i][1] % P);
			add(f[u][i][1], 1ll * f[v][i][0] * t[i - 1][1] % P); 
			add(f[u][i][1], 1ll * f[v][i][1] * t[i - 1][0] % P);
			
			add(f[u][i][0], 1ll * b * plu(s[i][0], s[d[v]][1]) % P);
			add(f[u][i][0], 1ll * f[v][i][0] * t[i - 1][0] % P);
		}
	}
	
	// cerr << "this " << u << endl;
	// rep(i, h[u], d[u]) cerr << "f " << i << ' ' << f[u][i][0] << ' ' << f[u][i][1] << endl;
}

void solve() {
	n = read(), k = read();
	rep(i, 1, n) {
		a[i] = read(), g[i].clear();
		rep(j, 0, n) f[i][j][0] = f[i][j][1] = 0;
	}
	rep(i, 2, n) par[i] = read(), g[par[i]].push_back(i);
	
	dfs1(1, 1);
	dfs2(1);
	
	printf("%d\n", f[1][1][1]);
}

int main() {
	int t = read(); while(t --) solve(); return 0;
}
