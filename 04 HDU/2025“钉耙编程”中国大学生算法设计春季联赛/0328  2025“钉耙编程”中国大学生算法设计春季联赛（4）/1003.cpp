#include <bits/stdc++.h>
using namespace std;
#define int long long
int k,b,c,v;
int gt(int x)
{
    if(x<b) return 0;
    return (x-b)/k+1;
}
int get(int l,int r)
{
    return gt(r)-gt(l-1);
}
void solve()
{
    cin>>k>>b>>c>>v;
    int res=0;
    int ans=0;
    for(int i=62;i>=0;i--)
    {
        if(c>>i&1)
        {
            if(!(v>>i&1)) ans+=1ll<<i;// 1 0
            else res+=get(ans+(1ll<<i),ans+2*(1ll<<i)-1);//1 1
        }
        else
        {
            if(v>>i&1)//0 1
            {
                int l=ans;
                int r=ans+(1ll<<i)-1;
                res+=get(l,r);
                ans+=1ll<<i;
            }
        }
    }
    if((ans^c)<=v&&(ans-b)>=0&&(ans-b)%k==0) res++;
    cout<<res<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}