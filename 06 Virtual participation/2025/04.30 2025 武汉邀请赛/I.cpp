#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
void solve() 
{
    cin>>n>>k;
    int j1=k;
    vector<vector<int>>a(n+1,vector<int>(n+1,0));
    a[1][1]=j1--;
    for(int i=2;i<=n;i++) 
    {
        a[1][i]=j1--;
        if(a[1][i]<1)
        {
            cout<<"No\n";
            return ;
        }
    }

    int j=k+1;
    for(int i=2;i<=n;i++)
    {
        a[i][i]=j++;
        if(a[i][i]>n*n)
        {
            cout<<"No\n";
            return ;
        }
    }


    for(int i=1;i<=n;i++) 
    for(int k=1;k<=n;k++) 
    if(a[i][k]==0) 
    {
        if(j<=n*n) a[i][k]=j++;
        else a[i][k]=j1--;
    }

    cout<<"Yes\n";
    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";

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
