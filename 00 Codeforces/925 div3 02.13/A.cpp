#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
void solve()
{
	cin>>n;
	n-=3;
	a=b=c=1;
	if(n>=25) c+=25,n-=25;
	else c+=n,n-=n;
	
	if(n>=25) b+=25,n-=25;
	else b+=n,n-=n;
	
	if(n>=25) a+=25,n-=25;
	else a+=n,n-=n;
	cout<<char('a'+a-1)<<char('a'+b-1)<<char('a'+c-1)<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
