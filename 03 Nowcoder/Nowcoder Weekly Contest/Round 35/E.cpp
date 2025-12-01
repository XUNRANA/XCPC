#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100010];
vector<int>g[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(g[i].size()==0&&cnt!=n-1)
		{
			cout<<"-1\n";
			return ;
		}
		cnt+=g[i].size();
	}
	vector<pair<int,int>>ans;
	int p=1;
	for(int i=1;i<n;i++)
	{
		int p1;
		if(g[i].size()==0) break;
		for(auto j:g[i])
		{
			ans.push_back({p,j});
			p1=j;
		}
		p=p1;
	}
	if(ans.size()>m) cout<<"-1\n";
	else
	{
		int res=m-ans.size();
        if(res==0)
        {
            for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
            return ;
        }
		for(int i=1;i<n;i++)
		{
			if(g[i].size()==0) break;
			if(g[i].size()==1||g[i+1].size()==1) continue;
            for(int j=0;j<g[i].size();j++)
            {
                for(int j1=j+1;j1<g[i].size();j1++)
                {
                    res--;
					ans.push_back({g[i][j],g[i][j1]});
					if(res==0) 
					{
						for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
						return ;
					}
                }
            }
            
			for(int j=0;j<g[i].size()-1;j++)
			{
				for(int j1=0;j1<g[i+1].size();j1++)
				{
					res--;
					ans.push_back({g[i][j],g[i+1][j1]});
					if(res==0) 
					{
						for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
						return ;
					}
				}
			}
		}
		cout<<"-1\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

