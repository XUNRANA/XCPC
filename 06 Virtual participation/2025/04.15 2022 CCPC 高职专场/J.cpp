#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>p;
int f[1000010];
void init()
{
	for(int i=2;i<=1e6;i++)
	{
		if(!f[i])
		{
			p.push_back(i);	
			for(int j=i;j<=1e6;j+=i)
			{
				f[j]=1;
			}
		}
	}
}
//10 8

//18
//2*3*3

//2*5  2*2*2
//2 2
//2 5 
//3 3
void solve()
{
	int a,b;
	cin>>a>>b;
	int c=a+b;
	set<int>ca,cb;
	for(auto i:p)
	{
		if(a%i==0)
		{
			while(a%i==0) a/=i;
			ca.insert(i);
		}
		if(b%i==0)
		{
			while(b%i==0) b/=i;
			cb.insert(i);
		}
	}
	if(a!=1) ca.insert(a);
	if(b!=1) cb.insert(b);
	int ans=ca.size()*cb.size();
	for(auto i:p)
	{
		if(c%i==0)
		{
			if(!ca.count(i)&&!cb.count(i)) ans++;
			while(c%i==0) c/=i;
		}
	}
	if(c!=1) if(!ca.count(c)&&!cb.count(c)) ans++;
	
	cout<<ans<<"\n";
	
} 
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

