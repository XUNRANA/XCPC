#include <bits/stdc++.h>
using namespace std;
int n,r,q;
struct node
{
	int s,t,l;
}a[200010];
bool cmp(struct node a1,struct node a2)
{
	if(a1.s==a2.s) return a1.l<a2.l;
	return a1.s>a2.s;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>r>>q;
	for(int i=1;i<=2*n;i++) cin>>a[i].s,a[i].l=i;
	for(int i=1;i<=2*n;i++) cin>>a[i].t;
	sort(a+1,a+1+2*n,cmp);
	while(r--)
	{
		for(int i=2*n;i>=1;i-=2)
		{
			if(a[i].t>a[i-1].t) a[i].s++;
			else a[i-1].s++;
		}
		sort(a+1,a+1+2*n,cmp);
	}
	cout<<a[q].l;
}
