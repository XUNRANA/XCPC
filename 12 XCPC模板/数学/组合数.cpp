#define P 1000000007
int jc[100010];
void init()
{
	jc[0]=1;
	for(int i=1;i<100000;i++) jc[i]=jc[i-1]*i%P;
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
int inv(int x)
{
	return ksm(x,P-2);
}
int C(int a,int b)//适合a，b均大于1e4 
{
	return jc[a]*inv(jc[b]*jc[a-b]%P)%P;
}



int C[2010][2010];
void init()//适合a*b<=1e7 
{
	for(int i=0;i<=2000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
		}
	} 
}