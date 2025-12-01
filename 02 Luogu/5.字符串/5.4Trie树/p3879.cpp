#include <bits/stdc++.h>
using namespace std;
int n,m,l,cnt;
string s;
int nex[500010][26];
bool is[500010][1010];

void insert(string s,int i)
{
	int now=0;
	for(auto i:s)
	{
		int k=i-'a';
		if(!nex[now][k]) nex[now][k]=++cnt;
		now=nex[now][k];
	}
	is[now][i]=1;//s在第i行出现 
}
void ck(string s)
{
	int now=0;
	for(auto i:s)
	{
		int k=i-'a';
		if(!nex[now][k]) 
		{
			cout<<"\n";
			return ;
		}
		now=nex[now][k];
	} 
	for(int i=1;i<=n;i++) if(is[now][i]) cout<<i<<" ";
	cout<<"\n";
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			cin>>s;
			insert(s,i);
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		ck(s);
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
