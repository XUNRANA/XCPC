#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,i;
}c[1000010];
int fa[1000010];
bool cmp(node c1,node c2)
{
	if(c1.a==c2.a) return c1.b<c2.b;
	return c1.a<c2.a;
}
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
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		cin>>c[i].a>>c[i].b;
		c[i].i=i;
		c[i].a-=i;
		c[i].b-=i;
	}
	sort(c+1,c+1+n,cmp);
	int mxi=1;
	for(int i=2;i<=n;i++)
	{
		if(c[i].a==c[i-1].a) 
		{
			merge(c[i].i,c[i-1].i);
			if(c[i].b>c[mxi].b) mxi=i;
			continue;
		}
		else if(c[i].b<=c[mxi].b)
		{
			merge(c[i].i,c[mxi].i);
		}
		else if(c[i].b>c[mxi].b) 
		{
			mxi=i;
		}
	}
	for(int i=1;i<=n;i++) swap(c[i].a,c[i].b);
	sort(c+1,c+1+n,cmp);
	mxi=1;
	for(int i=2;i<=n;i++)
	{
		if(c[i].a==c[i-1].a) 
		{
			merge(c[i].i,c[i-1].i);
			if(c[i].b>c[mxi].b) mxi=i;
			continue;
		}
		else if(c[i].b<=c[mxi].b)
		{
			merge(c[i].i,c[mxi].i);
		}
		else if(c[i].b>c[mxi].b) 
		{
			mxi=i;
		}
	}
	set<int>st;
	for(int i=1;i<=n;i++) st.insert(find(i));
	cout<<st.size()<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
