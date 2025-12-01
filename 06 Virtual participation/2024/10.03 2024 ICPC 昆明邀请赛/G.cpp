#include <bits/stdc++.h>
using namespace std;
int n,a[1000010];
void solve()
{
	cin>>n;
	if(n%4==0||n==1) 
	{
		cout<<"impossible\n";
		return ;
	}
	if(n==2) cout<<"1 0\n";
	else if(n==3) cout<<"1 0 2\n";
	else
	{
		for(int i=1;i<=n;i++) a[i]=i-1;
		swap(a[1],a[2]);
		for(int i=4;i<=n;i++)
		{
			if(i%4==0) swap(a[i],a[i+1]);
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
