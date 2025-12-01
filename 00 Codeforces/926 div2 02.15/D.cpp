#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
/*
树形dp
对于每一个点，他的所有孩子，我们在乎的形态是他们的链最长有几个危险路口 
dp1[i]，表示i的子树，经过i向下能有危险路口为0的数量  都无 （只有一种情况） 
dp2[i]，表示i的子树，经过i向下能有危险路口为1的数量  孩子1、自己1 
dp3[i]，表示i的子树，经过i向下能有危险路口为2的数量  孩子1+自己1、孩子2 
dp1[i]：始终为1
dp2[i]： 
孩子1： 
我们所有的孩子都只能有一个危险路口最多，那么至少有一个危险路口
如果孩子提供危险路口，那么应该是孩子0个1个的情况一起乘算，然后减去全部都不是危险路口的情况 
自己1： 一种情况 
dp3[i]: 那么这种情况不能加了，只能孩子提供一个或者孩子有一个链有两个危险路口 
*/
void solve()
{
	int n;
    cin>>n;
    vector<vector<int>>que(n+1);
    for(int i=1;i<=n-1;i++)
	{
        int u,v;
        cin>>u>>v;
        que[u].push_back(v);
        que[v].push_back(u);
    }
    int dp1[n+1],dp2[n+1],dp3[n+1];
    for(int i=0;i<=n;i++)
	{
        dp1[i]=1;
        dp2[i]=1;
        dp3[i]=0;
    }
    function<void(int,int)>dfs = [&](int u,int fa)
	{
        int z1=1,z2=1,z3=0;
        for(auto x:que[u])
		{
            if(x == fa) continue;
            dfs(x,u);
            z2*=(dp2[x]+dp1[x])%mod;
            z3+=dp2[x]+dp3[x];
            z2%=mod;
            z3%=mod;
        }
        z2-=z1;
        z2=(z2%mod+mod)%mod;
        dp1[u]=z1;
        dp2[u]=z1+z2;
        dp3[u]=z3;
        dp1[u]%=mod;
        dp2[u]%=mod;
        dp3[u]%=mod;

    };
    dfs(1,-1);
    cout<<(dp1[1]+dp2[1]+dp3[1])%mod<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}





//solution2
/*
f[u][x] 表示以u领导的子树中，其点到达u路径上危险的数量最多为x的方案数 
叶子节点：fu0=1（本身不危险），fu1=1（本身危险），fu2=0（不可能）
非叶子节点：
u本身非危险：fu0=所有fv0的乘积 
不超过1个的方案 ：fu1=所有的（fv0+fv1）的乘积 
最多为1个点的方案: fu1-=fu0 
u本身危险：fu1=
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
void solve()
{
	int n;cin>>n;
    vector<vector<int> > e(n+1);
    for(int i=2;i<=n;i++) 
	{
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }   
    vector<vector<int>> f(n+1,vector<int>(3));
    auto dfs=[&](auto &&self,int x,int fa)->void {
        for(int y:e[x]) if(y!=fa) 
		{
            self(self,y,x);
        }
        f[x][0]=f[x][1]=1;
        for(int y:e[x]) if(y!=fa) 
		{
            f[x][0]*=f[y][0];
            f[x][0]%=mod;
            f[x][1]*=(f[y][0]+f[y][1]);
            f[x][1]%=mod;
        }
        f[x][1]-=f[x][0];
        for(int y:e[x]) if(y!=fa) 
		{
            f[x][2]+=f[y][2]*f[x][0]/f[y][0];
            f[x][2]%=mod;
            f[x][2]+=f[y][1]*f[x][0]/f[y][0];
            f[x][2]%=mod;
        }
        f[x][1]+=f[x][0];
        f[x][1]%=mod;
    };
    dfs(dfs,1,0);
    cout<<(f[1][0]+f[1][1]+f[1][2])%mod<<"\n";
} 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}

*/
