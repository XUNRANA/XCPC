#include <bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll n,m,k,a[N],b[N],ord[N],i,j,x,y,ans;
map<ll,ll>mp[N];
bool cmp(ll x,ll y)
{
	return b[x]>b[y];
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	for(i=0;i<m;i++) scanf("%lld",&b[i]);
	for(i=0;i<k;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		mp[x][y]=1;
	}
	for(i=0;i<m;i++) ord[i]=i;
	sort(ord,ord+m,cmp);
	for(i=0;i<n;i++) for(j=0;j<m;j++)
	if(!mp[i].count(ord[j]))
	{
		ans=max(ans,a[i]+b[ord[j]]);
		break;
	}
	printf("%lld\n",ans);
}
