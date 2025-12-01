#include <bits/stdc++.h>
using namespace std;
int c[1010];
void solve()
{
	int n;
	scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		int a,b,d;
		scanf("%d-%d %d",&a,&b,&d);
		c[a]+=d;
		mx=max(mx,c[a]);
	}
	for(int i=1;i<=1000;i++) if(c[i]==mx)
	{
		cout<<i<<" "<<mx<<"\n";
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
