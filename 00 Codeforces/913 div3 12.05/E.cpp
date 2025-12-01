#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
void solve()
{
	ans=1;
    cin>>n;
    while(n)
    {
    	ans*=(n%10+1)*(n%10+2)/2;
		n/=10; 
	}
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}

