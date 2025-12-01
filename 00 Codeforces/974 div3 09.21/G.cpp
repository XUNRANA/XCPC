#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,k,ans,cur;
vector<pair<int,int> >v;
void work(int d)
{
	while(!v.empty()&&cur<d)
	{
		auto &x=v.back().first;
		auto &a=v.back().second;
		if(cur>x+k-1)//过期 
		{
			v.pop_back();
			continue;
		}
		if(a>=m)//一个就足以 
		{
			int r=min({cur+a/m-1,x+k-1,d-1});
			ans+=r-cur+1;
			a-=(r-cur+1)*m;
			cur=r+1;
			continue;
		}
		
		int need=m;//一个不足 
		while(!v.empty()&&need>0)
		{
			auto &x=v.back().first;
			auto &a=v.back().second;
			if(cur>x+k-1) 
			{
				v.pop_back();
				continue;
			}
			if(a<=need)//取更前的 
			{
				need-=a;
				v.pop_back();
			}
			else//刚好可以 
			{
				a-=need;
				need=0;
			}
		}
		if(need==0) ans++;//答案增加 
		cur++;//天数增加 
	}
	cur=d;//更新最新的d 
}
void solve()
{
	cin>>n>>m>>k;
	v.clear();
	cur=ans=0;
	for(int i=1;i<=n;i++)
	{
		int a,d;
		cin>>a>>d;
		work(a);
		v.push_back({a,d});
	} 
	work(1e9);
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}


