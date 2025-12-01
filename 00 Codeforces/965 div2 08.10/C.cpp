#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,k,ans;
struct node
{
	int a,b;
}c[N];
bool cmp(node c1,node c2)
{
	if(c1.a==c2.a) return c1.b<c2.b;
	return c1.a<c2.a;
}
int ck(int x)
{
	
}
int ck(int x,int t)
{
	int s=0;
	for(int i=t;i<=n;i++)
	{
		if(c[i].a<x ) s+=x-c[i].a;
	}
	if(s<=k) return 1;
	else return 0;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>c[i].a;
	for(int i=1;i<=n;i++) cin>>c[i].b;
	sort(c+1,c+1+n,cmp);
//	if(c[n].b)
//	{
//		cout<<c[n].a+k+c[n/2].a<<"\n";
//		return ;
//	}
//	else
//	{
//		int t=c[n/2].a;
//		int l=1,r=1e9;
//		while(l<=r)
//		{
//			int m=l+r>>1;
//			if(ck(m,n/2)) l=m+1;
//			else r=m-1;
//		}
//		
//	}
//	for(int i=n;i>=1;i--)
//	{
//		if(c[i].b) ans=max(ans,c[i].a+k+c[i/2].a);
//		else ans=max(ans,c[i].a+)
//	}
	//1 1 2 5
	//1 1 0 0
//	5
//	1 2 3 4
	
//	l=1,r=1e9;
//	while(l<=r)
//	{
//		m=l+r>>1;
//		if(ck(m)) l=m+1;
//		else r=m-1;
//	}
//	cout<<l<<"\n";
	
	for(int i=1;i<=n;i++) cout<<c[i].a<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<c[i].b<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

