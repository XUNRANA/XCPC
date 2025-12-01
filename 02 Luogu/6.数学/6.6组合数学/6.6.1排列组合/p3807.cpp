#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,P,jc[100010];
int ksm(int a,int b)
{
    int res=1;
    while(b) 
	{
		if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
int C(int n,int m)
{
	if(m>n) return 0;
	return jc[n]*inv(jc[m])%P*inv(jc[n-m])%P;
}
int lucas(int n,int m)//Â¬¿¨Ë¹¶¨Àí 
{
	if(!m) return 1;
	return C(n%P,m%P)*lucas(n/P,m/P)%P;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=P;i++) jc[i]=jc[i-1]*i%P;
}
void solve() 
{
	cin>>n>>m>>P;
	init();
	cout<<lucas(n+m,n)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
