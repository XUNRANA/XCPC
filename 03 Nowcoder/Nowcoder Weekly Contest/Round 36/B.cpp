#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,s,a[110][110];
void solve()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],s+=a[i][j];
	if(s!=x) cout<<"wrong answer\n";
	else
	{
		set<int>s;
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=1;j<=m;j++) res^=a[i][j];
			s.insert(res);
		}
		for(int i=1;i<=m;i++)
		{
			int res=0;
			for(int j=1;j<=n;j++) res^=a[j][i];
			s.insert(res);
		}
		if(s.size()==1) cout<<"accepted\n";
		else cout<<"wrong answer\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

