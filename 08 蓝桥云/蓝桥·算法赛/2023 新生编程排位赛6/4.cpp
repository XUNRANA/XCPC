#include <bits/stdc++.h>
using namespace std;
struct node
{
	int d,h;
}a[100010];
bool cmp(node a1,node a2)
{
	if(a1.d==a2.d) return a1.h<a2.h;
	return a1.d>a2.d;
}
int n,mx,ans=1;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].h;
	sort(a+1,a+1+n,cmp);
	mx=a[1].h;
	for(int i=2;i<=n;i++)
	{
		if(a[i].h>=mx) 
		{
			mx=a[i].h;
			ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
