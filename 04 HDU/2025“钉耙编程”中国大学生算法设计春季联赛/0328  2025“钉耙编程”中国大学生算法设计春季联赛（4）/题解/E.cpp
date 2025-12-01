#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 10010;
int n[2], p[2][N];

void solve() {
	
	n[0] = n[1] = 0;
	
	double P = read();
	int nn = read(), k = read();
	while(nn --) {
		int o = read();
		p[o][++ n[o]] = read();
	}
	
	sort(p[0], p[0] + n[0] + 1);
	sort(p[1], p[1] + n[1] + 1);
	
	double sum = 0, dsc = 1.0;

	per(i, n[1], max(1, n[1] - k + 1))
		sum += p[1][i];
	rep(i, 1, min(n[0], k - n[1]))
		dsc = dsc * p[0][i] / 10.0;
	
	int pos = min(n[0], max(0, k - n[1]));
	double ans = max(0.0, P * dsc - sum);

	rep(i, max(1, n[1] - k + 1), n[1]) {
		pos ++;
		if(pos <= n[0]) dsc = dsc * p[0][pos] / 10.0;
		sum -= p[1][i];
		ans = min(ans, max(0.0, P * dsc - sum));	
	}
	
	printf("%.2f\n", ans);
}

int main() {
	int t = read(); while(t --) solve(); return 0;
}
