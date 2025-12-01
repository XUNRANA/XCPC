#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
bool ck(int x)//k个最大为x
{
    if(k%x==0)
    {
        int cnt=k/x;
        return cnt-1+k<=m;
    }
    else
    {
        int cnt=k/x;
        return cnt+k<=m;
    }
}
void solve()
{
    cin>>n>>m>>k;
    if(k%n==0) k/=n;
    else k=k/n+1;
    int l=1,r=1e9;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(ck(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
