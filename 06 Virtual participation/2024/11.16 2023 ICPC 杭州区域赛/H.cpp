#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
const int N = 5e5+5;
int a[N],b[N],w[N],d[N],n;
vector<int>g[N];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	} 
	return res;
}
int inv(int x)
{
	return ksm(x,P-2);
}
int jc[N];
void init()
{
	jc[0]=1;
	for(int i=1;i<N;i++) jc[i]=jc[i-1]*i%P;
}
void dfs(int x)
{
	for(auto v:g[x])
	{
		d[v]=d[x]+1;
		dfs(v);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) d[i]=0,g[i].clear();
	
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		if(a[b[i]]>a[i]) d[i]=1,v.push_back(i);//必须发生 
		else if(a[b[i]]+w[b[i]]<=a[i]) ;//肯定不发生 
		else g[b[i]].push_back(i);//可能发生 
	}
	
	for(auto x:v) dfs(x);//肯定发生的继续扩展 
	
	for(int i=1;i<=n;i++)
	{
		int ans;
		if(!d[i]) ans=a[i];//肯定不发生 
		else ans=(a[i]+w[i]*inv(jc[d[i]])%P)%P;
		cout<<ans<<" ";
	}
	cout<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
