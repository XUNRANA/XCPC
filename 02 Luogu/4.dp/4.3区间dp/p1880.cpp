#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define N 220
int n,a[N],s[N],f[N][N],f1[N][N];
void solve()
{
	cin>>n;
	memset(f,inf,sizeof f);
	for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i]; 
	for(int i=1;i<=2*n;i++) s[i]=s[i-1]+a[i],f[i][i]=0;
	for(int len=2;len<=2*n;len++)//长度 
	{
		for(int l=1;l+len-1<=2*n;l++)//起点 
		{
			int r=l+len-1;//终点 
			for(int k=l;k<r;k++)//分割点 
			{
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
				f1[l][r]=max(f1[l][r],f1[l][k]+f1[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	int ans1=1e9;
	int ans2=0;
	for(int i=1;i<=n;i++) 
	{
		ans1=min(ans1,f[i][i+n-1]);
		ans2=max(ans2,f1[i][i+n-1]);
	}
	cout<<ans1<<"\n"<<ans2<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
