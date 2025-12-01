#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[100][100];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(a[i][j]=='1')
            {
                int f=1,ans=0;
                for(int i1=i;i1>=1;i1--) if(a[i1][j]=='0') f=0;
                ans|=f;
                f=1;
                for(int j1=j;j1>=1;j1--) if(a[i][j1]=='0') f=0;
                ans|=f;
                if(!ans)
                {
                    cout<<"NO\n";
                    return ;
                }
            }
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
