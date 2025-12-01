#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ksm(int a,int b)
{
    if(b<0) return 0;//!!!!!
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int jc[1000010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=1e6;i++) jc[i]=jc[i-1]*i%P;
}
int C(int a,int b)
{
    if(b>a) return 0;//!!!!!!!
    return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
void solve() 
{
    init();
    int n,k;
    cin>>n>>k;
    if(!k)
    {
        cout<<ksm(3,n)<<"\n";
        return ;
    }
    int ans=0;
    for(int i=1;i<=k;i++)// k个进位分成：i个进位段
    {
        int ans1=C(k-1,i-1)*ksm(3,k-i)%P;//k-1个空隙选i-1个、分成i段

        int c1=C(n-k-1,i-2);//i-1块

        int c2=C(n-k-1,i-1);//i块

        int c3=C(n-k-1,i);//i+1块

        ans+=ans1*c2%P*ksm(3,n-k-i)%P;//i   可能i位无效
        ans%=P;
        ans+=ans1*c2%P*ksm(3,n-k-i+1)%P;//i  可能i-1位无效
        ans%=P;
        ans+=ans1*c1%P*ksm(3,n-k-i+1)%P;//i-1块 肯定i-1位无效
        ans%=P;
        ans+=ans1*c3%P*ksm(3,n-k-i)%P;//i+1  肯定i位无效
        ans%=P;
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
    return 0;
}