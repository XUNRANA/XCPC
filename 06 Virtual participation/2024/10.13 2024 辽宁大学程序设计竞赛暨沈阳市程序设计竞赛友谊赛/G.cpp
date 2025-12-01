#include<bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int jc[2000010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=2000000;i++) jc[i]=jc[i-1]*i%P;
}
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
int C(int a,int b)
{
	return jc[a]*ksm(jc[b]*jc[a-b]%P,P-2)%P;
}
int cal(int a,int b)//将b分成a份，每份可以为空 
{
	if(b<0) return 0;
	return C(b+a-1,a-1);
}
void solve()
{
	int len,n;
	cin>>len>>n;
	int k=len-3*n;//?àóàμ??? 
	int kon=2*n+1;//A_BA_B ?éò?·???μ????? 
    if(k<0)
    {
        cout<<"0\n";
        return ;
    }
    if(k==0) 
    {
        cout<<"2\n";
        return ;
    }
    
//    A1B   0 4 1 3 2 2 4 0            5
//    A123B                            3
//    A12345B                          1
    
	int ans=(cal(kon,k)-cal(kon,k-n)+P)%P;
	while(k>0)
	{
		k-=2*n;
		ans=(ans+(cal(kon,k)-cal(kon,k-n)+P)%P)%P;
	}
	cout<<2*ans%P<<"\n";
}

signed main()
{
	init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
