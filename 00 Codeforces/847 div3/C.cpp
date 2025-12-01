#include <bits/stdc++.h>
using namespace std;
#define int long long

int b[110][110];
int a[110];
void solve()
{
    int l=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-1;j++) cin>>b[i][j];
    }

    for(int j=1;j<=n-1;j++)
    {
        for(int i=1;i<=n;i++) a[i]=b[i][j];
        sort(a+1,a+n+1);
        
        if(j==1)
        {
            if(a[1]==a[2]) 
            {
                cout<<a[1]<<" "<<a[n]<<" ";
                l=a[n];
            }
            else 
            {
                cout<<a[n]<<" "<<a[1]<<" ";
                l=a[1];
            }   
        }
        else 
        {
            if(a[1]==l) 
            {
                cout<<a[n]<<" ";
                l=a[n];
            }
            else
            {
                cout<<a[1]<<" ";
                l=a[1];
            }
        }
    }
    cout<<"\n";
    // 4 2 1 3
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