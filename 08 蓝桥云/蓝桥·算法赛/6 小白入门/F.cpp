#include <bits/stdc++.h>
using namespace std;
int t,k,m,l,r,mid;
int ck(int x)
{
  if(sqrt(x)+(int)(log(x)/log(k))>m) return 1;
  return 0;
}
int main()
{
  cin>>t;
  while(t--)
  {
    cin>>k>>m;
    l=1,r=1e9;
    while(l<r)
    {
     // cout<<l<<" "<<r<<"\n";
      mid=l+r>>1;
      if(ck(mid)) r=mid;
      else l=mid+1;
    }
    cout<<l<<"\n";
  }
  return 0;
}
