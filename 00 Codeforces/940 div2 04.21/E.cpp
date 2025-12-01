#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=1000000007;
const int N=1000010;
int f[N];
vector<int>minp,primes;
void sieve(int n)
{
	minp.assign(n+1,0);
	primes.clear(); 
	for(int i=2;i<=n;i++)
	{
		if(minp[i]==0)
		{
			minp[i]=i;
			primes.push_back(i);
		}
		for(auto p:primes)
		{
			if(i*p>n) break;
			minp[i*p]=p;
			if(p==minp[i]) break;
		}
	}
}
void init()
{
	sieve(N);
	for(auto p:primes)
	{
		for(int j=p;j<N;j+=p)
		{
			f[j]+=(p-1)*(j/p)%p;
			if(j+p<N) f[j+p]-=(p-1)*(j/p)%p;
		}
	}
	for(int j=4;j<N;j+=4)
	{
		f[j]+=2*(j/4)%4;
		if(j<N) f[j+4]-=2*(j/4)%4;
	}
	for(int i=1;i<N;i++) f[i]=(f[i]+f[i-1])%P;
	for(int i=1;i<N;i++) f[i]=(f[i]+f[i-1])%P;
}
void solve()
{
	int n;
	cin>>n;
	cout<<f[n]<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);	
	int T=1;
	cin>>T;
	while(T--) solve();
}
