#include <bits/stdc++.h>
using namespace std;
#define P 998244353
#define N 1000010
int jc[N],inv[N],p[N],f[26][3],del,ans;
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
void init()
{
//	inv[ 1 ] = 1;
//  for( int i = 2; i <= n; i++ )
//	inv[ i ] = ( P - P / i ) * inv[ P % i ] % P;
	jc[0]=1;
	for(int i=1;i<N;i++) jc[i]=jc[i-1]*i%P;
	int infact=ksm(jc[N-1],P-2);
	for(int i=N-1;i>=1;i--) inv[i]=infact*jc[i-1]%P,infact=infact*i%P;
}
void solve()
{
	init();
	int n;
	string s;
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>p[i];
	del=1;
	for(int i=1;i<=n;i++)
	{
		int t=s[i]-'a';
		for(int j=0;j<26;j++)
		{
			if(j<t) f[t][1]=(f[t][1]+f[j][1]*inv[p[i]]%P)%P;//以t结尾，递增 
			if(j>t) f[t][2]=(f[t][2]+f[j][2]*inv[p[i]]%P)%P;//以t结尾，递减 
		}
		
		for(int j=0;j<26;j++)
		{
			if(j==t) continue;
			for(int k=0;k<3;k++) f[j][k]=f[j][k]*((1-inv[p[i]]+P)%P)%P;//更新非t 
		}
		for(int k=0;k<3;k++) f[t][k]=(f[t][k]+del*inv[p[i]]%P)%P;//前面都删除保留当前字符 
		del=del*((1-inv[p[i]]+P)%P)%P;
	}
	ans=0;
	for(int i=0;i<26;i++) ans=((ans+(f[i][1]+f[i][2])%P)%P-f[i][0]+P)%P;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
