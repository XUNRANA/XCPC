#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,k,n;
typedef vector<vector<int>> M;//矩阵 
M mul(M A,M B)//矩阵乘法 
{
	int n=A.size();
	M C(n,vector<int>(n,0));//单位矩阵
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				C[i][j]=(C[i][j]+A[i][k]*B[k][j]%m+m)%m;
			}
		}
	}
	return C;
}
M ksm(M A,int b)
{
	int n=A.size();
	M res(n,vector<int>(n,0));//单位矩阵
	for(int i=0;i<n;i++) res[i][i]=1;
	while(b)
	{
		if(b&1) res=mul(res,A);
		A=mul(A,A);
		b>>=1;
	} 
	return res;
}
void solve()
{
	cin>>m>>k>>n;
	if(n==0) cout<<2<<"\n";
	else if(n==1) cout<<k<<"\n";
	else
	{
		M A={{k,-1},{1,0}};
		M T=ksm(A,n-1);
		cout<<(T[0][0]*k%m+T[0][1]*2%m+m)%m; 
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
