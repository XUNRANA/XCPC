#include <bits/stdc++.h>
using namespace std;
int xx[200010];
int yy[200010];
void solve()
{
    int n,q;
    string s;
    cin>>n>>q;
    cin>>s;
    map<pair<int,int>,vector<int>>mp;
    int x=0;
    int y=0;
    mp[{x,y}].push_back(0);
    xx[0]=0;
    yy[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='U') y++;
        else if(s[i-1]=='D') y--;
        else if(s[i-1]=='L') x--;
        else x++;
        mp[{x,y}].push_back(i);
        xx[i]=x;
        yy[i]=y;
    }
    while(q--)
    {
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        if(mp.count({x,y})&&(mp[{x,y}][0]<l||mp[{x,y}].back()>=r)) cout<<"YES\n";
        else 
        {
            x=xx[l-1]+xx[r]-x;
            y=yy[l-1]+yy[r]-y;
            if(mp.count({x,y}))
            {
                auto it=lower_bound(mp[{x,y}].begin(),mp[{x,y}].end(),l-1);
                if(it!=mp[{x,y}].end()&&*it<=r) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else cout<<"NO\n";
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
