#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define N 200010
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
int jc[N];
void init()
{
    jc[0]=1;
    for(int i=1;i<=2e5;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
    return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
int sz[N],s0[N],s1[N],dp[N];
vector<int>g[N];
void pre(int u)
{
    sz[u]=1;//子树数量
    s0[u]=s1[u]=0;//儿子子树为奇数、偶数的数量
    for(auto v:g[u])
    {
        pre(v);
        sz[u]+=sz[v];
        if(sz[v]&1) s1[u]++;
        else s0[u]++;
    }
}
void cal(int u)
{
    dp[u]=1;
    for(auto v:g[u])
    {
        cal(v);
        dp[u]=dp[u]*dp[v]%P;
    }
    dp[u]=dp[u]*ksm(2,s0[u])%P;
    dp[u]=dp[u]*((C(s1[u],s1[u]/2)+((s1[u]&1)==0)*C(s1[u],s1[u]/2-1))%P)%P;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        g[f].push_back(i);
    }
    pre(1);
    cal(1);
    cout<<ksm(2*dp[1]%P,k)<<"\n";
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
