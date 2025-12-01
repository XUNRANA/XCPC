#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
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
int k,p;
int a[20];
string s;
void solve()
{
    cin>>k>>p>>s;
    p=p*inv(100)%P;
    s=" "+s;
    for(int i=1;i<=18;i++) cin>>a[i];
    for(int i=1;i<=18;i++) 
    {
        if(s[i]=='1') k+=5;
        if(k>=69)
        {
            k-=69;
            p=p*(a[i]+100)%P;
            p=p*inv(100)%P;
        }
    }
    cout<<p<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
