#include <bits/stdc++.h>
using namespace std;
#define N 400010
int n,a[N],de[N],f[N]; 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		de[a[i]]++;
	}
	queue<int>q;
	for(int i=1;i<=2*n;i++) if(!de[i]) q.push(i);
	int ans=2*n;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
//		cout<<u<<" "<<ans<<"\n";
		ans--;
		if(u>n)
		{
			ans+=f[u];
			continue;
		}
		f[a[u]]=max(f[a[u]],f[u]+1);
		if(--de[a[u]]==0) q.push(a[u]);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
