#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct node
{
	long long l,r;
}a[1010];
bool cmp(struct node a1,struct node a2)
{
	return a1.l*a1.r<a2.l*a2.r;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n+1;i++) cin>>a[i].l>>a[i].r;
	sort(a+2,a+n+2,cmp);
	for(int i=2;i<=n+1;i++)
	{
		ans=max(ans,a[1].l/a[i].r);
		a[1].l*=a[i].l;
	}
	cout<<ans;
} 
