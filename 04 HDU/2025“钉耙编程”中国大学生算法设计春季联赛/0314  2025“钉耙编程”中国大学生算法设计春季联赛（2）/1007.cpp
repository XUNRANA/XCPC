#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
int n,m,k;
int enc(int a,int b,int c)
{
	return a*k*k+b*k+c;
}
char c[110][110];
int f[110][110][8010];
int tr[128][8010];
void solve()
{
	cin>>n>>m>>k;
	for(int sum=0;sum<k;sum++)
	{
		for(int mul=0;mul<k;mul++)
		{
			for(int cur=0;cur<k;cur++)
			{
				for(int ch='0';ch<='9';ch++)
				{
					tr[ch][enc(sum,mul,cur)]=enc(sum,mul,(cur*10+ch-'0')%k);
				}
				tr['+'][enc(sum,mul,cur)]=enc((sum+mul*cur)%k,1,0);
				tr['-'][enc(sum,mul,cur)]=enc((sum+mul*cur)%k,k-1,0);//-1影响正负、取模
				tr['*'][enc(sum,mul,cur)]=enc(sum,mul*cur%k,0);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[i][j];
	
	memset(f,0,sizeof(f));
	f[1][1][enc(0,1,(c[1][1]-'0')%k)]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int s=0;s<k*k*k;s++)
	{
		int val=f[i][j][s];
		if(i+1<=n)
		{
			char ch=c[i+1][j];
			int u=i+1,v=j,t=tr[ch][s];
			if(isdigit(c[i][j])||isdigit(ch))
			{
				f[u][v][t]=(f[u][v][t]+val)%P;
			}
		}
		if(j+1<=m)
		{
			char ch=c[i][j+1];
			int u=i,v=j+1,t=tr[ch][s];
			if(isdigit(c[i][j])||isdigit(ch))
			{
				f[u][v][t]=(f[u][v][t]+val)%P;
			}
		}
	}




	int ans=0;
	for(int sum=0;sum<k;sum++)
	{
		for(int mul=0;mul<k;mul++)
		{
			for(int cur=0;cur<k;cur++)
			{
				if((sum+mul*cur)%k==0) ans=(ans+f[n][m][enc(sum,mul,cur)])%P;
			}
		}
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

