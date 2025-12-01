#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,a[100010],s;
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
int jc(int x)
{
    int res=1;
    for(int i=1;i<=x;i++) res*=i;
    return res;
}
int C(int a,int b)
{
    if(b==0||b==a) return 1;
    if(b>a) return 0;
    int res=ksm(jc(b),P-2);
    while(b--)
    {
        res=res*a%P;
        a--;
    }
    return res;
// 	int res=1;
// 	for(int i=0;i<b;i++)
// 	{
// 		res=res*(a-i)%P;
// 		res=res*ksm(i+1,P-2)%P;
// 	} 
// 	return res; 
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i],s%=P;
	
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
        if(a[i]>=3) ans+=C(a[i],3)*(s-a[i])%P;//三点共线
        ans%=P;
        if(a[i]>=4) ans+=C(a[i],4)%P;//四点共线
		ans%=P;
	}
	ans=(C(s,4)-ans+P)%P;//四个点=全选四点-共线
	for(int i=1;i<=n;i++)//三个点=一个点+二个点 
	{
		ans+=a[i]*C((s-a[i]+P)%P,2)%P;
		ans%=P;
	} 
	cout<<2*ans%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
