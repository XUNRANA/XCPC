#include <bits/stdc++.h>
using namespace std;
int n,t,f[200010],cnt;
void solve()
{
    cin>>n;
    cnt=0;
    while(n--)
    {
        cin>>t;
        if(!f[t]) cnt++;
    }
    if(cnt==0) cout<<"-1\n";
    else if(cnt&1) cout<<"0\n";
    else cout<<"1\n";
}
int main()
{
    for(int i=2;i<=2e5;i++)
    {
        if(!f[i])
        {
            for(int j=i+i;j<=2e5;j+=i) f[j]=1;
        }
    }
    f[1]=1;
    f[3]=1;
   // for(int i=2;i<=100;i++) cout<<i<<" "<<f[i]<<'\n';
    int T;
    cin>>T;
    while(T--) solve();
}