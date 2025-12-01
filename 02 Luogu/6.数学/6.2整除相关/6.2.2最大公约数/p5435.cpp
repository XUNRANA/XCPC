#include <bits/stdc++.h>
using namespace std;
#define p 998244353
#define int long long
int a[5010],b[5010],n,num,ans;
int gcd(int a,int b)
{
	int az=__builtin_ctz(a),bz=__builtin_ctz(b);//获取二进制表示形式中末尾0的个数 
	int z=min(az,bz);
	int dif;
	b>>=bz;
	while(a)
	{
		a>>=az;
		dif=b-a;
		az=__builtin_ctz(dif);
		if(a<b) b=a;
		if(dif<0) a=-dif;
		else a=dif;
	}
	return b<<z;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		ans=0;
		num=i;
		for(int j=1;j<=n;j++)
		{
			ans+=num*gcd(a[i],b[j]);
			ans%=p;
			num=num*i%p;
		}
		cout<<ans<<"\n";
	}
}
