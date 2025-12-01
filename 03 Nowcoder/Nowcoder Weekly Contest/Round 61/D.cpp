#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve()
{
	cin>>n>>k;
	if(k>=n)
	{
		int n1=(n+1)/2;
		int n2=n/2;
		cout<<n1<<" "<<n1+k<<" "<<(n1-1)*n1/2+(n2+1)*n2/2<<"\n";
		return ;
	}
	int pos=(n+1)/2;
	int l=pos-k/2,r=pos+(k+1)/2;
	int ans=0;
	ans+=l*(l-1)/2;
	ans+=(n-r)*(n-r+1)/2;
	int n1=(k+2)/2,n2=(k+1)/2;
	ans+=(n1-1)*n1/2+(n2-1)*n2/2;
	cout<<l<<" "<<r<<" "<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
