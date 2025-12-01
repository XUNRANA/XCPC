#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,ans,u,tmp,v[100010],w[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) w[i]^=w[i-1];
	for(int i=1;i<=n;i++) cout<<w[i]<<" ";
	cout<<"\n";
	for(int i=1;i<n;i++) v[i]=1;
	v[n]=inf;
	ans=0;
	for(int i=1;i<=n;i++) if((w[i]|m)==m) ans+=v[i];
	cout<<ans-inf<<"\n";                    
	for(int i=0;i<=30;i++)
	{
		if(m>>i&1)
		{
			u=(m-(1<<i))|((1<<i)-1);
			tmp=0;
			for(int j=1;j<=n;j++)
			if((w[j]|u)==u) tmp+=v[j];
			ans=max(ans,tmp);
		}
	}
	tmp=inf;
	if(ans-tmp+1<0) cout<<"-1\n";
	else cout<<ans-tmp+1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
