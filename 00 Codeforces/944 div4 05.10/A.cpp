#include <bits/stdc++.h>
using namespace std;
int x,ans,y;
void solve()
{
	cin>>x>>y;
	if(x>y) swap(x,y);
	cout<<x<<" "<<y<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
