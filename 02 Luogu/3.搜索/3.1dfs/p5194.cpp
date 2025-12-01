#include <bits/stdc++.h>
using namespace std;
long long n,c,ans,a[1010],s[1010];
void dfs(int cur,long long sum)
{
	if(sum>c) return ;
	if(s[cur-1]+sum<=c)// ¼ôÖ¦ 
	{
		ans=max(ans,s[cur-1]+sum);
		return ;
	}
	ans=max(ans,sum);
	for(int i=1;i<cur;i++) dfs(i,sum+a[i]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]+=s[i-1]+a[i];
	dfs(n+1,0);
	cout<<ans;
}
