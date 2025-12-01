#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
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
				C[i][j]=(C[i][j]+A[i][k]*B[k][j]%P+P)%P;
			}
		}
	}
	return C;
}
M ksm(M A,int b)//矩阵快速幂 
{
	int n=A.size();
	M res(n,vector<int>(n,0));//单位矩阵
	for(int i=0;i<n;i++) res[i][i]=1;//单位矩阵初始化 
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
    int n;
    cin>>n;
    if(n<=3) 
    {
        cout<<"1\n";
    }
    else
    {
        M A={{1,0,1},{1,0,0},{0,1,0}};
        A=ksm(A,n);
        cout<<A[1][0]<<"\n";
    }

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}