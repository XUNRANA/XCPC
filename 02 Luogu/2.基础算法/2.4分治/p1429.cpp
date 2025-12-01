#include <bits/stdc++.h>
using namespace std;
struct node
{
	double x,y;
}a[200010];
double d(int i,int j)
{
	return sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
}
bool cmp(node a1,node a2)
{
	if(a1.x==a2.x) return a1.y<a2.y;
	return a1.x<a2.x;
}
int main()
{
	int n;
	double ans=1e10;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) 
	for(int j=i+1;j<=min(n,i+20);j++) 
	ans=min(ans,d(i,j));
	printf("%.4f",ans);
}
