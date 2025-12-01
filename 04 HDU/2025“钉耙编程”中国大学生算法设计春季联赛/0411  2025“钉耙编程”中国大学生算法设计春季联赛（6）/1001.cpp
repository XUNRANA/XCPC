#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int a[4];
void solve()
{
    int k;
    cin>>k;
    int mx=0;
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<8;i++)
    {
        int s=0;
        for(int j=0;j<3;j++)
        if(i>>j&1) s+=a[j];
        
        if(s<k) mx=max(mx,s);
    }
    cout<<k-mx<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}