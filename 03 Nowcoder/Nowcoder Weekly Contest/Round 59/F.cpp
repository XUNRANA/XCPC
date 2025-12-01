#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,a[2010],C[2010][2010],ans;
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
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j) C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
        }
    }
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]!=a[j])
			{//·¶µÂÃÉºãµÈÊ½
				ans+=ksm(2,j-i-1)*C[i-1+n-j][n-j]%P;
				ans%=P;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
