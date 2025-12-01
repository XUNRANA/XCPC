#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x;
	cin>>x;
	if(x==1) 
	{
		cout<<"0\n";
		return ;
	}
	map<int,int>mp;
	for(int i=2;i*i<=x;i++)
	{
		while(x%i==0)
		{
			mp[i]++;
			x/=i;
		}
	}
	if(x!=1) mp[x]++;
	cout<<mp.size()<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

