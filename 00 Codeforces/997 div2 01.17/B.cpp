#include <bits/stdc++.h>
using namespace std;
int n,d[1010];
vector<int>g[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) d[i]=0,g[i].clear();
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=n;j++)
	{
		char ch;
		cin>>ch;
		if(i<j)
		{
			if(ch=='1')
			{
//				cout<<i<<" "<<j<<"\n";
				g[i].push_back(j);
				d[j]++;
			}
			else
			{
//				cout<<j<<" "<<i<<"\n";
				g[j].push_back(i);
				d[i]++;
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++) if(!d[i]) q.push(i);
//	vector<int>ans;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<u<<" ";
//		ans.push_back(u);
		for(auto v:g[u]) if(--d[v]==0) q.push(v);
	}
//	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
