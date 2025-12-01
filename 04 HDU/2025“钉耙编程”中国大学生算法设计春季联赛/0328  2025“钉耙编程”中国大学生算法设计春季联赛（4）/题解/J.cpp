#include<bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

const int P = 1e9 + 7;
inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}
inline void add(int &x, int y) {x = plu(x, y);}
inline void sub(int &x, int y) {x = del(x, y);}

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e5 + 10;
int n, c, m, a[N], sum[N], dat[N];
vector<int> g[N], h[N];
bool v[N];

void solve() {
	n = read(), c = read();
	
	memset(sum, 0, sizeof(sum));
	memset(dat, 0, sizeof(dat));
	
	rep(i, 1, max(n, c)) g[i].clear(), h[i].clear(), v[i] = false;
	
	rep(i, 1, n) a[i] = read();
	m = read();
	rep(i, 1, m) {
		int u = read(), v = read();
		g[u].eb(v); if(u != v) g[v].eb(u);
	}
	
	int lim = (int) sqrt(n);
	rep(i, 1, c) if((int) g[i].size() > lim)
		{v[i] = true; for(int o : g[i]) h[o].eb(i);}
	rep(i, 1, n) {
		int x = a[i], cur = (i == 1);
		if(v[x]) add(cur, dat[x]);
		else {for(int o : g[x]) add(cur, sum[o]);}
		if(i == n) return printf("%d\n", cur), void();
		add(sum[x], cur);
		for(int o : h[x]) add(dat[o], cur);
	}
}

int main() {
	int t = read(); while(t --) solve(); return 0;
}
