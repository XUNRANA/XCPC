#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n;
	map<int,string>mp1;
	map<string,int>mp2;
	for(int i=1;i<=n;i++)
	{
		string s;
		int x,y;
		cin>>s>>x>>y;
		mp1[x]=s;
		mp2[s]=y;
	}
	cin>>m;
	while(m--)
	{
		int x;
		cin>>x;
		cout<<mp1[x]<<" "<<mp2[mp1[x]]<<"\n";
	}
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

