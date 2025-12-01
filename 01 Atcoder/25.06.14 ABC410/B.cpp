#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<int>c(m+1,0);
	for(int i=1;i<=m;i++) 
	{
		int x;
		cin>>x;
		if(x) 
		{
			c[x]++;
			cout<<x<<" ";
		}
		else 
		{
			int mi=m;
			for(int i=1;i<=n;i++) mi=min(mi,c[i]);
			for(int i=1;i<=n;i++) if(c[i]==mi)
			{
				c[i]++;
				cout<<i<<" ";
				break;
			}
		}
	}

} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
