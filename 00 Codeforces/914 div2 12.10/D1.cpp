#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],b[200010];
int st[19][200010];
int ask(int l,int r)
{
	int k=__lg(r-l+1);
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) 
	{
		if(b[i]<a[i])
		{
			cout<<"NO\n";
			return ;
		}
	}
	
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	
	for(int i=1;(1<<i)<=n;i++)
	for(int j=1;j+(1<<i)-1<=n;j++)
	st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&(a[j]!=b[i]||(j<i&&ask(j,i)>b[i]))) j++;
		if(j>n||(j>=i&&ask(i,j)>b[i]))
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
