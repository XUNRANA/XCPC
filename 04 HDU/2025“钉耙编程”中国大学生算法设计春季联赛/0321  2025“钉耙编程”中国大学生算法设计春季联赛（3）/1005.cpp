#include <bits/stdc++.h>
using namespace std;
int n,x,a[300010];
int fa[300010];
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
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		if((i-x)>=1) merge(i-x,i);
		if((i+x)<=n) merge(i+x,i);
	}
	set<int>st;
	for(int i=1;i<=n;i++) st.insert(find(i));
	cout<<st.size()-1<<"\n";

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
