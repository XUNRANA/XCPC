#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,a[100010],b[100010],c[100010],ans=0,mi=1;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  int mx=a[n];
  for(int i=n-1;i>=1;i--)
  {
    b[i]=mx;
    if(a[i]>mx) mx=a[i];
  }
  mx=a[1];
  for(int i=2;i<=n;i++)
  {
    c[i]=mx;
    if(a[i]>mx) mx=a[i];
  } 

  for(int i=2;i<=n-1;i++) ans=max(ans,(b[i]+c[i])/a[i]);
  cout<<ans;
}
