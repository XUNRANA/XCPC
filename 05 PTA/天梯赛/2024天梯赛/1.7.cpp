#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[1001];
int a,b;
int f(int x,int l)
{
	if(x<10) return l;
	else
	{
		int res=1;
		while(x)
		{
			res*=x%10;
			x/=10;
		}
		return f(res,l+1);
	}
}
signed main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		cout<<i<<" "<<f(i,0)<<"\n";
		g[f(i,0)].push_back(i);
	}
	
	for(int i=1000;i>=0;i--)
	if(g[i].size())
	{
		cout<<i<<"\n";
		int f=0;
		for(auto j:g[i]) 
		{
			if(f==1) cout<<" ";
			cout<<j;
			f=1;
		}
		return 0;
	}
}
