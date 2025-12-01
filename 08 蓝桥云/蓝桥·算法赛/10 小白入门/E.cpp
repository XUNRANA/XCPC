#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],ans;
int fx(int a,int b)
{
  int res=a+b;
  if(a%10==b%10) res-=a%10;
  a/=10;
  b/=10;
  if(a%10==b%10) res-=a%10;
  a/=10;
  b/=10;
  if(a%10==b%10) res-=a%10;
  a/=10;
  b/=10;
  if(a%10==b%10) res-=a%10;
  a/=10;
  b/=10;
  if(a%10==b%10) res-=a%10;
  a/=10;
  b/=10;
  if(a%10==b%10) res-=a%10;
  a/=10;
  b/=10;
  return res;
}
signed main()
{
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+1+n);
  vector<int>v;
  v.push_back(a[n]);
  for(int i=n-1;i>=1;i--) 
  {
    if(v.size()>1000) break;
    if(a[i]==a[i+1]) ans=max(a[i],ans);
    else v.push_back(a[i]);
  }
  for(int i=0;i<v.size();i++)
  {
    for(int j=i+1;j<v.size();j++)
    {
      //cout<<v[i]<<" "<<v[j]<<" "<<fx(v[i],v[j])<<"\n";
      ans=max(ans,fx(v[i],v[j]));
    }
  }
  cout<<ans<<"\n";
}
