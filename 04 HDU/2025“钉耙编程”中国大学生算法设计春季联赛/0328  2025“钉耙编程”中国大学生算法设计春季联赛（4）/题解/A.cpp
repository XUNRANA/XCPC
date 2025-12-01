#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e4 + 10;
int n, u, k, hp, a[N];
struct node {int a, h, id;} s[N];

bool cmp(node x, node y) {
	return x.h == y.h ? ( x.a < y.a) : x.h < y.h;
}

void solve() {
	n = read(), u = read(), k = read(), hp = read();
	rep(i, 1, n)
		s[i].a = read(), s[i].h = read(), s[i].id = i;
	sort(s + 1, s + n + 1, cmp);
	a[n + 1] = 0;
	per(i, n, 1) a[i] = max(a[i + 1], s[i].a);
	
	int ans = 0;
	rep(i, 1, n) {
		if(hp <= 0) break;
		
		if(s[i].h <= u) {
			ans ++, hp -= a[i + 1];
			continue;
		} else
			s[i].h -= u, hp -= a[i];
		
		if(hp <= 0) break;
		
		int tim = min(k-1, (s[i].h + (u>>1) - 1) / (u>>1));
		
		if(tim > 1) {
			if(1ll * (tim - 1) * a[i] >= hp) break;
			hp -= (tim - 1) * a[i];
			s[i].h -= min(1ll * (tim - 1) * (u>>1), 1ll * s[i].h);
		}
		
		if(tim>0&&(s[i].h <= (u>>1))) ans ++, hp -= a[i + 1]; 
        else break;
	}
	
	printf("%d\n", ans);
}

signed main() {
	int t = read(); while(t --) solve(); return 0;
}
