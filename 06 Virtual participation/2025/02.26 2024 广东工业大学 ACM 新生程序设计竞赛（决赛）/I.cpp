#include <bits/stdc++.h>
using namespace std;
int fa[100010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		merge(x,i);
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
