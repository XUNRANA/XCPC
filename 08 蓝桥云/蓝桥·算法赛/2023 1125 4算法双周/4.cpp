#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x,y,z,q,t;
	cin>>x>>y>>z;
	set<int>s;
	for(int i=0;i<40;i++)
	{
		for(int j=0;j<40;j++)
		{
			for(int k=0;k<40;k++)
			{
				if(pow(x,i)+pow(y,j)+pow(z,k)>1e13) break;
				s.insert(pow(x,i)+pow(y,j)+pow(z,k));
			}
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>t;	
		while(*s.upper_bound(t)==t+1) t++;
		cout<<t+1<<" "<<(*s.upper_bound(t))-(t+1)<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
