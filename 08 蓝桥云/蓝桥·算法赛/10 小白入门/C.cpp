#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,A,B,ans,t;
signed main()
{
  cin>>n>>A>>B>>ans;
  vector<int>z,f;
  for(int i=2;i<=n;i++)
  {
    cin>>t;
    if(t>=0) z.push_back(t);
    else f.push_back(t);
  }
  sort(z.begin(),z.end());
  sort(f.begin(),f.end());
  for(int i=0;i<f.size();i++)
  {
    if(B) ans-=f[i],B--;
    else ans+=f[i],A--;
  }
  for(int i=z.size()-1;i>=0;i--)
  {
    if(A) ans+=z[i],A--;
    else ans-=z[i],B--;
  }
  cout<<ans<<"\n";
}
