void init(int n)//线性求逆元 inv(x)表示1/x对p取模 
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;
}

//a*x+b*y==gcd(a,b)
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int res=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return res;
}
int getinv(int a)//exgcd求逆元 getinv(x)返回1/x对P取模 
{
	int x=0,y=0;
	int d=exgcd(a,P,x,y);
	return d==1? (x%P+P)%P:-1;
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
int inv(int x)//适用P为质数的时候 
{
	return ksm(x,P-2);
} 

