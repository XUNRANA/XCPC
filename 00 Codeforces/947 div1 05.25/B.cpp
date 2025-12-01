#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int t=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]%a[1]!=0) 
		{
			if(!t) t=a[i];
			else if(a[i]%t!=0)
			{
				cout<<"No\n";
				return ;
			}
		}
	}
	cout<<"Yes\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
