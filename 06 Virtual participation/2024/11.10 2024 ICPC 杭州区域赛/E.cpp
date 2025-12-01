#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int l,r,i;
}a[100010];
int vt[100010];
bool cmp(node a1,node a2)
{
	return a1.l<a2.l;
}
void solve()
{
	int n,f;
	cin>>n>>f;
	int ans=0;
	vector<int>res;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r,a[i].i=i,vt[i]=0,ans+=a[i].r-a[i].l;
	sort(a+1,a+1+n,cmp);//°´lÉýÐò	
	for(int i=1;i<=n;i++) 
	if(a[i].l>f) 
	{
		vt[i]=1;
		res.push_back(a[i].i);
		ans+=a[i].l-f;
		f=a[i].r;
	}
	else if(a[i].r>f) 
	{
		vt[i]=1;
		res.push_back(a[i].i);
		f=a[i].r;
	}
	
	for(int i=n;i>=1;i--) if(!vt[i]) res.push_back(a[i].i);
	
	cout<<ans<<"\n";
	for(auto i:res) cout<<i<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
