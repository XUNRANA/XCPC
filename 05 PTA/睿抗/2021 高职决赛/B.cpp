#include <bits/stdc++.h>
using namespace std;

int a[100010];
int ans[100010];
int b[110];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	for(int i=1;i<=n/m;i++)
	{
		for(int j=1;j<=m;j++) cin>>b[j];
		
		for(int j=1;j<=m;j++)
		{
			ans[a[(i-1)*m+j]]=b[m-j+1];
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(!ans[x]) cout<<"Wrong Number\n";
		else cout<<ans[x]<<"\n";
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
