#include <bits/stdc++.h>
using namespace std;
int d[510][510];
int n,k;
char ch;
int is[510];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='M') is[i]=1;
		cin>>k;
		int f,dis;
		while(k--)
		{
			string s;
			cin>>s;
			for(int i=0;i<s.size();i++) if(s[i]==':')
			{
				f=stoi(s.substr(0,i));
				dis=stoi(s.substr(i+1));
			}
//			scanf("%d:%d",&f,&dis);
			d[i][f]=dis;
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int mx1=1e9,mx2=1e9;
	for(int i=1;i<=n;i++)
	{
//		cout<<is[i]<<"\n";
		int mx=0;
		for(int j=1;j<=n;j++) 
		if(is[j]!=is[i])
		{
			mx=max(mx,d[j][i]);
//			cout<<d[j][i]<<" ";
		}
		if(is[i]) mx1=min(mx1,mx);
		else mx2=min(mx2,mx);
//		cout<<"\n";
	}
	vector<int>a,b;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=n;j++) 
		if(is[j]!=is[i]) mx=max(mx,d[j][i]);
		
		if(is[i])
		{
			if(mx==mx1) a.push_back(i);
		}
		else 
		{
			if(mx==mx2) b.push_back(i);
		}
	}
	for(int i=0;i<b.size();i++)
	{
		if(i) cout<<" ";
		cout<<b[i];
	}
	cout<<"\n";
	
	for(int i=0;i<a.size();i++)
	{
		if(i) cout<<" ";
		cout<<a[i];
	}
	cout<<"\n";
	
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int T=1;
//	cin>>T;
	while(T--) solve();
}
