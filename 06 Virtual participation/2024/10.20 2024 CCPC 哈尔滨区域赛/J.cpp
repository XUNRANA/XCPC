#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,m,s;
int a[N],x[N],lst[N];
void solve()
{
	cin>>n>>m;
	s=0;
	for(int i=1;i<=n;i++) cin>>a[i],lst[i]=0,s+=a[i];
	set<pair<int,int>>path;
	for(int i=1;i<=m;i++)
	{
		int id;
		cin>>x[i]>>id;
		if(s<x[i]) continue;
		path.insert({x[i-1]+1,x[i]});
		
		int lstx=x[lst[id]];//上次充电的位置 
		
		int tmp=a[id];//最多充多少电 
		
		while(1)
		{
			auto p=*path.lower_bound({lstx+1,0});
			if(tmp<p.second-p.first+1)
			{
				path.erase(p);
				path.insert({p.first+tmp,p.second});
				s+=tmp;
				break;
			}
			else
			{
				path.erase(p);
				s+=p.second-p.first+1;
				tmp-=p.second-p.first+1;
			}
			if(p.second==x[i]) break;
		}
		lst[id]=i;//更新上一个充电的地方 
	} 
	cout<<s<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
