#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define P 1000000007
long long n,k,a[N],f[N][N],ans;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
 	sort(a+1,a+1+n);
 	for(int i=1;i<=n;i++) f[i][1]=1;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<i;j++)
 		{
 			for(int k=2;k<=n-k;k++)
 			if(a[i]%a[j]==0)
 			{
 				f[i][k]=(f[i][k]+f[j][k-1])%P;
			}
		}
		ans=(ans+f[i][n-k])%P;
	}
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
