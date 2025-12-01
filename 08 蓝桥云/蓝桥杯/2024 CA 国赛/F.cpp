#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

int ksm(int a,int b)
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
    int x,y,n;
    cin>>x>>y>>n;
    if(y%x!=0)
    {
        cout<<"0\n";
        return ;
    }
    map<int,int>mx,my;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            x/=i;
            mx[i]++;
        }
    }
    if(x!=1) mx[x]++;


    for(int i=2;i*i<=y;i++)
    {
        while(y%i==0)
        {
            y/=i;
            my[i]++;
        }
    }
    if(y!=1) my[y]++;

    set<int>st;
    for(auto i:mx) st.insert(i.first);
    for(auto i:my) st.insert(i.first);

    int ans=1;
    for(auto i:st)
    {
        int mi=min(mx[i],my[i]);
        int mxx=max(mx[i],my[i]);
        int l=mxx-mi+1;
        if(l==1) continue;
        int res=ksm(l,n);
        res=(res-2*ksm(l-1,n)%P+P)%P;
        if(l>2) res=(res+ksm(l-2,n))%P;
        ans=ans*res%P;
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
    return 0;
}
