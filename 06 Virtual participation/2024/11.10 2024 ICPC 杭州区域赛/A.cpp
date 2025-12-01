#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c;
int fa[26];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
	fa[find(a)]=find(b);
}
/*
4
abab
cdcd
abce
abab
cdcd
abcd
abab
cdcd
abc
x
yz
def
*/
void solve()
{
	cin>>a>>b>>c;
	if(a.size()!=b.size()) cout<<"NO\n";
	else if(a.size()!=c.size()) cout<<"YES\n";
	else
	{
		for(int i=0;i<26;i++) fa[i]=i;
		int n=a.size();
		for(int i=0;i<n;i++) merge(a[i]-'a',b[i]-'a');
		
		int f=0;
		for(int i=0;i<n;i++)
		if(find(c[i]-'a')!=find(a[i]-'a')&&find(c[i]-'a')!=find(b[i]-'a'))
		{
			f=1;
			break;	
		}
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
