#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,k,j,o,ans;
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
    cin>>n>>k;
    o=k/2;
    j=k-o;
    ans=(ans+ksm(o,n))%P;//È«ÎªÅ¼Êý
    int q=n/3,q1=n%3;
    
    ans=(ans+ksm(j,2*q)*ksm(o,q)%P*ksm(j,q1)%P)%P;//ÆæÆæÅ¼
    
    if(q1==0) ans=(ans+ksm(j,2*q)*ksm(o,q)%P)%P;
    else if(q1==1) ans=(ans+ksm(j,2*q)*ksm(o,q)%P*o%P)%P;//Å¼ÆæÆæ
    else ans=(ans+ksm(j,2*q)*ksm(o,q)%P*o%P*j%P)%P;
    
    if(q1==0) ans=(ans+ksm(j,2*q)*ksm(o,q)%P)%P;
    else if(q1==1) ans=(ans+ksm(j,2*q)*ksm(o,q)%P*j%P)%P;//ÆæÅ¼Ææ
    else ans=(ans+ksm(j,2*q)*ksm(o,q)%P*o%P*j%P)%P;
    
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

