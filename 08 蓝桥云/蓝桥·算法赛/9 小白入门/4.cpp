#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans;
vector<int>c(61);
signed main()
{
    cin>>n;
      for(int i=1;i<=n;i++)
      {
          cin>>t;
        for(int j=60;j>=0;j--) if(t>>j&1) ans+=c[j],c[j]++;
      }
      cout<<ans<<"\n"; 
}
