#include <iostream>
using namespace std;
int n,a[100010];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  a[0]=a[n];
  a[n+1]=a[1];
  for(int i=1;i<=n;i++) cout<<a[i-1]+a[i+1]<<" ";
}
