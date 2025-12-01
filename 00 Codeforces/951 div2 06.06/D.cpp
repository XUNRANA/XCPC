#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define p1 1331
#define P 1000000007
int n,k,ans1,ans2;
int pre[N];
int suf[N];
int p[N];
string s;
void solve()
{
	cin>>n>>k>>s;
	s="$"+s;
	ans1=ans2=1;
	p[0]=1;
	pre[0]=1;
	suf[n+1]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*p1%P;
		pre[i]=(pre[i-1]*p1%P+s[i]-'0'+1)%P;
		suf[n-i+1]=(suf[n-i+1+1]*p1%P+s[n-i+1]-'0'+1)%P;
		int t=(i-1)/k;
		if(t&1)
		{

			ans1=(ans1*p1%P+2)%P;
			ans2=(ans2*p1%P+1)%P;
		}
		else
		{
			ans1=(ans1*p1%P+1)%P;
			ans2=(ans2*p1%P+2)%P;
		}
	}
	ans1=(ans1-1*p[n]%P+P)%P;
	ans2=(ans2-1*p[n]%P+P)%P;

	for(int i=1;i<=n;i++)
	{
		int t=(suf[1]-suf[i+1]*p[i]%P+P)%P;
		int t1=(pre[n]-pre[i]*p[n-i]%P+P)%P;
		//cout<<(t1*p[i]%P+t)%P<<"\n";
		if((t1*p[i]%P+t)%P==ans1||(t1*p[i]%P+t)%P==ans2)
		{
			cout<<i<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
