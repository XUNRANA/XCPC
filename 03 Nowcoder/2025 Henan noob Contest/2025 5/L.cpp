#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x1,y1,z,x2,y2;
    cin>>x1>>y1>>z>>x2>>y2;
    int t=(x1-1)/y2+1;
    int cnt=0;
    while(x2>0){
        cnt++;
        int k=(cnt*t-1)/3;
        x2-=k*y1+k*(k-1)/2*z;
    }
    cout<<cnt;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
