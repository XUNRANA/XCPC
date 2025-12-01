#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,c1,c2,ans,jc[100010],inv[100010];
string s;
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
	cin>>n>>s;
    for(auto i:s) 
    if(i=='(') c1++;
    else if(i==')') c2++;
    jc[0]=jc[1]=1;
    for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%P;
    inv[n]=ksm(jc[n],P-2);
    for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%P;//n-1 ?0
    if(n&1||max(c1,c2)>n/2) ans=0;
    else ans=jc[n-c1-c2]*inv[n/2-min(c1,c2)]%P*inv[n-c1-c2-n/2+min(c1,c2)]%P;
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
