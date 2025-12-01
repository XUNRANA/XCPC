#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	vector<int>c(n+1,0);
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int mx=0;
	for(int i=1;i<=n*m;i++)
	{
		int t=0;
		if(a[i]%m==0) t=a[i]/m;
		else t=a[i]/m+1;
		c[t]++;
		
		mx=max(mx,c[t]);
		
		int t1=min(k,i-mx);
		
		if(mx+t1>=m)
		{
			cout<<i<<"\n";
			break;
		}
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
