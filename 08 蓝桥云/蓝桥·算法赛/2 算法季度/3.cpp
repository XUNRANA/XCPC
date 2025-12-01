#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node
{
  int x,y;
}a[100010];
int n,k,s[100010],mi,ans;
bool cmp(node a,node b)
{
  return a.x<b.x;
}
void solve()
{
  ans=mi=1e18;
  cin>>k>>n;
  for(int i=1;i<=k;i++) cin>>a[i].x>>a[i].y;
  sort(a+1,a+1+k-1,cmp);
  for(int i=1;i<=k;i++) s[i]=s[i-1]+a[i].x,mi=min(mi,a[i].y);
  for(int i=1;i<=k-1;i++)
  {
    int p=upper_bound(a+1,a+1+k-1,node{a[i].y,0},cmp)-a-1;
    if(p>=n) 
    {
      ans=min(ans,s[n]);
      continue;
    }
    if(p>=i) ans=min(ans,s[p]+(n-p)*a[i].y);
    else ans=min(ans,s[p]+(n-p-1)*a[i].y+a[i].x);
  }
  if(n>=k) ans=min(ans,s[k]+(n-k)*mi);
  cout<<ans<<"\n";
}
signed main()
{
  int t;
  cin>>t;
  while(t--) solve();
}
