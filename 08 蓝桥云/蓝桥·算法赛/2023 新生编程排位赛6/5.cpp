#include <bits/stdc++.h>
using namespace std;
int n,s,ans,a[510][510];
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0,j=0;j<n;j++)
    {
      int s=0,s1=0;
      for(int k=0;k<n;k++) 
      {
        s+=a[(i+k)][(j+k)%n];
        s1+=a[(i-k+n)%n][(j-k+n)%n];
      }
      ans=max(ans,s);
      ans=max(ans,s1);
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
