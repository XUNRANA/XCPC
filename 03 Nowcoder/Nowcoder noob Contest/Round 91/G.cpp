#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200050
#define M 998244853
int n,k,q,a,b,p,d[N],fa[N][20],pw[N],h1[N],h2[N];
string s;
int fk(int x,int y)
{
	return ((h2[x]-h2[p]+M)+(h1[y]-h1[fa[p][0]]+M)*pw[N-d[p]*2])%M*pw[d[x]]%M;
}
int lca(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	for(int i=18;i>=0;i--) if(d[fa[y][i]]>=d[x]) y=fa[y][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--)
	if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*114514%M;//¼ÆËãpow 
	cin>>n>>s;
	s="&"+s;
	for(int i=1;i<=n;i++)
	{
		cin>>k;//¸¸½Úµã 
		fa[i][0]=k;d[i]=d[k]+1;
		for(int j=1;j<=18;j++) fa[i][j]=fa[fa[i][j-1]][j-1];//±¶Ôö 
		h1[i]=(h1[k]+pw[d[i]]*s[i])%M;//×ÔÏÂµ½ÉÏ 
		h2[i]=(h2[k]+pw[N-d[i]]*s[i])%M;//×ÔÉÏµ½ÏÂ 
	}
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		p=lca(a,b);
		cout<<(fk(a,b)==fk(b,a)?"YES\n":"NO\n");
	}
}