#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 1000000007
int n,k,ans,a[200010],cnt,nex[30*200010][2],w[30*200010];
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

void insert(int x,int v)
{
	int now=0;
	for(int i=30;i>=0;i--)
	{
		int k=x>>i&1;
		if(!nex[now][k]) nex[now][k]=++cnt;
		now=nex[now][k];
		w[now]=(w[now]+v)%P;
	}
}

int query(int x)
{
	int res=0,now=0;
	for(int i=30;i>=0;i--)
	{
		int t=(x>>i&1)^(k>>i&1);
		if(k>>i&1) res=(res+w[nex[now][!t]])%P;
		if(!nex[now][t]) return res;
		now=nex[now][t];
	}
	return (res+w[now])%P;
}

void solve()
{
	cin>>n>>k;
	for(int i=0;i<=cnt;i++) nex[i][0]=nex[i][1]=w[i]=0;
	cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=n;//j==iÊ±ÓÐ1µÄ¹±Ï× 
	for(int i=2;i<=n;i++)
	{//j-i: 2^(i-j-1)=2^(i-1)/2^j
		insert(a[i-1],inv(ksm(2,i-1)));
		ans=(ans+query(a[i])*ksm(2,i-1)%P)%P;
	}
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
    while(T--) solve();
}

