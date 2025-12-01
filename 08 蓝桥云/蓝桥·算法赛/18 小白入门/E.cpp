#include <bits/stdc++.h>
using namespace std;
#define N 2010
#define int long long
int n,x,y;
struct node
{
	int a,b;
}c[N];
bool cmp(node c1,node c2)
{
	return c1.b+c1.a<c2.b+c2.a;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=2*n;i++) cin>>c[i].a;
	for(int i=1;i<=2*n;i++) cin>>c[i].b;
	sort(c+1,c+1+2*n,cmp);
	for(int i=1;i<=2*n;i+=2) 
	{
		x+=c[i].a;
		y+=c[i+1].b;
	}
	cout<<x-y<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
