#include <bits/stdc++.h>
using namespace std;
long long n,m,s;
struct node
{
	long long p,n;
}a[5010];
bool cmp(struct node a1,struct node a2)
{
	if(a1.p==a2.p) return a1.n>a2.n;
	return a1.p<a2.p;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i].p>>a[i].n;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(n-a[i].n>0) 
		{
			n-=a[i].n;
			s+=a[i].n*a[i].p;
		}
		else 
		{
			s+=n*a[i].p;
			break;
		}
	}
	cout<<s;
}
