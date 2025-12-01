int gcd(int x,int y)
{
	return y==0? x:gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}
