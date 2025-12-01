#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[15][10],sw[15];
void init()
{
	for(int i=0;i<10;i++) f[1][i]=1;
	for(int i=2;i<=10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(abs(j-k)>=2) f[i][j]+=f[i-1][k];
			}
		}
	}
}
int calc(int x)
{
	int ans=0,n=0;
	while(x)
	{
		sw[++n]=x%10;
		x/=10;
	}
	//不算最高位，都能取满 
	for(int i=1;i<n;i++) for(int j=1;j<10;j++) ans+=f[i][j];
	for(int i=1;i<sw[n];i++) ans+=f[n][i];//最高位小一点也能取满 
	for(int i=n-1;i>=1;i--)//枚举下一位 
	{
		for(int j=0;j<sw[i];j++) if(abs(sw[i+1]-j)>=2) ans+=f[i][j];
		if(abs(sw[i+1]-sw[i])<2) break;
	}
	return ans; 
}
void solve()
{
	int a,b;
	cin>>a>>b;
	cout<<calc(b+1)-calc(a)<<"\n"; 
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
