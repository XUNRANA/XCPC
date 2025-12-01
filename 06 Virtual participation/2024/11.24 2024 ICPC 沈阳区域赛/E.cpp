#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a0,a1,a2,a3;
int dp[1<<20];
int vt[1<<20];
vector<pair<int,int>>op;
int fx(int u,int k)
{
	int res=0;
	for(int i=0;i<16;i++) 
	if(u>>i&1) res|=(1<<(i^k));
	return res&((1<<15)-1);
}
void init()
{
	//a0
	op.push_back({1,a0});
	op.push_back({2,a0});
	op.push_back({4,a0});
	op.push_back({8,a0});
	
	//a1
	op.push_back({12,a1});
	op.push_back({3,a1});
	
	//a2
	op.push_back({10,a2});
	op.push_back({5,a2});
	
	//a3
	op.push_back({15,a3});
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

	for(int i=0;i<(1<<20);i++)
	{
		dp[i]=1e18;
		vt[i]=0;
	}
//	1000
	q.push({0,0});
	dp[0]=0;
	
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto i:op)
		{
			int k=i.first;
			int nu=fx(u,k);
			if(u==1)
			{
				cout<<nu<<" "<<k<<"\n";
				
			}
			if(dp[u]+i.second<dp[nu]) 
			{
				dp[nu]=dp[u]+i.second;
				q.push({dp[nu],nu});
			}			
			
		}
	}
//	for(int i=0;i<1000;i++) cout<<i<<" "<<dp[i]<<"\n";

}
void solve()
{
	cin>>n>>a0>>a1>>a2>>a3;
	init();
	while(n--)
	{
		cin>>m;
		int res=0;
		while(m--)
		{
			string s;
			cin>>s;
			int num;
			if(s=="00") num=0;
			else if(s=="01") num=4;
			else if(s=="10") num=8;
			else if(s=="11") num=12;
			cin>>s;
			if(s=="00") num+=0;
			else if(s=="01") num+=1;
			else if(s=="10") num+=2;
			else if(s=="11") num+=3;
			res|=1<<num;
//			cout<<num<<"\n";
		}
		cout<<res<<" !!\n";
		cout<<dp[res]<<"\n";
	}
}
/*
2 1000 100 10 1
4
10
00
01
00
00
10
00
01
1
11
11
*/
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
