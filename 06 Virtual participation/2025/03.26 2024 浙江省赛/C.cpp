#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int k;
    cin>>k;
    cout<<k+2+k+2<<" "<<(k+1)*(k+2)<<" "<<"2\n";
    for(int i=1;i<=k+2;i++) cout<<"1 2 ";
    cout<<"\n";
    for(int i=1;i<=2*k+4;i++)
    {
        for(int j=1;j<i;j++) 
        {
            if(i%2==0&&j==i-1) continue;
            if((i&1)!=(j&1)) cout<<i<<" "<<j<<"\n";
        }
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
