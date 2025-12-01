#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double 
struct p{
	int x,y;
};
int dispp(p u,p v)
{
	return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
}
double disps(p u,p v,p w)//uµ½Ïß¶Îv£¬wµÄ¾àÀë 
{
	int d1=(u.x-v.x)*(w.x-v.x)+(u.y-v.y)*(w.y-v.y);
    if(d1<=0.0) return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
    int d2=(v.x-w.x)*(v.x-w.x)+(v.y-w.y)*(v.y-w.y);
    if(d1>=d2) return (u.x-w.x)*(u.x-w.x)+(u.y-w.y)*(u.y-w.y);
    double r=1.0*d1/d2;
    double px=v.x+(w.x-v.x)*r;
    double py=v.y+(w.y-v.y)*r;
    return (u.x-px)*(u.x-px)+(u.y-py)*(u.y-py);
}
void solve()
{
	p c;
	int r,n,ans=0;
	cin>>c.x>>c.y>>r>>n;
	vector<p>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	r=r*r;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int d1=dispp(c,a[i]);
			int d2=dispp(c,a[j]);
			if(d1==r&&d2==r) ans+=2;
			else if(d1<r&&d2>=r||d1>=r&&d2<r) ans++;
			else if(d1<r&&d2<r) ;
			else
			{
				double d=disps(c,a[i],a[j]);
				if(d==r) ans++;
				else if(d<r) ans+=2;
			} 
		}
	}
	ans*=n-2;
	for(int i=1;i<=n;i++) if(dispp(a[i],c)==r) ans-=(n-1)*(n-2)/2;
	int sum=n*(n-1)*(n-2)/6;
	printf("%.8f",1.0*ans/sum);
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
