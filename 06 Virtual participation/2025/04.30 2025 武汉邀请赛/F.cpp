#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
void solve() 
{
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[y]+=x;
    }
    vector<int>a;
    for(auto i:mp) a.push_back(i.first);
    sort(a.begin(),a.end(),greater<int>());
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        if(mp[a[i]]==0) continue;
        if(mp[a[i]]%m==0)
        {
            ans+=mp[a[i]]/m%P*ksm(2,a[i])%P;
            ans%=P;
        }
        else
        {
            ans+=(mp[a[i]]+m-1)/m%P*ksm(2,a[i])%P;
            ans%=P;
            __int128 d=m-mp[a[i]]%m;
            for(int j=1;d&&d<=1e18&&a[i]-j>=0;j++)
            {
                d*=2;
                if(mp.count(a[i]-j))
                {
                    int mi=d;
                    if(mp[a[i]-j]<mi) mi=mp[a[i]-j];
                    mp[a[i]-j]-=mi;
                    d-=mi;
                }
            }
            if(d>1e18)
            {
                cout<<ans<<"\n";
                return ;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}