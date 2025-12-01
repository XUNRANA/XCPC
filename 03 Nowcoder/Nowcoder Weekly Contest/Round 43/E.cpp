#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res;
bool cmp(vector<int>a,vector<int>b)
{
    int dx=a[0],dy=a[1],x1=a[2],y1=a[3],x2=b[2],y2=b[3];
    return dx*y1-dy*x1<dx*y2-dy*x2;
}
void solve()
{
	cin>>n;
	vector<pair<int,int>>a(n);
    map<pair<int,int>,vector<vector<int>>>mp;
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    for(int i=0;i<n;i++)
    {
        int x1=a[i].first,y1=a[i].second;
        for(int j=i+1;j<n;j++)
        {
            int x2=a[j].first,y2=a[j].second;
            int dx=x1-x2,dy=y1-y2;
            if(dx<0) dx=-dx,dy=-dy;
            mp[{dx,dy}].push_back({dx,dy,x1,y1});
        }
    }
    for(auto i:mp)
    {
        auto v=i.second;
        sort(v.begin(),v.end(),cmp);
        int x1=v[0][2],y1=v[0][3],x2=v.back()[2],y2=v.back()[3];
        int dx=x1-x2,dy=y1-y2;
        res=max(res,abs(i.first.first*dy-i.first.second*dx));
    }
    if(res==0) cout<<"-1\n";
    else cout<<res<<".0"; 
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
int n,res;
void solve()
{
	cin>>n;
	vector<pair<int,int>>a(n); 
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	map<pair<int,int>,int>mx,mn;
	for(int i=0;i<n;i++)
	{
		int x1=a[i].first,y1=a[i].second;
		for(int j=0;j<i;j++)
		{
			int x2=a[j].first,y2=a[j].second;
			int dx=x2-x1,dy=y2-y1;
			if(dx>0)
			{
				dx=-dx;
				dy=-dy;
			}
			int s=dy*x2-dx*y2;
			if(!mx.count({dx,dy}))
			{
				mx[{dx,dy}]=-1e18;
				mn[{dx,dy}]=1e18;
			}
			mx[{dx,dy}]=max(mx[{dx,dy}],s);
			mn[{dx,dy}]=min(mn[{dx,dy}],s);
			res=max(res,mx[{dx,dy}]-mn[{dx,dy}]);
		}
	}
	if(res==0) res=-1;
	cout<<res<<".0";
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
