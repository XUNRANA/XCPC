#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y,n,m;
	cin>>n>>m>>x>>y;
	cout<<max({n-x+m-y,n-x+y-1,x-1+y-1,m-y+x-1})<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
