#include <bits/stdc++.h>
using namespace std;
#define int long long
int p,q,k;
int ans;
unordered_map<int,int>mp;
vector<int>pr,prc;
void dfs(__int128 x,int i,int c)
{
    if(x<=q) 
    {
        ans++;
    }

    __int128 t=x*pr[i];
    if(c+1<=prc[i]&&t<=q) dfs(t,i,c+1);
    
    for(int j=i+1;j<pr.size();j++)
    {
        t=x*pr[j];
        if(t<=q)
        {
            dfs(t,j,1);
        }
    }
}
void solve()
{
    cin>>p>>q>>k;
    for(int i=2;i*i<=p;i++)
    {
        while(p%i==0)
        {
            mp[i]++;
            p/=i;
        }
    }
    if(p!=1) mp[p]++;

    for(int i=2;i*i<=k;i++)
    {
        while(k%i==0)
        {
            mp[i]+=100;
            k/=i;   
        }
    }
    if(k!=1) mp[k]+=100;

    for(auto i:mp) pr.push_back(i.first),prc.push_back(i.second);

    dfs(1,0,0);
    cout<<ans<<"\n";
   
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}