#include <bits/stdc++.h>
using namespace std;
int k;
vector<int>a;
int fx(int x)
{
	int r=0;
	while(x)
	{
		r+=x%10;
		x/=10;
	}
	return r;
}
int is(int x)
{
	if(x<=2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
vector<array<int,2>>ans;
void dfs(int x,int i,int m)
{
	if(i==k)
	{
		if(m==0)
		{
			x=x*100+99;
			int x1=fx(x);
			int y1=fx(x+1);
			if(is(__gcd(x1,y1)))
			{
				ans.push_back({y1,x});
				// cout<<y1<<" "<<x<<"\n";
			}
		}
		return ;
	}

	if(!i)
	{
		for(int j=1;j<=min(9,m);j++) 
		{
			dfs(x*10+j,i+1,m-j);
		}
	}
	else
	{
		for(int j=0;j<=min(9,m);j++)
		{
			dfs(x*10+j,i+1,m-j);
		}
	}
}
void solve()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"Case "<<i<<"\n";
		
		cin>>k>>m;
		ans.clear();
		if(m>18) 
		{
			k-=2;
			dfs(0,0,m-18);
			
		}
		sort(ans.begin(),ans.end());
		if(ans.size()) for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
		else cout<<"No Solution\n";
		
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
