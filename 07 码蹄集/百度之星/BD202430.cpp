#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n;
int a[300010],b[300010];
int l[300010],r[300010];
int getidx(int x)
{
    return lower_bound(b+1,b+n+1,x)-b;
}

int tr[300010];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    while(x<=3e5)
    {
        tr[x]=(tr[x]+v)%P;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res=(res+tr[x])%P;
        x-=lowbit(x);
    }
    return res;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        int idx=getidx(a[i]);
        l[i]=query(idx-1)+1;
        add(idx,l[i]);
    }
    for(int i=1;i<=n;i++) add(getidx(a[i]),P-l[i]);
 
    for(int i=n;i>=1;i--) 
    {
        int idx=getidx(a[i]);
        r[i]=query(idx-1)+1;
        add(idx,r[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        ans=(ans+1ll*l[i]*r[i])%P;
        // cout<<l[i]<<" "<<r[i]<<"\n";
    }
    cout<<ans<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
