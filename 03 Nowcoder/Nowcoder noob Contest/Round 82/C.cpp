#include <bits/stdc++.h>
using namespace std;
#define M 998244353;
long long i,j,k,n,m,t,res[200500],f[200500],ft[200500],ftx[200500];
int main()
{
	f[0]=1;
	for(i=1;i<=200000;i++)
    {
		f[i]=(f[i-1]*25+ft[i-1]*24+ftx[i-1]*25)%M;
		ft[i]=(f[i-1]+ft[i-1])%M;
		ftx[i]=(ft[i-1])%M;
		res[i]=(res[i-1]*26+ftx[i-1])%M;
	}
	cin>>t;
	while(t--)
    {
		cin>>n;
		cout<<res[n]<<"\n";
	}
}