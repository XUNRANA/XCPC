#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int a,i,ans,s;
}a[100010];
bool cmp1(node a1,node a2)
{
	return a1.a<a2.a;
}
bool cmp2(node a1,node a2)
{
	return a1.i<a2.i;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a,a[i].i=i,a[i].s=0;
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++) a[i].s=a[i-1].s+a[i].a;
	
	/*
	for(int i=1;i<=n;i++) cout<<a[i].a<<" ";
	cout<<"\n";
	
	for(int i=1;i<=n;i++) cout<<a[i].s<<" ";
	cout<<"\n";
	*/
		
	for(int i=1,j=1;i<=n;i++)
	{
		if(i>j) j=i;
		while(j+1<=n&&a[j].s>=a[j+1].a) j++;
		a[i].ans=j-1;
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++) cout<<a[i].ans<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
