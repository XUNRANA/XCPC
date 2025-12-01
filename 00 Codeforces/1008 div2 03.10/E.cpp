#include <bits/stdc++.h>
using namespace std;
#define int long long
int c1=((1ll<<30)-1)/3;//奇数位
int c0=((1ll<<30)-1)/3*2;//偶数位

int query(int x)
{
    cout<<x<<"\n";
    cout.flush();
    cin>>x;
    return x;
}
void print(int x)
{
    for(int i=29;i>=0;i--) if(x>>i&1) cout<<"1";
    else cout<<"0";
    cout<<"\n";
}
void solve()
{
    int x=query(c1);//奇数位
    int y=query(c0);//偶数位
    cout<<"!\n";
    cout.flush();
    int m;
    cin>>m;
    int ans=0;
    int d1=x-2*c1;
    int d0=y-2*c0;
    vector<int>cnt(30,0);
    for(int i=29;i>=0;i--)
    if(i&1)
    {
        if(d1>>i&1) cnt[i]=1;
        else if(d1>>(i+1)&1) cnt[i]=2;
    }
    else
    {
        if(d0>>i&1) cnt[i]=1;
        else if(d0>>(i+1)&1) cnt[i]=2;
    }

    // for(int i=0;i<30;i++) cout<<i<<" "<<cnt[i]<<"\n";

    for(int i=29;i>=0;i--)
    {
        if(m>>i&1) ans+=2*(1<<i);
        else ans+=cnt[i]*(1<<i);
    }
    cout<<ans<<"\n";
}

signed main() 
{
    int x=15,y=20;
    // cout<<(x|c1)+(y|c1)<<"\n";
    // cout<<(x|c0)+(y|c0)<<"\n";
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

