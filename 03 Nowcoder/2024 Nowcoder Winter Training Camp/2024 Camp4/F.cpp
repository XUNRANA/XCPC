#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010],ans[1010],dp[1010][1010],f[1010][7];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<6)
	{
		cout<<"0\n";
		return ;
	} 
	for(int i=1;i<=n;i++)//枚举左端点 
	{
		for(int j=1;j<=6;j++) 
		{
			f[j][0]=-1e18;//max
			f[j][1]=1e18;//min
		}
		for(int j=i;j<=n;j++)//枚举右端点 
		{
			for(int k=6;k>=1;k--)
			{//  ((1-2)*3-4)*5-6
				if(k==1)
				{
					f[k][0]=max(f[k][0],f[k-1][0]+a[j]);
					f[k][1]=min(f[k][1],f[k-1][1]+a[j]);
				}
				else if(k%2==0)
				{
					f[k][0]=max(f[k][0],f[k-1][0]-a[j]);
					f[k][1]=min(f[k][1],f[k-1][1]-a[j]);
				}
				else
				{
					for(int z=0;z<2;z++)
					{
						if(abs(f[k-1][z])>1e18/2) continue;
						f[k][0]=max(f[k][0],f[k-1][z]*a[j]);
						f[k][1]=min(f[k][1],f[k-1][z]*a[j]);
					}
				}
			}
			dp[i][j]=max(dp[i][j],f[6][0]);
		}
	}
	for(int i=1;i<=n;i++) for(int j=i-1;j>=0;j--) ans[i]=max(ans[i],ans[j]+dp[j+1][i]);
	cout<<ans[n]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}



/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010],dp[1010];
void fx(set<int>&st)
{
	while(st.size()>1) st.erase(st.begin());
}
void fn(set<int>&st)
{
	while(st.size()>1) st.erase(--st.end());
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		// ((1-2)*3-4)*5-6
		set<int>mn[6],mx[6];
		for(int j=i;j<=n;j++)
		{
			//dp[j]表示前j个数的最大得分，可由[1,j]转移而来 
			dp[j]=max(dp[j],dp[j-1]);
			for(auto &k:mn[5]) dp[j]=max(dp[j],dp[i-1]+k-a[j]);
			for(auto &k:mx[5]) dp[j]=max(dp[j],dp[i-1]+k-a[j]);
			//4*5
			for(auto &k:mn[4]) mn[5].insert(k*a[j]),mx[5].insert(k*a[j]);
			for(auto &k:mx[4]) mn[5].insert(k*a[j]),mx[5].insert(k*a[j]);
			//3-4
			for(auto &k:mn[3]) mn[4].insert(k-a[j]),mx[4].insert(k-a[j]);
			for(auto &k:mx[3]) mn[4].insert(k-a[j]),mx[4].insert(k-a[j]);
			//2*3
			for(auto &k:mn[2]) mn[3].insert(k*a[j]),mx[3].insert(k*a[j]);
			for(auto &k:mx[2]) mn[3].insert(k*a[j]),mx[3].insert(k*a[j]);
			//1-2
			for(auto &k:mn[1]) mn[2].insert(k-a[j]),mx[2].insert(k-a[j]);
			for(auto &k:mx[1]) mn[2].insert(k-a[j]),mx[2].insert(k-a[j]);
			//0-1
			mn[1].insert(a[j]);
			mx[1].insert(a[j]);
			for(int i=1;i<=5;i++) fn(mn[i]);
			for(int i=1;i<=5;i++) fx(mx[i]);
		}
	}
	cout<<dp[n]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
*/
