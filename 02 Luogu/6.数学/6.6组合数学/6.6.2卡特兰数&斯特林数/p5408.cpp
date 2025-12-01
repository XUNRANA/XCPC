#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 167772161
int S[1010][1010];
void solve()
{
	//组合数   c(n,m)=c(n-1,m-1)+c(n-1,m)
	//第一类斯特林数（圆排列）： s(n,m)=s(n-1,m-1)+(n-1)*s(n-1,m)
	//第二类斯特拉数（不排列）： s(n,m)=求和(k:0-m) (-1^k)*C(m,k)*(m-k)^n*(1/m!) 
	int n;
	cin>>n;
	S[0][0]=1; 
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=i;j++)
	S[i][j]=(S[i-1][j-1]+S[i-1][j]*(i-1)%P)%P;
	
	for(int i=0;i<=n;i++) cout<<S[n][i]<<" ";
	cout<<"\n";	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
