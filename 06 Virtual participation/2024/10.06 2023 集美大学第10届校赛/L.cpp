#include <bits/stdc++.h>
using namespace std;
struct node
{
	int i,j;
	vector<string>v;
}s[1010];
int n,m,fa[3010],sz[3010];
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=3000;i++) fa[i]=i;
	int k=n+1;
	map<string,int>mp;
	for(int i=1;i<=n;i++) 
	{
		s[i].i=i;
		string str;
		cin>>str;
		string t="";
		for(auto j:str)
		{
			if(j!='_') t+=tolower(j);
			else 
			{
				s[i].v.push_back(t);
				t="";
			}
		}
		s[i].v.push_back(t);
		cin>>str;
		if(!mp.count(str)) mp[str]=k++;
		s[i].j=mp[str];
	}

	map<string,int>idk;
	for(int i=1;i<=m;i++)
	{
		string k;
		cin>>k;
		idk[k]=2*n+i;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<s[i].i<<" "<<s[i].j<<"\n";
		merge(s[i].i,s[i].j);
		for(auto j:s[i].v) 
		{
			if(idk.count(j))
			{
//				cout<<s[i].i<<" "<<idk[j]<<"\n";
				merge(s[i].i,idk[j]);
			}
		}
//		cout<<j<<" ";
//		cout<<"\n";
	}
	map<int,int>cnt;
	for(int i=1;i<=n;i++) cnt[find(i)]++;
	
	for(int i=1;i<=n;i++) cout<<cnt[find(i)]-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
