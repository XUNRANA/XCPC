#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m1,m2;
int a[200010],b[200010];
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
int c(int a,int b)
{
	int res=1,res1=1;
	for(int i=1;i<=b;i++) res=res*(a-i+1)%P,res1=res1*i%P;
	res=res*ksm(res1,P-2)%P;
	return res;
}
void solve()
{
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) cin>>a[i];
	for(int i=1;i<=m2;i++) cin>>b[i];
	if(a[m1]!=b[1])
	{
		cout<<"0\n";
		return ;
	}
	else cout<<c(n-1,a[m1]-1)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
