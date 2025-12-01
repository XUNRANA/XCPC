#include <bits/stdc++.h>
using namespace std;
void solve()
{
	double a,b,k;
	cin>>a>>b>>k;
	double ans=0;

	ans+=500;
	b*=1.2;
	
	ans+=a+0.9*b;
	b*=1.2;
	
	ans+=a;
	b*=1.2;
	
	ans+=a+2*b;
	b*=1.2;
	
	ans+=a;
	ans+=5*b;
	b*=1.2;
	
	ans+=a;
	ans+=5*b;
	b*=1.2;
	
	ans+=a;
	ans+=5*b;
	b*=1.2;
	
	ans+=a;
	ans+=5*b;
	b*=1.2;
	
	if(ans>=k) cout<<"You have slain an enemy\n";
	else cout<<"You have been slain\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
