#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void solve()
{
    cin>>n>>m;
    queue<array<int,2>>q;

    vector<vector<int>>ban(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='#') 
            {
                q.push({i,j});
                ban[i][j]=1;
            }
        }
    }


    int ans=0;
    while(!q.empty())
    {
        map<array<int,2>,int>mp;
        while(!q.empty())
        {
            ans++;
            int x=q.front()[0];
            int y=q.front()[1];
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<1||nx>n||ny<1||ny>m) continue;
                mp[{nx,ny}]++;
            }
        }

        for(auto i:mp) 
        {
            if(i.second==1&&!ban[i.first[0]][i.first[1]]) q.push(i.first);
            ban[i.first[0]][i.first[1]]=1;
        }
    }

    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
