#include <bits/stdc++.h>
using namespace std;
int n,q,l,r,f,j,a[100010],b[150];
int main()
{
  cin>>n>>q;
  for(int i=1;i<=n;i++) cin>>a[i];
  while(q--)
  {
    cin>>l>>r;
    if(r-l>100) cout<<"YES\n";
    else
    {
      j=1;
      f=0;
      for(int i=l;i<=r;i++) b[j++]=a[i];
      sort(b+1,b+j);
      for(int i=2;i<j;i++) 
      if(b[i]-b[i-1]<=365)
      {
        f=1;
        break;
      }
      if(f==1) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
}
