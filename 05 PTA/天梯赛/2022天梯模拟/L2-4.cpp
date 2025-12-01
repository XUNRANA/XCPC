#include <bits/stdc++.h>
using namespace std;

vector<int>g[100010];
int b[100010];
void solve()
{
	int n,m,k,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x;
			g[i].push_back(x);
		}
	}
	int now=1;
	while(m--)
	{
		int op;
		cin>>op;
		if(!op)
		{
			int j;
			cin>>j;
			now=g[now][j-1];
		}
		else if(op==1)
		{
			int j;
			cin>>j;
			b[j]=now;
			cout<<now<<"\n";
		}
		else
		{
			int j;
			cin>>j;
			now=b[j];
		}
	}
	cout<<now<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
