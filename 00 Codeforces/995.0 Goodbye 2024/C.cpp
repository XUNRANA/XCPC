#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> fx(int l,int r,int k)
{
    if(r-l+1<k) return {0,0};
    int m=l+r>>1;
    if((r-l+1)&1) 
    {
        auto x=fx(l,m-1,k);
        return {x.second*m+x.first+x.first+m,x.second*2+1};
    }
    else
    {
        auto x=fx(l,m,k);
        return {x.second*m+x.first+x.first,x.second*2};
    }
    return {0,0};
}
void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<fx(1,n,k).first<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
