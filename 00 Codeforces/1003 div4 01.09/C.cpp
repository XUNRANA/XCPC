#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=m;i++) cin>>b[i];
	
	int mi=b[1];
	for(int i=2;i<=m;i++) mi=min(mi,b[i]);
	
	b[1]=mi;
	
	int p=min(a[1],b[1]-a[1]);
	
	for(int i=2;i<=n;i++)
	{
		int t1=a[i];
		int t2=b[1]-a[i];
		if(t1<p&&t2<p) 
		{
			cout<<"NO\n";
			return ;
		}
		
		if(t1>=p&&t2>=p) p=min(t1,t2);
		else if(t1>=p) p=t1;
		else p=t2;
	}
	cout<<"YES\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
