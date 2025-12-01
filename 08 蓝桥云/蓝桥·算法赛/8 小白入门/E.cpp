#include <bits/stdc++.h>
using namespace std;
int ans,n,a[110];
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n==2)
	{
		if(a[1]==a[2]) cout<<"1\n";
		else cout<<"0\n";
		return ;
	}
	if(a[1]==a[2]&&a[n]==a[n-1])
	{
		cout<<"0\n";
		return ;
	}
	if(a[2]==a[3]&&a[n-1]==a[n-2]) 
	{
		cout<<"1\n";
		return ;
	}
	else cout<<"2\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	cin>>t1;
	while(t1--) solve();
}
