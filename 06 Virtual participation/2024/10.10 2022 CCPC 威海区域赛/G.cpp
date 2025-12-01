#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,n,k;
int p[2000010];
int l[100010],r[100010];
int ck(int i,int x)
{
	return __gcd((i*x)^x,x)==1;
}
int get(int x)
{
	if(x%k==0) return x/k*p[k];
	else return x/k*p[k]+p[x%k];
}
void solve()
{
	cin>>x>>n;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	if(x%2==0)
	{
		for(int i=1;i<=n;i++) cout<<"0\n";
		return ;
	}
	if(x==1)
	{
		for(int i=1;i<=n;i++) cout<<r[i]-l[i]+1<<"\n";
		return ;
	}
	k=log2(x)+1;
	k=1ll<<k;
	for(int i=1;i<=k;i++) p[i]=p[i-1]+ck(i,x);
	for(int i=1;i<=n;i++) cout<<get(r[i])-get(l[i]-1)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
