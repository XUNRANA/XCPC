#include <bits/stdc++.h>
using namespace std;
int s,n,k,a[100];
void solve()
{
	s=0;
	cin>>n>>k;
	for(int i=1,j=1;i<=n;i++,j*=2)
	{
		a[i]=(n-j)/(2*j)+1;
		s+=a[i];
		if(s==n) break;
	}
	for(int i=1;i<=34;i++)
	{
		if(k>a[i]) k-=a[i];
		else
		{
			cout<<((1<<(i-1))+(k-1)*(1<<i))<<"\n";
			return ;
		}
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
