#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,b;
int c[250010];
void solve()
{
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n*m;i++)
    {
        int x;
        cin>>x;
        c[x]++;
    }

    
    priority_queue<array<int,2>,vector<array<int,2>>,less<array<int,2>> >pq;

    vector<int>d;
    for(int i=1;i<=n*m;i++) if(c[i]) d.push_back(c[i]);

    sort(d.begin(),d.end(),greater<int>());
   

    int ans=(n*m-c[0])*a;

    // cout<<ans<<"?\n";
    int cnt=0;
    for(auto i:d) 
    {
        // ans-i*a+c[0]*b<ans
        if(c[0]*b+cnt*i*b<i*a)
        {
            ans=ans-i*a+c[0]*b+cnt*i*b;
            cnt++;
        }
        else break;
        // cout<<i<<" ";
        // cout<<"\n";
    }
    cout<<ans<<"\n";

    for(int i=0;i<=n*m;i++) c[i]=0;

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}