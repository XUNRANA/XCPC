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
int lucas(int n,int m)//卢卡斯定理 C(n,m)%P
{
	if(!m) return 1;
	return C(n%P,m%P)*lucas(n/P,m/P)%P;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=P;i++) jc[i]=jc[i-1]*i%P;
}