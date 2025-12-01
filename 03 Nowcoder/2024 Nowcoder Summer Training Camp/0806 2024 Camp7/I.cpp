#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,k,h,ans;
int ck(int x)
{
    int t=(h-x+k-1)/k;
    return x+(t-1)*k>=m*t;
}
void solve()
{
    cin>>m>>k>>h;
    if(m==k) cout<<min(m,h)<<"\n";
    else if(h<=m) cout<<h<<"\n";
    else 
    {
        int l=1,r=h;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(ck(mid)) r=mid-1;
            else l=mid+1;
        }
        cout<<l<<"\n";
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
