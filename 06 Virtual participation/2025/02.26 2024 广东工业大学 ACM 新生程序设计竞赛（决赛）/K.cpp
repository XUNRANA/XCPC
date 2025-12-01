#include <bits/stdc++.h>
using namespace std;
int a1[100010];
int a2[100010];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a1[i]=a2[i]=0;
	for(int i=1;i<=m;i++)
	{
		int op,x;
		cin>>op>>x;
		if(op==1) a1[x]++;
		else a2[x]++;
	}
	int cnt1=0;
	int cnt2=0;
	int s1=0;
	int s2=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		s1+=cnt1;
		s2+=2*cnt2;
		ans+=s1;
		ans+=s2;
		
		ans+=a1[i];
		ans+=a2[i];
		if(a1[i]) cnt1+=a1[i];
		if(a2[i]) cnt2+=a2[i];
		cout<<ans<<" ";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
