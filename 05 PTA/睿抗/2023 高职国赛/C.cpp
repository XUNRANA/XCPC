#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,q;
vector<int>g[110];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,k;
        cin>>u;
        cin>>k;
        while(k--)
        {
            cin>>v;
            g[u].push_back(v);
        }
    }
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        queue<int>q;
        q.push(x);
        int ans1=1;
        int ans2=1;
        int c=1;
        while(!q.empty())
        {
            queue<int>q1;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto v:g[u])
                q1.push(v);
            }
            c++;
            if(q1.size()>ans2)
            {
                ans2=q1.size();
                ans1=c;
            }
            q=q1;
        }
        cout<<ans1<<" "<<ans2<<"\n";
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
