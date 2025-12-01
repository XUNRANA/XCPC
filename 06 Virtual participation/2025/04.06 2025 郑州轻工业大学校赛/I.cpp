#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
int ksm(int a,int b,int P)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n,b;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        mp[x]=y;
    }
    cin>>b;
    int ans1=1;
    int ans2=1;
    for(auto [x,y]:mp) ans1=ans1*ksm(x,y,P)%P;
    for(auto [x,y]:mp) ans2=ans2*ksm(x,y,b)%b;
    cout<<(ans1-ans2+P)%P*ksm(b,P-2,P)%P<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
