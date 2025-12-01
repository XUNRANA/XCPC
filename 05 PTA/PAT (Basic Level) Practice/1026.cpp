#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a,b;
    cin>>a>>b;
    int t=(b-a+50)/100;
    printf("%02d:%02d:%02d",t/3600,t/60%60,t%60);

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

