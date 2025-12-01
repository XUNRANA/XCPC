#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
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
int a[200010];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int s=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		ans=(ans+a[i]*i%P-s%P+P)%P;
	}
	
	cout<<2*ans%P*ksm(n,P-2)%P<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

