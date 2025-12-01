#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010];
int t1[300010];
int t2[300010];

int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x,int tr[])
{
    while(i<=n)
    {
        tr[i]+=x;
        i+=lowbit(i);
    }
}
int query(int l,int r,int tr[])
{
    if(l>r) return 0;
    int res=0;
    while(r)
    {
        res+=tr[r];
        r-=lowbit(r);
    }
    l--;
    while(l)
    {
        res-=tr[l];
        l-=lowbit(l);
    }
    return res;
}
void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }

    int mi=n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        mi=min(mi,a[i]);
        if(query(1,a[i]-1,t1)&&query(1,a[i]-1,t1)==query(1,a[i]-1,t2)) 
        {
            ans++;
            // cout<<i<<"?\n";
        }
        add(a[i],1,t1);
        if(mi==a[i]) add(a[i],1,t2);
    }

    mi=n;
    for(int i=1;i<=n;i++)
    {
        mi=min(mi,a[i]);
        add(a[i],-1,t1);
        if(mi==a[i]) add(a[i],-1,t2);
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

