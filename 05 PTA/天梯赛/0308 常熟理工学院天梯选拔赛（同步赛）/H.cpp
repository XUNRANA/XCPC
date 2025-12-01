#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node
{
	int x,y,type,dis,id;
}p[2010];
bool c1(node p1,node p2)
{
    if(p1.dis==p2.dis) return p1.id<p2.id;
	return p1.dis<p2.dis;
}
int ans[2010];
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y>>p[i].type,p[i].id=i;
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=n;i++) p[i].dis=(p[i].x-x)*(p[i].x-x)+(p[i].y-y)*(p[i].y-y);
	sort(p+1,p+1+n,c1);
	map<int,int>cnt;
	int mx=0,res=0;
	for(int i=1;i<=n;i++)
	{
		cnt[p[i].type]++;
		if(cnt[p[i].type]>mx)
		{
			mx=cnt[p[i].type];
			res=p[i].type;
		}
		else if(cnt[p[i].type]==mx) res=min(res,p[i].type);
		ans[i]=res;
	}
	
	while(q--)
	{
		int x;
		cin>>x;
		cout<<ans[x]<<"\n";
	}
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

