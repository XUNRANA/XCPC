#include <bits/stdc++.h>
using namespace std;
#define MAXN 20005
int N;
char tet[MAXN][15];
int sc[MAXN],cur[MAXN];
long long P1=17,P2=37;
long long MOD1=10000000007,MOD2=10000000000009;
inline void getHash(long long &h1,long long &h2,int a[]) 
{
    h1=0;
	h2=0;
    for(int i=1;i<=N;++i) 
	{
		h1=(h1*P1+a[i])%MOD1;
        h2=(h2*P2+a[i])%MOD2;
    }
}
map<pair<long long,long long>,long long>s;
void solve() 
{
	cin>>N;
    for(int i=1;i<=N;++i) cin>>tet[i]>>sc[i];
    s.clear();
    long long ans1,ans2; 
	getHash(ans1,ans2,sc);
    long long t1,t2;
    for(char a='A';a<='D';++a)
        for(char b='A';b<='D';++b)
            for(char c='A';c<='D';++c)
                for(char d='A';d<='D';++d)
                    for(char e='A';e<='D';++e) {

                        for(int i=1;i<=N;++i) 
						{
                            cur[i] = 0;
                            if(tet[i][0]==a) cur[i] += 10;
                            if(tet[i][1]==b) cur[i] += 10;
                            if(tet[i][2]==c) cur[i] += 10;
                            if(tet[i][3]==d) cur[i] += 10;
                            if(tet[i][4]==e) cur[i] += 10;
                        }

                        getHash(t1,t2,cur); 
						s[make_pair(t1,t2)]++;
                    }

    long long ans = 0;
    for(char a='A';a<='D';++a)
        for(char b='A';b<='D';++b)
            for(char c='A';c<='D';++c)
                for(char d='A';d<='D';++d)
                    for(char e='A';e<='D';++e) {

                        for(int i=1;i<=N;++i) 
						{
                            cur[i] = 0;
                            if(tet[i][5]==a) cur[i] += 10;
                            if(tet[i][6]==b) cur[i] += 10;
                            if(tet[i][7]==c) cur[i] += 10;
                            if(tet[i][8]==d) cur[i] += 10;
                            if(tet[i][9]==e) cur[i] += 10;
                        }
                        getHash(t1,t2,cur);
                        t1=((ans1-t1)%MOD1+MOD1)%MOD1;
                        t2=((ans2-t2)%MOD2+MOD2)%MOD2;
                        ans+=s[make_pair(t1,t2)];
                    }

    cout<<ans<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
	cin>>T;
    while(T--) solve();
}
