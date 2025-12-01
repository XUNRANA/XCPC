#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010];
bool vis[70][2];
int b[70];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=0;i<=61;i++) vis[i][0]=vis[i][1]=0;
    
	for(int i=2;i<=n;i++)
	{
		int x=a[i-1]^a[i];
		for(int j=61;j>=0;j--)
		{
			if(x>>j&1)
			{
				vis[j][a[i-1]>>j&1]=1;
				break;
			}
		}
	}
	
	for(int j=61;j>=0;j--) 
	if(vis[j][0]&&vis[j][1])
	{
		cout<<"0\n";
		return ;
	}
	
	
	
	//b[i]:表示0到i位，有多少位是固定的 
	b[0]=vis[0][0]||vis[0][1];
	for(int j=1;j<=61;j++) b[j]=b[j-1]+(vis[j][0]||vis[j][1]);
	
	int ans=0;
	for(int j=61;j>=0;j--)
	{
		int x=k>>j&1;
		
		//该位为1，而k在该位为0
		//说明当前k的前缀，已经小于所要求的了
		if(vis[j][1]&&!x) break;
		
		
		//k在该位为1，且该位置可以取0
		//则计算<= k当前前缀...1xxx的所有可行的后缀解：...0xxx
		//其中xxx可以取0或者1，除掉必须取0/1的位置，剩下j-b[j-1]位
		if(!vis[j][1]&&x) ans+=1ll<<(j-(j? b[j-1]:0));
		
		//如果该位必须取0，而k在该位为1
 		//说明当前k的前缀，大于所要求的了
		if(vis[j][0]&&x) break;
		
		if(j==0) ans++;
	}
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
