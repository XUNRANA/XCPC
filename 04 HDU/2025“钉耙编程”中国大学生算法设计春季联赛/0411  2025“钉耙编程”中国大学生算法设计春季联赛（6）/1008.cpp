#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int a[200010];
int jc[200010];
void init()
{
    jc[0]=1;
    for(int i=1;i<=2e5;i++) jc[i]=jc[i-1]*i%P;
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
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans1=0;
    int ans2=0;
    int s=a[1];
    for(int i=2;i<=n;i++)
    {
        ans1=(ans1+s*a[i]%P)%P;
        s=(s+a[i])%P;
    }
    ans2=ksm(jc[n-1],2)*n%P*inv(ksm(2,n-1))%P;
    cout<<ans1<<" "<<ans2<<"\n";
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