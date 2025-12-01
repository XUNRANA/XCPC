#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[400010],r[400010],a,b,c,cnt;
void solve()
{
	cin>>a>>b;
    c=a+b;
	if(!a&1||b&1)
	{
		cout<<"No\n";
		return ; 
	}
	queue<pair<int,int>>q;
	q.push({1,1});//1为黑色 
    a--;
	cnt=1;
	while(!q.empty())
	{
		int u=q.front().first;
		int f=q.front().second;
		q.pop();
		if(f)
		{
			if(b)
			{
				b-=2;
				q.push({++cnt,0});
				l[u]=cnt;
				q.push({++cnt,0});
				r[u]=cnt;
			}
			else l[u]=r[u]=-1;
		}
		else
		{
			if(a)
			{
				a-=2;
				q.push({++cnt,1});
				l[u]=cnt;
				q.push({++cnt,1});
				r[u]=cnt;
			}
			else l[u]=r[u]=-1;
		}
	}
	if(a!=0||b!=0) cout<<"No\n";
	else 
    {
        cout<<"Yes\n";
        for(int i=1;i<=c;i++) cout<<l[i]<<" "<<r[i]<<"\n";
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[400010],r[400010],a,b,c,cnt;
void dfs(int u,int f)
{
	if(u==-1) return ;
	if(f)//处理黑点 
	{
		if(b)//还有红点 
		{
			l[u]=++cnt;
			r[u]=++cnt;
			b-=2; 
		}
		else
		{
			l[u]=-1;
			r[u]=-1;
		}
		dfs(l[u],0);
		dfs(r[u],0);
	}
	else
	{
		if(a)
		{
			l[u]=++cnt;
			r[u]=++cnt;
			a-=2;
		}
		else
		{
			l[u]=-1;
			r[u]=-1;
		}
		dfs(l[u],1);
		dfs(r[u],1);
	}
}
void solve()
{
	cin>>a>>b;
    c=a+b;
	if(!a&1||b&1)
	{
		cout<<"No\n";
		return ; 
	}
	//a 黑点 奇数   
	//b 红点 偶数
	a--;
    cnt=1;
	dfs(1,1);
	if(a!=0||b!=0)
	{
		cout<<"No\n";
		return ; 
	}
	cout<<"Yes\n";
	for(int i=1;i<=c;i++) cout<<l[i]<<" "<<r[i]<<"\n";
    for(int i=1;i<=c;i++) l[i]=r[i]=0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
*/
