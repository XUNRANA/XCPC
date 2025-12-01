#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,p,ans;
	cin>>n>>k>>p;
	if(k<0) k*=-1;
	ans=(k+p-1)/p;
	if(ans>n) ans=-1;
	cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
