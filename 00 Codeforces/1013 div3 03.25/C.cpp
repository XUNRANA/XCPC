#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    if(n%2==0) 
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++) 
    {
        if(2*i-1>n) cout<<2*i-1-n<<" ";
        else cout<<2*i-1<<" ";
    }
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
