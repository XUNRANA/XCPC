#include <bits/stdc++.h>
using namespace std;
const int N=1e8+5;
const int M=6e6+5;
int s[M],k;
bool f[N];
void init()
{
	for(int i=2;i<=N-5;i++)
	{
		if(!f[i]) s[k++]=i;
		for(int j=0;j<=k&&s[j]*i<=N-5;j++)
		{
			f[i*s[j]]=1;
			if(i%s[j]==0) break;
		}
	}
}
void solve()
{
	int x,y,l,r;
	cin>>x>>y;
	l=lower_bound(s,s+k,x)-s;
	r=upper_bound(s,s+k,y)-s;
	if(l==0) cout<<r-l<<" "<<max(0,r-l-2)<<"\n";
	else cout<<r-l<<" "<<0<<"\n";
	
}
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
