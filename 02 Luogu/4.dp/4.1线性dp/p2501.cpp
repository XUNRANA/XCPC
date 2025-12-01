#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 35010
#define inf 0x3f3f3f3f
int n,a[N],b[N],h[N],g[N],f[N],p[N],s[N];
vector<int>vec[N];
void init(int l,int r)
{
	if(l>r) return ;
	p[l]=s[r-1]=0;
	for(int i=l+1;i<=r-1;i++) p[i]=p[i-1]+abs(b[i]-b[l]);
	for(int i=r-1;i>=l;i--) s[i]=s[i+1]+abs(b[i+1]-b[r]);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i]-i;
	int tot=1;
	g[tot]=b[1];
	f[1]=1;
	vec[1].push_back(1);
	b[n+1]=inf;
	vector<int>ans;//最长单调不降 
	for(int i=2;i<=n+1;i++)
	{
		if(b[i]>=g[tot])
		{
			g[++tot]=b[i];
			vec[tot].push_back(i);
			f[i]=tot;
		}	
		else
		{
			int l=upper_bound(g+1,g+1+tot,b[i])-g;
			g[l]=b[i];
			vec[l].push_back(i);
			f[i]=l;
		}
	}
	cout<<n-(tot-1)<<"\n";
	b[0]=-inf;
	memset(h,0x3f3f3f3f,sizeof(h));
	h[0]=0;
	vec[0].push_back(0);
	for(int i=1;i<=n+1;i++)
	{
		for(auto j:vec[f[i]-1])
		{
			if(j>i||b[j]>b[i]) continue;
			init(j,i);
			for(int k=j;k<i;k++) h[i]=min(h[i],h[j]+p[k]+s[k]);
		}
	}
	cout<<h[n+1];
}
