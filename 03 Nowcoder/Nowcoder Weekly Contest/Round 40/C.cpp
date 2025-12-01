#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,c[100010],a[100010],b[100010],t[100010];
void solve()
{
	cin>>n;
	map<int,int>ma,mb;
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++) 
	{
		
		c[t[i]]++;
		if(c[t[i]]==1) a[i]=t[i],ma[t[i]]=1;
		else b[i]=t[i],mb[t[i]]=1;
		if(c[t[i]]==3)
		{
			cout<<"-1\n";
			return ;
		} 
	}
	int j=1;
	for(int i=1;i<=n;i++) 
	if(!a[i])
	{
		while(ma.count(j)) j++;
		a[i]=j++;
	}
	j=1;
	for(int i=1;i<=n;i++) 
	if(!b[i])
	{
		while(mb.count(j)) j++;
		b[i]=j++;
	}
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
