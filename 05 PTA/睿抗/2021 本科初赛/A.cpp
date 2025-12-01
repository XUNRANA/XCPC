#include <bits/stdc++.h>
using namespace std;
int mp[10000];
int a[100];
void solve()
{
    int n,k,m,x;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                for(int l=k+1;l<=n;l++)
                    mp[a[i]+a[j]+a[k]+a[l]]=1;
    while(k--)
    {
        cin>>m;
        int f=1;
        while(m--)
        {
            cin>>x;
            if(!mp[4*x]) f=0;
        }
        if(f) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
