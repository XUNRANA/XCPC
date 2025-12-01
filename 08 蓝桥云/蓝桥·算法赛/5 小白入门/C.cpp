#include <bits/stdc++.h>
using namespace std;
long long n,ans,t;
int main()
{
  map<long long,int>m;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>t;
    m[t*i]++;
  }
  for(auto [x,y]:m) 
  if(y>=2) ans+=y*(y-1)/2;
  cout<<ans;
}
