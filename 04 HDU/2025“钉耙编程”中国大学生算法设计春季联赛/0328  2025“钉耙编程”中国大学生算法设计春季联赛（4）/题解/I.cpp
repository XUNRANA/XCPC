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

const int N = 17;
int n, q;
int s[6], h[6][N];
int p[N];
unordered_map<int, int> Ans;

int cnt[6];
int bit[6][1 << 5];

int len[N];
int pos[N][5];
int ans[1 << N];
void prework() {
    memset(ans,0,sizeof ans);
    memset(len,0,sizeof len);
    memset(ans,0,sizeof ans);
    memset(cnt,0,sizeof cnt);
    memset(p,0,sizeof p);
    memset(h,0,sizeof h);
    memset(s,0,sizeof s);

    Ans.clear();

	rep(i, 0, (1 << 5) - 1) {
		int o = __builtin_popcount(i);
	 	bit[o][++ cnt[o]] = i;
	}
}



int calc(int a, int b, int c, int d, int e) {
	if((p[a] | p[b] | p[c] | p[d] | p[e]) != (1 << 5) - 1) return 0;
	
	rep(i, 0, 31) ans[i] = 0;

	rep(i, 1, len[a]) ans[1 << pos[a][i]] ++;
	rep(i, 1, cnt[1]) {
		int s = bit[1][i];
		if(!ans[s]) continue;
		rep(j, 1, len[b]) {
			int t = pos[b][j];
			if(!(s >> t & 1)) ans[s | (1 << t)] += ans[s];
		}
	}
	
	rep(i, 1, cnt[2]) {
		int s = bit[2][i];
		if(!ans[s]) continue;
		rep(j, 1, len[c]) {
			int t = pos[c][j];
			if(!(s >> t & 1)) ans[s | (1 << t)] += ans[s];
		}
	}
	
	rep(i, 1, cnt[3]) {
		int s = bit[3][i];
		if(!ans[s]) continue;
		rep(j, 1, len[d]) {
			int t = pos[d][j];
			if(!(s >> t & 1)) ans[s | (1 << t)] += ans[s];
		}
	}
	
	rep(i, 1, cnt[4]) {
		int s = bit[4][i];
		if(!ans[s]) continue;
		rep(j, 1, len[e]) {
			int t = pos[e][j];
			if(!(s >> t & 1)) ans[s | (1 << t)] += ans[s];
		}
	}
	
	return ans[31];
}

int main() {
    int TT=read();
    while(TT--) {
        prework();
        n = read(), q = read();
        rep(i, 1, 5) {
            s[i] = read();
            rep(j, 1, s[i]) h[i][j] = read();
        }
        
        rep(i, 1, n) rep(j, 0, 4) {
            int o = read();
            p[i] |= 1 << j;
            if(o) pos[i][++ len[i]] = j;
        }
        
        rep(a, 1, s[1])
        rep(b, 1, s[2]) if(h[1][a] != h[2][b])
        rep(c, 1, s[3]) if(h[1][a] != h[3][c] && h[2][b] != h[3][c])
        rep(d, 1, s[4]) if(h[1][a] != h[4][d] && h[2][b] != h[4][d] && h[3][c] != h[4][d])
        rep(e, 1, s[5]) if(h[1][a] != h[5][e] && h[2][b] != h[5][e] && h[3][c] != h[5][e] && h[4][d] != h[5][e]) {
            int A = h[1][a];
            int B = h[2][b];
            int C = h[3][c];
            int D = h[4][d];
            int E = h[5][e];
            int cur = calc(A, B, C, D, E);
            if(cur) Ans[(1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << E)] += cur;		
        }
        
        vector<pair<int, int>> aAns;
        for(auto o : Ans) aAns.push_back(o);
        
        while(q --) {
            int c = read(), cur = 0;
            while(c --) {
                int o = read();
                cur |= 1 << o;
            }
            int sum = 0;
            for(auto o : aAns) if(!(o.first & cur)) sum += o.second;
            printf("%d\n", sum);
        }
    }
	return 0;
}
