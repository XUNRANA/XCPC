#include <bits/stdc++.h>
using namespace std;
#define int long long

int fa[10010];
int p[10010];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void solve()
{
	int n,k,q;
	cin>>n;
	for(int i=1;i<=10000;i++) fa[i]=i;
	set<int>st;
	while(n--)
	{
		cin>>k;
		for(int i=1;i<=k;i++) cin>>p[i],st.insert(p[i]);
		for(int i=2;i<=k;i++) merge(p[i],p[1]);
	}
	int cnt=0;
	for(int i=1;i<=st.size();i++) if(find(i)==i) cnt++;
	cout<<st.size()<<" "<<cnt<<"\n";
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)==find(y)) cout<<"Y\n";
		else cout<<"N\n";
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

