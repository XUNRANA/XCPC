#include <bits/stdc++.h>
using namespace std;


int n,a[200010];
int cnt,ans;
int nex[30*100010][2];
void insert(int x)//插入trie树 
{
	int now=0;
	for(int i=30;i>=0;i--)
	{
		int t=x>>i&1;
		if(!nex[now][t]) nex[now][t]=++cnt;
		now=nex[now][t];
	}
}
void query(int x)//查找与x异或最大的 
{
	int res=0,now=0;
	for(int i=30;i>=0;i--)
	{
		int t=x>>i&1;
		if(nex[now][!t])//有反向走反向 
		{
			res|=1<<i;
			now=nex[now][!t];
		}
		else now=nex[now][t];
	}
	ans=max(ans,res);//找最大 
}

void solve()
{
    cin>>n;
    for(int i=2;i<=n;i++) cin>>a[i],a[i]^=a[i-1];

    
    for(int i=1;i<=n;i++) 
    {
        insert(a[i]);
        // cout<<a[i]<<" \n"[i==n];
    }
    for(int i=0;i<n;i++)
    {
        ans=0;
        query(i);
        if(ans==n-1)
        {
            for(int j=1;j<=n;j++) cout<<(a[j]^i)<<" \n"[j==n];
            return ;
        }
    }

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}