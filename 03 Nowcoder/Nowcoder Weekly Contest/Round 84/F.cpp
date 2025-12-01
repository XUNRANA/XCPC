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
int a[20];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans+=abs(a[i]-a[j]);
	cout<<ans*ksm(n,P-2)%P;
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

