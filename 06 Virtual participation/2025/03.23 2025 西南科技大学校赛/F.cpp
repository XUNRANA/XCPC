#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int w[30];
vector<int>g[30];
int ck(int x)
{
    int cnt=0;
    for(int i=20;i>=0;i--) if(x>>i&1) cnt++;
    return cnt;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<m;i++)
    {
        int c;
        cin>>c;
        while(c--)
        {
            char ch;
            cin>>ch;
            g[i].push_back(ch-'A');
        }
    }
    int rr=0;
    for(int i=0;i<(1<<m);i++)
    {
        if(ck(i)==k)
        {

            map<int,int>mp;
            for(int j=0;j<m;j++) 
            if(i>>j&1)
            {
                for(auto kk:g[j])
                {
                    mp[kk]++;
                }
            }
            int res=0;
            for(auto [x,y]:mp) if(y>=2) res+=w[x]*y;
            rr=max(rr,res);
        }
    }
    cout<<rr<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
