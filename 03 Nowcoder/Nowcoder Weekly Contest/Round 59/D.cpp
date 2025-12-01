#include <bits/stdc++.h>
using namespace std;
int s,n,k;
void solve()
{
	cin>>s>>n>>k;
	if(k==0)
	{
		if(s<n)
		{
			cout<<"NO\n";
			return ;
		}
		if(s%n==0)
		{
			cout<<"YES\n";
			for(int i=0;i<n;i++) cout<<s/n<<" ";
			cout<<"\n";
		}
		else
		{
			cout<<"YES\n";
			int t=s%n;
			for(int i=0;i<n;i++)
			{
				if(i<t) cout<<s/n+1<<" ";
				else cout<<s/n<<" ";
			}
			cout<<"\n";
		}
		return ;
	}
	//1-(k-1)
	int t=(1+k-1)*(k-1)/2;
	int cnt=k;
	if(cnt>n||t>s)
	{
		cout<<"NO\n";
		return ;
	}
	if(n-cnt==0)
	{
		if(t!=s)
		{
			cout<<"NO\n";
			return ;
		}
	}
	
	if(n-cnt==1)
	{
		int t1=s-t;
		if(t1==k) cout<<"NO\n";
		else 
		{
			cout<<"YES\n";
			for(int i=0;i<k;i++) cout<<i<<" ";
			cout<<t1<<"\n";
		}
	}
	else if(n-cnt>=1)
	{
		int t1=s-t;
		vector<int>res;
		for(int i=0;i<k;i++) res.push_back(i);
		if(t1==k)
		{
			res.push_back(1);
			res.push_back(k-1);
		}
		while(res.size()<n) res.push_back(0);
		cout<<"YES\n";
		for(auto i:res) cout<<i<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
