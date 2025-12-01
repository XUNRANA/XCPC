#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
long long s;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2) cout<<a[2]-a[1]<<"\n";
	else
	{
		s=0;
		for(int i=1;i<=n-2;i++)
		s+=a[i];
		
		s-=a[n-1];
		s+=a[n];
		cout<<s<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
