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
int inv(int x)
{
	return ksm(x,P-2);
}
int jc[500010];
int in[500010];
int a[500010];
int cnt[500010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=5e5;i++) jc[i]=jc[i-1]*i%P;
	in[500000]=inv(jc[500000]);
	for(int i=499999;i>=0;i--) in[i]=in[i+1]*(i+1)%P;
}
void solve()
{
	init();
	int n;
	cin>>n;
	int l=n-2;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	int ans=1;
	for(int i=1;i<=5e5;i++) ans=ans*inv(jc[cnt[i]])%P;
	int res=0;
	for(int i=1;i*i<=l;i++)
	{
		if(l%i==0)
		{
			int x=i;
			int y=l/i;
			if(x!=y)
			{
				if(cnt[x]&&cnt[y])
				{
					int tans=ans;
					tans=tans*jc[cnt[x]]%P;
					tans=tans*jc[cnt[y]]%P;
					cnt[x]--;
					cnt[y]--;
					tans=tans*in[cnt[x]]%P;
					tans=tans*in[cnt[y]]%P;
					//不能这么写，等价于a^b%P !!!!!!= (a%P)^b%P 
//					ans=ans*inv(jc[cnt[x]])%P;
//					ans=ans*inv(jc[cnt[y]])%P;
					
					res=(res+2*jc[l]%P*tans%P)%P;
					cnt[x]++;
					cnt[y]++;
				}
			}
			else if(cnt[x]>=2)
			{
				int tans=ans;
				tans=tans*jc[cnt[x]]%P;
				cnt[x]-=2;
				tans=tans*in[cnt[x]]%P;
//				ans=ans*inv(jc[cnt[x]])%P;
				res=(res+jc[l]*tans)%P;
				cnt[x]+=2;
			}
		}
	}
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
