#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int i,x,ans;
}a[200010];
bool cmp(node a1,node a2)
{
	return a1.x<a2.x;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x,a[i].i=i;
	sort(a+1,a+1+n,cmp);
	int mx=0;
	for(int i=1;i<=n;i++) a[i].ans=(a[i].x)*(n-i+1)*(n-i+1),mx=max(mx,a[i].ans);
	for(int i=1;i<=n;i++) 
	if(mx==a[i].ans)
	{
		cout<<n-i+1<<"\n";
		vector<int>res;
		for(int j=i;j<=n;j++) res.push_back(a[j].i);
		sort(res.begin(),res.end());
		for(auto j:res) cout<<j<<" ";
		cout<<"\n";
		break;
	}
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
