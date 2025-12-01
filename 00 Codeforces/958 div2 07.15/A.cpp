#include <bits/stdc++.h>
using namespace std;
int n,k,dp[1010]; 
void solve()
{
	cin>>n>>k;
	if(n==1) cout<<"0\n";
	else cout<<(n-1+k-2)/(k-1)<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
