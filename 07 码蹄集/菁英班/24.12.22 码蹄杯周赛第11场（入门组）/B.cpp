#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	int i,j;
	if(n&1)
	{
		if(a[(n+1)/2]!=b[(n+1)/2])
		{
			cout<<"No\n";
			return ;
		}
		i=n/2;
		j=i+2;
	}
	else
	{
		i=n/2;
		j=i+1;
	}
	while(i>=1&&j<=n)
	{
		if(a[i]!=b[i]||a[j]!=b[j]) break;
		i--;
		j++;
	}
	
	for(int i1=1;i1<=i;i1++) 
	if(a[i1]!=b[j+i1-1]||b[i1]!=a[j+i1-1])
	{
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
	
//	1-i
//	     j-n;
	
	
	
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
