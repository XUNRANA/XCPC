#include <bits/stdc++.h>
using namespace std;
#define int long long

int pb1[200010];
int pb0[200010];
int s1[200010];
int s0[200010];
void solve()
{
    int n;
    string a,b;
    cin>>n>>a>>b;
    a=" "+a;
    b=" "+b;
    vector<array<int,2>>idx;
    vector<int>id;

    for(int i=1;i<=n;i++)
    {
        pb1[i]=pb1[i-1]+(b[i]=='1');
        pb0[i]=pb0[i-1]+(b[i]=='0');
        idx.push_back({i-2*pb1[i],i});
        id.push_back(i-2*pb1[i]);
    }
    sort(idx.begin(),idx.end());
    sort(id.begin(),id.end());

    for(int i=1;i<=n;i++) s0[i]=s0[i-1]+pb0[idx[i-1][1]];
    
    s1[n+1]=0;
    for(int i=n;i>=1;i--) s1[i]=s1[i+1]+pb1[idx[i-1][1]];

    int c1=0,c0=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='1') c1++;
        else c0++;
        int x=c1-c0;
        int j=upper_bound(id.begin(),id.end(),x)-id.begin()+1;
        ans+=s1[j]+(n-j+1)*c1;
        ans+=s0[j-1]+(j-1)*c0;
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
}