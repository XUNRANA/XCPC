#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long a,b,m,ans1;
	cin>>a>>b>>m;
	if(a>b) swap(a,b);
	ans1=(a+m)/a+(a+m+b-a)/b;
	cout<<ans1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
