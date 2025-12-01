#include <bits/stdc++.h>
using namespace std;
int a[3][3];
int x,y;
int res[19]={10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
void solve()
{
	vector<int>f(10,0);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
			f[a[i][j]]=1;
			if(!a[i][j])
			{
				x=i;
				y=j;
			}
		}
	}
	for(int i=1;i<=9;i++) 
	if(!f[i])
	{
		a[x][y]=i;
	}
	
	int k=3;
	while(k--)
	{
		cin>>x>>y;
		cout<<a[x-1][y-1]<<"\n";
	}
	int c=0;
	cin>>c;
	map<int,vector<int>>mp;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mp[i+1].push_back(a[i][j]);
		}
	}
	
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			mp[j+4].push_back(a[i][j]);
		}
	}	
	mp[7].push_back(a[0][0]);
	mp[7].push_back(a[1][1]);
	mp[7].push_back(a[2][2]);	
	mp[8].push_back(a[0][2]);
	mp[8].push_back(a[1][1]);
	mp[8].push_back(a[2][0]);	
	int ans=0;
	for(auto i:mp[c]) ans+=i;
	cout<<res[ans-6]<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

