#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int r[1010],c[1010];
char a[1010][1010];
void solve() 
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) r[i]=0;
    for(int i=1;i<=m;i++) c[i]=0;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            a[i][j]=ch;
            if(ch=='1') r[i]++,c[j]++,s++;        
        }
    }
    if(!s)
    {
        cout<<"YES\n";
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(n+m-2==s&&r[i]+c[j]==s&&a[i][j]=='0')
            {
                cout<<"YES\n";
                return ;
            }
        }
    }
    
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(r[i]+r[j]==s&&s==2*m)
    {
        cout<<"YES\n";
        return ;
    }
    
    for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++) if(c[i]+c[j]==s&&s==2*n)
    {
        cout<<"YES\n";
        return ;
    }
    cout<<"NO\n";
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
