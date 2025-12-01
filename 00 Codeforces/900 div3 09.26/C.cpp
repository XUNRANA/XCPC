#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long n,k,x;
	cin>>n>>k>>x;
	if((2*n+1-k)*k/2<x||(1+k)*k/2>x) cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
