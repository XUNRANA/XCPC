#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
void solve()
{
	cin>>n>>a>>b>>c;
	int cnt=n/(a+b+c)*3;
	n%=(a+b+c);
	if(n==0) ;
	else if(n<=a) cnt++;
	else if(n<=a+b) cnt+=2;
	else cnt+=3;
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
