#include <iostream>
using namespace std;
long long n,k,a[100010],b[100010],c[100010],ans=1e18;
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=n;i++) cin>>b[i];
  for(int i=1;i<=n;i++) c[i]=a[i]+b[i];
  for(int i=1;i<=n;i++) a[i]+=a[i-1];
  for(int i=1;i<=n;i++) ans=min(ans,a[i]+(k-i)*c[i]);
  cout<<ans;
}
