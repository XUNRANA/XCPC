#include <bits/stdc++.h>
using namespace std;
vector<int>g[100010];
int flag=0;
void dfs(int u)
{
	if(flag) cout<<" ";
	cout<<u;
	flag=1;
	
	for(auto v:g[u]) dfs(v);
}
void solve()
{
	int n,f,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f;
		g[f].push_back(i);
		if(!f) r=i;
	}
	if(n==1)
	{
		cout<<"0 yes\n1\n";
		return ;
	}
	set<int>st;
	for(int i=1;i<=n;i++) 
	{
		sort(g[i].begin(),g[i].end());
		st.insert(g[i].size());
	}
	int fl=0;
	if(st.size()!=2) fl=1;
	cout<<*st.rbegin()<<" "<<(fl?"no\n":"yes\n");
	dfs(r);
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

