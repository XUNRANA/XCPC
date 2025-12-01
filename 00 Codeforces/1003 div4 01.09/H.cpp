#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n;
int t0[200010];
int t00[200010];
int t1[200010];
int t11[200010];
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x,int t[])
{
    while(i<=n)
    {
        t[i]=(t[i]+x+P)%P;
        i+=lowbit(i);
    }
}
int query(int l,int r,int t[])
{
    int res=0;
    while(r)
    {
        res+=t[r];
        res%=P;
        r-=lowbit(r);
    }
    l--;
    while(l)
    {
        res-=t[l];
        res=(res+P)%P;
        l-=lowbit(l);
    }
    return res;
}
int p2[200010];
void init()
{
    p2[0]=1;
    for(int i=1;i<=2e5;i++) p2[i]=p2[i-1]*2%P;
}
string s;
int q,x;
void solve()
{
    string s;
    cin>>s;
    n=s.size();
    s=" "+s;
    int ans=(p2[n]-1+P)%P;
    for(int i=1;i<=n;i++) 
    if(s[i]=='1') 
    {
        add(i,p2[i-1],t1);
        add(i,p2[n-i],t11);
        ans+=query(1,n,t0)*p2[n-i]%P;
        ans%=P;
    }
    else 
    {
        add(i,p2[i-1],t0);
        add(i,p2[n-i],t00);
        ans+=query(1,n,t1)*p2[n-i]%P;
        ans%=P;
    }
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(s[x]=='1')
        {
            ans-=query(1,x-1,t0)*p2[n-x]%P;
            ans=(ans+P)%P;
            ans-=query(x+1,n,t00)*p2[x-1]%P;
            ans=(ans+P)%P;
            add(x,-p2[x-1],t1);
            add(x,-p2[n-x],t11);
            
            add(x,p2[x-1],t0);
            add(x,p2[n-x],t00);

            ans+=query(1,x-1,t1)*p2[n-x]%P;
            ans%=P;
            ans+=query(x+1,n,t11)*p2[x-1]%P;
            ans%=P;
        }
        else
        {
            ans-=query(1,x-1,t1)*p2[n-x]%P;
            ans=(ans+P)%P;
            ans-=query(x+1,n,t11)*p2[x-1]%P;
            ans=(ans+P)%P;
            add(x,-p2[x-1],t0);
            add(x,-p2[n-x],t00);

            add(x,p2[x-1],t1);
            add(x,p2[n-x],t11);

            ans+=query(1,x-1,t0)*p2[n-x]%P;
            ans%=P;
            ans+=query(x+1,n,t00)*p2[x-1]%P;
            ans%=P;
        }
        s[x]=(s[x]-'0')^1+'0';
        cout<<ans<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++) t0[i]=t1[i]=t00[i]=t11[i]=0;
}

signed main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
