#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int h[100010];
int x[100010];
bool ck(int cnt)//轰炸cnt次 
{
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int d=(h[i]+cnt-1)/cnt;//每次至少伤害为d
        if(d>m) continue;
        int l=x[i]-(m-d);
        int r=x[i]+(m-d);
        mp[l]++;
        mp[r+1]--;
    }
    int p=0;
    for(auto &i:mp) 
    {
        i.second+=p;
        if(i.second>=k) return 1;
        p=i.second;
    }
    return 0;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>x[i];

    int l=1,r=1e18;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(ck(mid)) r=mid-1;
        else l=mid+1;
    }
    if(l==1e18+1) l=-1;
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
