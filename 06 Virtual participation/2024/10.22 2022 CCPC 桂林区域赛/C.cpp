#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n,m,a[100010];
int s;//总和 
int ps;//前缀和的和 
int ss;//后缀和的和
int len;//长度 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		ps+=a[i]*(n-i+1);
		ss+=a[i]*i;
		s%=P;
		ps%=P;
		ss%=P;
	}
	len=n;
	int ans=0;
	for(int i=1;i<m;i++)
	{
		//前后合成一个块 
		int sum=s*2%P;
		int sps=(ps+ss+s*len%P)%P;
		int sl=len*2%P;
		
		int res=(ksm(2,(m-i))*sps%P+(ksm(2,2*(m-i)-1)-ksm(2,(m-i)-1)+P)%P*sum%P*sl%P)%P;
		ans=max(ans,res);
		
		ps=(ps*2%P+s*len%P)%P;
		
		ss=(ss*2%P+s*len%P)%P;
		
		s=s*2%P;
		
		len=len*2%P;
	}
	
	int sps=(ps+ss+s*len%P)%P;//翻转 
	ans=max(ans,sps);
	
	ps=(ps*2%P+s*len%P)%P;//不翻转 
	ans=max(ans,ps);

	cout<<ans<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
