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

#define int long long

const int N = 2e5 + 10;
int n, q, a[N];
int c[N];

void add(int x, int v) {for(; x <= n; x += (x & -x)) c[x] += v;}
int ask(int x) {int s = 0; for(; x; x -= (x & -x)) s += c[x]; return s;}

signed main() {
    int TT=read();
    while(TT--) {
        memset(c,0,sizeof c);
    	n = read(), q = read();
    	rep(i, 1, n) a[i] = read(), add(i, a[i]);
    	while(q --) {
    		int op = read(), x = read(), y = read();
    		if(op == 1) {
    			add(x, y - a[x]);
    			a[x] = y;
    		} else {
    			printf("%lld\n", ask(y) / 100 - ask(x - 1) / 100);	
    		}
    	}
    }
	return 0;
}
