#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd;
#define x first
#define y second
pdd p1;
double s;
double dis(pdd a,pdd b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
bool line(pdd a,pdd b,pdd c)//c 在直线a，b上 
{
	pdd A={c.x-a.x,c.y-a.y};
	pdd B={c.x-b.x,c.y-b.y};
	if(A.x*B.y==B.x*A.y)//ac平行bc 
	{
		double ff=dis(a,c)+dis(b,c)-dis(a,b);
		if(fabs(ff)<1e-10) return 1;
	}
	return 0;
}
double area(pdd a,pdd b,pdd c)
{
	pdd A={a.x-b.x,a.y-b.y};
	pdd B={a.x-c.x,a.y-c.y};
	return fabs(A.x*B.y-A.y*B.x);
}
void fx(pdd a,pdd b)
{
	pdd l=a;
	pdd r=b;
	pdd o=a;
	while(dis(l,r)>1e-8)
	{
		pdd mid={(l.x+r.x)/2,(l.y+r.y)/2};
		double ss=area(o,mid,p1);
		if(ss>s) r=mid;
		else if(ss<s) l=mid;
		else 
		{
			l=mid;
			break;
		}
	}
	printf("%.15f %.15f\n",l.x,l.y);
}

void solve()
{
	pdd p[4];
	
	for(int i=1;i<=3;i++) 
	{
		int a,b;
		scanf("%d %d",&a,&b);
		p[i].x=a;
		p[i].y=b;
	}
	int a,b;
	scanf("%d %d",&a,&b);
	p1.x=a;
	p1.y=b;
	
	bool ok=0;
	s=area(p[1],p[2],p[3])/2;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i==j) continue;
			int k;
			if(line(p[i],p[j],p1))
			{
				for(k=1;k<=3;k++) if(k!=i&&k!=j) break;
				ok=1;
				if(dis(p[i],p1)>=dis(p[j],p1)) fx(p[i],p[k]);
				else fx(p[j],p[k]);
				break;
			}
		}
		if(ok) break;
	}
	if(!ok) puts("-1\n");
}

int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
