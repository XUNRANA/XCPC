#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int n,t1,cp;
int f[1000010];
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	f[1]=1;
	for(int i=2;i<=1e6;i++) if(!f[i]) for(int j=2*i;j<=1e6;j+=i) f[j]=1;
	//f[i]=0表示i是质数 
	map<int,int>p,s;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>t1;
		if(!f[t1]) p[t1]++;
		else s[t1]++;
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--) solve();
}
