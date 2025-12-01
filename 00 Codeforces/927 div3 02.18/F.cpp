#include <bits/stdc++.h>
using namespace std;
#define N 1000020
//L[i]:包含i的所以区间的最左端点最小值
//dp[i]：喂第i个点，dp[L[i]-1]+cnt[i]、不喂的话是dp[i-1] 
//cnt[i]；包含点i的所以区间数量  
int n,m,cnt[N],dp[N],L[N],l,r;
struct node
{
	int l,r;
}a[N];

bool cmp(node a1,node a2)
{
	if(a1.l==a2.l) return a1.r>a2.r;
	return a1.l<a2.l;
}

void solve()
{
	l=r=0;
	cin>>n>>m;
	for(int i=0;i<=n+10;i++) dp[i]=cnt[i]=L[i]=0;
	for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+m,cmp);
	l=a[1].l,r=a[1].r;
	L[l]+=l-1;
	L[r+1]-=l-1;
	for(int i=2;i<=m;i++)
	{
		if(a[i].r<=r) continue;
		else 
		{
			L[r+1]+=a[i].l-1;
			L[a[i].r+1]-=a[i].l-1;
			r=a[i].r;
		}
	}
	for(int i=1;i<=m;i++) cnt[a[i].l]++,cnt[a[i].r+1]--;
	for(int i=1;i<=n+1;i++) cnt[i]+=cnt[i-1],L[i]+=L[i-1];
	for(int i=1;i<=n;i++) dp[i]=max(dp[i-1],cnt[i]+dp[L[i]]);
	cout<<dp[n]<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
