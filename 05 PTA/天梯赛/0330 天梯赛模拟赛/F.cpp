#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[1000010];
void solve() 
{
    int n,s;
    cin>>n>>s;
    int a=s/n;
    int b=s%n;
    //    n-s%n;   
    // 1 1 1 1 2 2 2 2
    for(int i=1;i<=n;i++) 
    {
        if((n-i+1)==b) 
        {
            ans[i]=(a+1)*n;
            for(int j=i-1;j>=1;j--) ans[j]=ans[j+1]-1;
            for(int j=i+1;j<=n;j++) ans[j]=ans[j-1]+1;
            for(int j=1;j<=n;j++) cout<<ans[j]<<" ";
            cout<<"\n";
            return ;
        }
    }
    // 1 2 3 4 5 6 7 8 9
    // 0 0 1 1 1 2 2 2 3
    int f=a*n;
    for(int i=1;i<=n;i++) cout<<f++<<" ";
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}