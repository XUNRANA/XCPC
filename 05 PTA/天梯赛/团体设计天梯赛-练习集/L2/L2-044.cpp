#include <bits/stdc++.h>
using namespace std;
int n;
int g[510];
int d[510][510];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e9;
	for(int i=1;i<=n;i++) 
	{
		char ch;
		int k;
		cin>>ch>>k;
		if(ch=='M') g[i]=1;
		else g[i]=0;
	
		for(int j=1;j<=k;j++)
		{
			int id,di;
			string s;
			cin>>s;
			int c=s.find(':');
			id=stoi(s.substr(0,c));
			di=stoi(s.substr(c+1));
			d[i][id]=min(d[i][id],di);//并不是双向的 
		}
	}
	

	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) 
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	map<int,vector<int>>mp[2];
	int mx1=1e9,mx2=1e9;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=n;j++)
		if(g[j]!=g[i]) mx=max(mx,d[j][i]);//别人对你的好感度 
		
		if(g[i]) 
		{
			mp[1][mx].push_back(i);
			mx1=min(mx,mx1);
		}
		else 
		{
			mp[0][mx].push_back(i);
			mx2=min(mx,mx2);
		}
	}
	
	
	int f=0; 
	for(auto i:mp[0][mx2]) 
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
	}
	cout<<"\n";
	
	f=0; 
	for(auto i:mp[1][mx1]) 
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
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

