#include <bits/stdc++.h>
using namespace std;
int b[100010];
void solve()
{
	int n,m,q,x;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++) cin>>b[i];
	
	b[0]=0;
	b[m+1]=n+1; 
	sort(b+1,b+1+m);
	
	while(q--) 
	{
		cin>>x;
		if(m==1)
		{
			if(x<b[1]) cout<<b[1]-1<<"\n";
			else cout<<n-b[1]<<"\n";
			continue;
		}
		
		int j=upper_bound(b,b+m+2,x)-b;
		if(j==m+1) cout<<n-b[m]<<"\n";
		else if(j==1) cout<<b[1]-1<<"\n";
		else cout<<(b[j]-b[j-1]-1+1)/2<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
