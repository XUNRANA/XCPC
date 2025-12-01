#include <bits/stdc++.h>
using namespace std;
#define int  long long
struct node
{
	int i;
	__int128 v;
}a[100010];
bool cmp(node a1,node a2)
{
	if(a1.v==a2.v) return a1.i<a2.i;
	return a1.v>a2.v;
}
int n,x,y,z;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].i=i;
		cin>>z>>y>>x;
		y+=z/3;
		z%=3;
		x+=y/3;
		y%=3;
		a[i].v=18*x+3*y+z;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) cout<<a[i].i<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
