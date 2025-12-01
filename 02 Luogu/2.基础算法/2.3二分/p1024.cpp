#include <bits/stdc++.h>
using namespace std;
double a,b,c,d,l,r,m,x1,x2,s;
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d; 
}
int main()
{
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++)
	{
		l=i;
		r=i+1;
		x1=f(l);
		x2=f(r);
		if(!x1) 
		{
			printf("%.2f ",l);
			s++;
		}
		if(x1*x2<0)
		{
			while(r-l>=0.001)
			{
				m=(l+r)/2;
				if(f(m)*f(r)<0) l=m;
				else r=m;
			}
			printf("%.2f ",r);
			s++;
		}
		if(s==3) break;
	}
}
