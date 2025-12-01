#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	double c;
	double p;
}a[1010];
bool cmp(node a1,node a2)
{
	return a1.p*a2.c>a2.p*a1.c;
}
void solve()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i].c;
	for(int i=1;i<=n;i++) cin>>a[i].p;
	sort(a+1,a+1+n,cmp);
	double s=0;
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s+a[i].c<=d) 
		{
			ans+=a[i].p;
			s+=a[i].c;
		}
		else
		{
			double fz=d-s;
			ans+=1.00*fz*a[i].p/a[i].c;
			break;
		}
	}
	
	printf("%.2f",ans);
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

