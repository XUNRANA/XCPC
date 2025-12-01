#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,n,x,y,s,sum,ans=1e18,mi=1e18;
signed main()
{
	cin>>k>>n;
  	vector<pair<int,int>>v;
  	for(int i=1;i<=k-1;i++)
  	{
  		cin>>x>>y;
    	v.push_back({x,y});
  	}
  	cin>>x>>y;

  		for(int i=0;i<v.size();i++)
    	{
    		mi=min(mi,v[i].second);
      		s+=v[i].first;
      		cout<<s+(n-(i+1))*mi<<"\n";
      		ans=min(ans,s+(n-(i+1))*mi);
    	}
    	cout<<ans<<"\n";
}
