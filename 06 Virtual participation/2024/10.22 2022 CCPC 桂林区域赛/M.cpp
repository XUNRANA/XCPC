#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[300010];
int tr[300010];
int n;
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void solve()
{
	int len;
	cin>>n>>len;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		add(p[i],1);
		res+=sum(n)-sum(p[i]);
	}
	cout<<res<<"\n";
	int sum=(n-1)*n/2;
	string s;
	cin>>s;
	int j=1;
	int f=1;
	for(auto i:s)
	{
		if(i=='S')
		{
			res-=p[j]-1;
			res+=n-p[j];
			if(f) j++;
			else j--;
			if(j==0) j=n;
			if(j==n+1) j=1;
		}
		else
		{
			res=sum-res;
			f^=1;
			if(f) j++;
			else j--;
			if(j==0) j=n;
			if(j==n+1) j=1;
		}
		cout<<res%10;
	}
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
