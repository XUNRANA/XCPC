#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
2
2
0 0
0 1
3
1 1
2 3
5 8
*/
struct p
{
	int x;
	int y;
}a[200010];
bool cmp1(p p1,p p2)
{
	return (p1.y-p1.x)<(p2.y-p2.x);
}
bool cmp2(p p1,p p2)
{
	return (p1.y+p1.x)<(p2.y+p2.x);
}
double fx(int i)
{
	return 1.0*(abs(a[i].x-a[i+1].x)+abs(a[i].y-a[i+1].y))/(sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y)));
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,cmp1);
	double ans=1.0;
	for(int i=1;i<=n-1;i++)
	ans=max(ans,fx(i));
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n-1;i++)
	ans=max(ans,fx(i));
	printf("%.12f\n",ans);
}

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
