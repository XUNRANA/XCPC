#include <bits/stdc++.h>
using namespace std;
#define N 4010
int r[N],l[N],d[N],xi[N];
map<pair<int,int>,int>mp;
set<pair<int,int>>s;
int ck(int x,int y)
{
	if(r[x]==2) return 0;
	if(l[y]==2) return 0;
	if(d[x-y+1000]==2) return 0;
	if(xi[x+y]==2) return 0;
    vector<pair<int,int>>v;
    for(auto i:s)
    {
        int nx=i.first,ny=i.second;
        if(nx==x||y==ny||nx-ny==x-y||nx+ny==x+y) continue;
        //cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<"\n";
        int yy=ny-y;
        int xx=nx-x;
        int g=__gcd(xx,yy);
        yy/=g;
        xx/=g;
        if(xx<0) 
        {
            xx=-xx;
            yy=-yy;
        }
        if(mp.count({xx,yy})) return 0;
        v.push_back({xx,yy});
    }
    for(auto i:v) mp[i]=1;
	return 1;
}
void solve()
{
	int n,x,y;
	string ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
        {
            
        x=i;
            y=j;
		if(ck(x,y)) 
		{
            s.insert({x,y});
			ans+="1";
			r[x]++;
			l[y]++;
            d[x-y+1000]++;
			xi[x+y]++;
		}
		else ans+="0";
        }
    }
    for(int i=0;i<ans.size();i+=n) cout<<ans.substr(i,n)<<"\n";
    cout<<ans<<"\n";
    for(auto i:mp) cout<<i.first.first<<" "<<i.first.second<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
