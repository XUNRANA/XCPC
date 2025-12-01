#include <bits/stdc++.h>
using namespace std;
struct node
{
	int k,s;
}a[5010];
bool cmp(struct node a1,struct node a2)
{
	if(a1.s==a2.s) return a1.k<a2.k;
	return a1.s>a2.s;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].k>>a[i].s;
	sort(a+1,a+1+n,cmp);
	int n1=floor(m*1.5); 
	while(n1<n&&a[n1+1].s==a[n1].s) n1++;
	cout<<a[n1].s<<" "<<n1<<"\n";
	for(int i=1;i<=n1;i++) cout<<a[i].k<<" "<<a[i].s<<"\n";
}
