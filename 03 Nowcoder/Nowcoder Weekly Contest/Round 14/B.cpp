#include <bits/stdc++.h>
using namespace std;
int x,y,x5,x6,y5,y6;
void solve()
{
	x5=x6=y5=y6=0;
	cin>>x>>y;
	while(x%5==0) x/=5,x5++;
	while(x%6==0) x/=6,x6++;
	
	while(y%5==0) y/=5,y5++;
	while(y%6==0) y/=6,y6++;
 	
 	if(x6<y6||x5>y5||x!=y) cout<<"-1\n";
	else cout<<y5-x5+x6-y6<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
