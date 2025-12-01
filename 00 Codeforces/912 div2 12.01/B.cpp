#include <bits/stdc++.h>
using namespace std;
int n,a[1010],m[1010][1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=(1<<30)-1;
		for(int j=1;j<=n;j++)
		{
			cin>>m[i][j];
			if(i!=j) a[i]&=m[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&((a[i]|a[j])!=m[i][j]))
			{
				cout<<"NO\n";
				return ;
			} 
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
