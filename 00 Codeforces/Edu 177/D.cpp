#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
int n;
int dp[26][2];
int d[26][2];
int jc[500010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=5e5;i++) jc[i]=jc[i-1]*i%P;
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
int C(int a,int b)
{
    return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2);
}
void solve() 
{
    int s=0;
    vector<int>a;
    int inv=1;
    for(int i=0;i<26;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
        inv=inv*ksm(jc[x],P-2)%P;
        s+=x;
    }
    int l=(s+1)/2;//奇数位的个数
    int r=s/2;//偶数位的个数
    vector<int>dp(l+1,0);
    dp[0]=1;
    for(auto i:a)
    {
        if(!i) continue;
        for(int j=l;j>=i;j--) dp[j]=(dp[j]+dp[j-i])%P;
    }
    cout<<dp[l]*jc[l]%P*jc[r]%P*inv%P<<"\n";
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