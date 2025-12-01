#include <bits/stdc++.h>
using namespace std;
#define int long long
int ck(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<"\n";
	int z;
	cin>>z;
	return z;
}

void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int>>ans;
	for(int i=2;i<=n;i++)
	{
		int a=1,b=i;
		while(1)
		{
			int t=ck(a,b);
			if(t==a)
			{
				ans.push_back({a,b});
				break;
			}
			a=t;
		}
	}
	cout<<"! ";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<" ";	 
}
signed main()
{
	int T=1;
	cin>>T;
	while(T--) solve();
}
