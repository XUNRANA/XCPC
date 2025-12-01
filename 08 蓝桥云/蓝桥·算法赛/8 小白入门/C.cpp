#include <bits/stdc++.h>
using namespace std;
#define int long long
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%10;
		a=a*a%10;
		b>>=1;
	}
	return res;
}
void solve()
{
	int x,ans;
	string p;
	cin>>x>>p;
  	ans=ksm(x,p[0]-'0');
	for(int i=1;i<p.size();i++) ans=ksm(ans,10)*ksm(x,p[i]-'0')%10;
	cout<<ans<<"\n";
}
signed main()
{
	int t1=1;
	cin>>t1;
	while(t1--) solve();
} 
