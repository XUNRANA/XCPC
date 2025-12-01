#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int f1=n*m/2;
	int f2=n*m-f1;
	int k1=(k+1)/2; 
	int k2=(k+1)-k1; 
	if(n==1&&m==1) cout<<k<<"\n";
	else cout<<min(f1*k1+f2*k2,f1*k2+f2*k1)<<"\n"; 
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
