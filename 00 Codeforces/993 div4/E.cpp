#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int l,int r,int l1,int r1)
{
    if(r<l1||r1<l) return 0;
    if(l1>=l&&r1<=r) return r1-l1+1;
    if(l>=l1&&r<=r1) return r-l+1;
    if(l1>=l&&l1<=r) return r-l1+1;
    if(r1>=l&&r1<=r) return r1-l+1;
}
void solve()
{
    int k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    int t=1;
    vector<int>a;
    while(t<=1e9)
    {
        a.push_back(t);
        t*=k;
    }
    int ans=0;
    for(auto i:a)
    {
        int ll=(l2+i-1)/i;
        int rr=r2/i;
        ans+=fx(l1,r1,ll,rr);
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
