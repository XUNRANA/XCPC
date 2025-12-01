#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>fa,mp; 
int ans,d,q,x,y;
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
int fx(int x,int y)
{
    return x*x+y*y;
}
void solve()
{
	cin>>d>>q;
	while(q--)
	{
		ans++;
		cin>>x>>y;
		mp[x]=y;
		fa[x]=x;
		for(int i=x-d;i<=x+d;i++)
		{
			if(mp.find(i)==mp.end()||i==x) continue;
			if(fx(i-x,mp[i]-y)<=d*d)
			{
				if(find(x)!=find(i))
				{
					fa[find(x)]=find(i);
					ans--;
				}
			}
		}
		cout<<ans<<"\n";
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
