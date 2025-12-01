#include <bits/stdc++.h>
using namespace std;
#define P 998244353
int n,m,f[2][5001][2][2];
char s[5001];
int a[5001];
int main()
{
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	if(n==1||n==2) cout<<(1ll<<min(n,m))<<"\n";
	else 
	{
		f[0][0][a[1]][a[2]]=1;//修改0次 
		f[0][1][a[1]^1][a[2]]=1;//修改1次 
		f[0][1][a[1]][a[2]^1]=1;//修改1次 
		f[0][2][a[1]^1][a[2]^1]=1;//修改2次 
		for(int i=2;i<n;i++)//遍历a（3-n） 
		{
			int now=i&1,nxt=now^1;
			for(int j=0;j<=m;j++) for(int p=0;p<2;p++) for(int q=0;q<2;q++) f[nxt][j][p][q]=0;//滚动数组 
			for(int j=0;j<=m;j++) for(int p=0;p<2;p++) for(int q=0;q<2;q++)
			if(f[now][j][p][q])
			{
				if(!(p==1&&q==1&&a[i+1]==0)) f[nxt][j][q][a[i+1]]=(f[nxt][j][q][a[i+1]]+f[now][j][p][q])%P;//不是110时，转移 （110时不能转移） 
				if(!(p==1&&q==1&&a[i+1]==1)) f[nxt][j+1][q][a[i+1]^1]=(f[nxt][j+1][q][a[i+1]^1]+f[now][j][p][q])%P;//不是111时，修改 （111时不能修改） 
			}
		}
		int ans=0;
		for(int i=0;i<=m;i++) for(int p=0;p<2;p++) for(int q=0;q<2;q++) ans=(ans+f[n&1][i][p][q])%P;
		cout<<ans<<"\n";
	}
}
