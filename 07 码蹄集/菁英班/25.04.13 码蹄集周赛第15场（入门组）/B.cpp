#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int a,b,c,i;
}a[10010];
bool cmp(node a1,node a2)
{
	if(a1.c==a2.c) return a1.i>a2.i;
	return a1.c<a2.c;
}
int f[10010];
void solve()
{
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].a>>a[i].b;
		a[i].c=a[i].a-a[i].b;
		a[i].i=i;
		s+=a[i].c;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++) f[a[i].i]=1;
	

	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
