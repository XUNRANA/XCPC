#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
void solve()
{
	cin>>n;
	vector<array<int,2>>a(n);
	for(int i=0;i<n;i++) cin>>a[i][0];//输入a 
	for(int i=0;i<n;i++) cin>>a[i][1];//输入b 
	sort(a.begin(),a.end());//按a排序 
	ans=0;
	for(int x=1;x*x<=2*n;x++)//遍历1-sqrt(n) 
	{
		vector<int>c(n+1);
		for(int i=0;i<n;i++)
		{
			int y=x*a[i][0]-a[i][1];
			if(y>=1&&y<=n) ans+=c[y];
			if(a[i][0]==x) c[a[i][1]]++;
		}	
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
