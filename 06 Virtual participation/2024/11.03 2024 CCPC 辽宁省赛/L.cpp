#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
bool ck(__int128 x)
{
    __int128 sum=0;
    for(__int128 i=4;i<=x;)
    {
        sum+=x/i-x/(25*i);
        i*=100;
    }
    return x-sum>=k;
}

void solve()
{
    cin>>k;
    k+=1533;
    int l=1;
    int r=2e18;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(ck(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<"\n";
}
/*
5
2
3
4
114514
998244353
*/

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
