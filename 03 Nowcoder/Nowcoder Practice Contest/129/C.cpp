#include <bits/stdc++.h>
using namespace std;
#define int long long
int fa[200100],a[200010];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
	fa[find(a)]=find(b);
}
int n,k,t;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],fa[i]=i;
	k--;
	if(k<0)
	{
		cout<<n<<"\n";
		return ;
	}
	for(int i=n+1;i<n+100;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=60;j>=0;j--)
		{
			int fk=k>>j&1;
			int ft=a[i]>>j&1;
			if(fk&&!ft) break; //1  0
			if(ft&&!fk) merge(i,n+j+1);//0 1
            //if(ft&&!fk) cout<<i<<" "<<n+j+1<<"\n";
		}
	}
	int ans=0;
	unordered_map<int,int>mp;
	for(int i=1;i<=n;i++) mp[find(i)]++,ans=max(ans,mp[find(i)]);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
