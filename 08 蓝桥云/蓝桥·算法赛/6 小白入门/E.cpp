#include <bits/stdc++.h>
using namespace std;
int n,cnt,a[200010],b[200010];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=n;i++) cin>>b[i];
  sort(a+1,a+1+n);
  sort(b+1,b+1+n);
  for(int i=1,j=1;i<=n;i++)
  {
    if(b[j]<2*a[i])
    {
      j++;
      cnt++;
    }
  }
  cout<<cnt;
}
