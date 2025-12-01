#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
double y1,y2;
// floor（x) 小于等于x的最大整数
// ceil（x) 大于等于x的最小整数 
void solve()
{
	ans=0;
	cin>>n;
	for(int i=-n;i<=n;i++)
	{
		y2=sqrtl((n+1)*(n+1)-i*i-1);
		y1=sqrtl(n*n-i*i);
		//cout<<y1<<" "<<y2<<" "<<ceil(y1)<<" "<<floor(y2)<<"\n";
		if(y1==0)
		{
			ans++;
			ans+=2*floor(y2);
			//<<i<<" "<<ans<<"\n";
			continue;
		}
		ans+=2*(floor(y2)-ceil(y1)+1);
		//cout<<i<<" "<<ans<<"\n";
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
