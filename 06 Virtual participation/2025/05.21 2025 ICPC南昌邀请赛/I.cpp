#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int p[100010];
int ss[100010];
int jc[100010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=1e5;i++) jc[i]=jc[i-1]*i%P;
}
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
int inv(int x)
{
    return ksm(x,P-2);
}
int C(int a,int b)
{
    return jc[a]*inv(jc[b])%P*inv(jc[a-b])%P;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) p[i]=p[i-1]+(s[i]=='1');
    vector<int>idx;
    for(int i=1;i<=n;i++)
    if(s[i]=='1') idx.push_back(i);

    if(idx.size()<k) cout<<"0\n";
    else if(idx.size()==k) cout<<C(n,idx.size())<<"\n";
    else
    {
        int ans=0;
        int l=1;
        int pr=0;
        for(int i=k-1;i<idx.size();i++)
        {
            int r=idx[i];
            
            if(i+1<idx.size()) r=max(r,idx[i+1]-1);
            else r=n;

            ans+=C(r-l+1,k);
            ans%=P;


            if(l!=1)
            {
                ans-=C(pr-l+1,k-1);
                ans=(ans+P)%P;
            }

            l=idx[i-k+1]+1;
            pr=r;
        }
        cout<<ans<<"\n";
    }
}
signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
