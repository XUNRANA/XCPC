#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	if(n==1) 
    {
        cout<<"YES\n";
        cout<<2<<" "<<3<<"\n";
    }
	else if(n==2) cout<<"NO\n";
	else 
	{
		cout<<"YES\n";
		cout<<n-1<<" "<<n<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
