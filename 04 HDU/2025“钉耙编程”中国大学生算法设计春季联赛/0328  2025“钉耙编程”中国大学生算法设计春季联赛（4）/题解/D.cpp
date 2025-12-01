#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e5 + 10;
int n, a[N], b[N], ans;
vector<int> g[N];

bool check(int x) {
	return __builtin_popcount(x) <= 1;
}

void dfs(int u) {
	if(g[u].empty()) ans += check(b[u]);
	for(int v : g[u]) {
		b[v] = __gcd(b[u], a[v] - a[u]);
		dfs(v);
	}
}

void solve() {
	n = read(), ans = 0;
	rep(i, 1, n) g[i].clear();
	rep(i, 2, n) {
		int f = read();
		g[f].eb(i);
	}
	rep(i, 1, n) a[i] = read();
	dfs(1);
	printf("%d\n", ans);
}

int main() {
	int t = read(); while(t --) solve(); return 0;
}
