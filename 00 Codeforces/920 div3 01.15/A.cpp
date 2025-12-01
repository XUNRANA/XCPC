#include <bits/stdc++.h>
using namespace std;
int t;
struct node
{
	int x,y;
}a[5];
bool cmp(struct node a1,struct node a2)
{
	if(a1.x==a2.x) return a1.y<a2.y;
	return a1.x<a2.x;
}
int main()
{
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=4;i++) cin>>a[i].x>>a[i].y;
		sort(a+1,a+1+4,cmp);
		cout<<(a[2].y-a[1].y)*(a[3].x-a[1].x)<<"\n";
	}
}
