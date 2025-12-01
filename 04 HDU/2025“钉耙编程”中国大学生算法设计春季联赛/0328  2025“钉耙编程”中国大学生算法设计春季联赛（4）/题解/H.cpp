#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
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

const int N = 1e6 + 10;
int n, k;
vector<int> a[N];
vector<int> f[N];

int main() {
	int T = read();
	while(T --){
		n = read(), k = read();
		f[0].resize(k + 1);
		rep(i, 1, n) {
			a[i].clear();
			f[i].clear();
			a[i].resize(k + 1);
			f[i].resize(k + 1);
			rep(j, 1, k) a[i][j] = read();
		}
		
		rep(i, 1, n) rep(j, 1, k) f[i][j] = max(f[i - 1][j] + a[i][j], f[i][j - 1]);
		printf("%d\n", f[n][k]);
	}
	return 0;
}
