#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[70],p1[70],cnt;
void insert(int x)//插入一个值 
{
	for(int i=63;i>=0;i--)
	{
		if(x>>i&1)
		{
			if(!p[i]) 
			{
				p[i]=x;
				return ;
			}
			else x^=p[i];
		}
	}
}
bool check(int x)//判断x是否可以异或得到 
{
	for(int i=63;i>=0;i--)
	{
		if(x>>i&1)
		{
			if(!p[i]) return false;
			else x^=p[i];
		}
	}
	return true;
}
int mx()//返回异或最大值
{
	int res=0;
	for(int i=63;i>=0;i--) res=max(res,res^p[i]);
	return res;
}
int mi()//返回异或最小值
{
	for(int i=0;i<=63;i++) if(p[i]) return p[i]; 
} 

void exchange()//改造线性基 
{
	for(int i=0;i<=63;i++)
	{
		for(int j=i-1;j>=0;j--)
		if(p[i]>>j&1) p[i]^=p[j];//其他位变成0，保证唯一性 
		
		if(p[i]) p1[cnt++]=p[i];//记录新的线性基 
	} 
	
}
int min_k_num(int k)//求第k小的异或值, 先调用exchange函数 
{
	int ans=0;
	for(int i=0;i<cnt;i++)
	{
		if(k>>i&1) ans^=p1[i];
	}
	return ans;
} 

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		insert(x);
	}
	exchange();
	int k=1ll<<cnt;
	cout<<min_k_num(k/2)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
