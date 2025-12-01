#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	cout<<(n+min(x,y)-1)/min(x,y)<<"\n";

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
