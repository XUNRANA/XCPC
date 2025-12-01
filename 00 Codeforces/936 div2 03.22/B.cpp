#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s,mx,s1,a[200010];
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
void solve()
{
	cin>>n>>k;
	s=mx=s1=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s1+=a[i];
		s+=a[i];
		mx=max(s,mx);
		if(s<0) s=0;
	}
	//cout<<s1<<" "<<mx<<" "<<k<<"\n";
	cout<<((s1-mx)%P+P+ksm(2,k)*(mx%P)%P+P)%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
