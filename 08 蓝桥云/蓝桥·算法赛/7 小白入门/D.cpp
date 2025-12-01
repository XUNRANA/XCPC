#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans;
signed main()
{
	cin>>n;
  	map<int,int>m;
  	while(n--)
  	{
    	cin>>t;
    	for(int i=0;i<=30;i++) if((1<<i)-t>0) ans+=m[(1<<i)-t];
    	m[t]++;
  	}
  	cout<<ans<<"\n";
}
