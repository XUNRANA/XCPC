#include <bits/stdc++.h>
using namespace std;
int n,x,a;
void solve()
{
	set<int>ans;
	cin>>n>>x;
	a=n-x;
	for(int i=1;i*i<=a;i++) 
	{
		if(a%i==0) 
		{
			if(i%2==0&&i/2+1>=x&&i>=2) ans.insert(i/2+1);
			if((a/i)%2==0&&a/i/2+1>=x&&a/i>=2) ans.insert(a/i/2+1);
		}
	}
	a=n+x-2;
	for(int i=1;i*i<=a;i++) 
	{
		if(a%i==0) 
		{
			if(i%2==0&&i/2+1>=x&&i>=2) ans.insert(i/2+1);
			if((a/i)%2==0&&a/i/2+1>=x&&a/i>=2) ans.insert(a/i/2+1);
		}
	}
	cout<<ans.size()<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
