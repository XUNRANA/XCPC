#include <bits/stdc++.h>
using namespace std;
int n,m,a[351],t,c[5];
int f[41][41][41][41];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>t,c[t]++;
	f[0][0][0][0]=a[1];
	for(int i=0;i<=c[1];i++)
		for(int j=0;j<=c[2];j++)
			for(int k=0;k<=c[3];k++)
				for(int l=0;l<=c[4];l++)
				{
					int r=1+i+j*2+k*3+l*4;
					if(i!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+a[r]);
					if(j!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+a[r]);
					if(k!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+a[r]);
					if(l!=0) f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+a[r]);
				}
	cout<<f[c[1]][c[2]][c[3]][c[4]];
}
