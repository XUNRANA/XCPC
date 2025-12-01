#include <bits/stdc++.h>
using namespace std;
#define int long long

bool f[1000010];
int mx[1000010];
vector<int>p;
vector<int>g[1000010];
void init()
{
    for(int i=2;i<=1e6;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e6;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
    f[1]=1;
    for(int i=1;i<=1e6;i++)
    {
        for(int j=i;j<=1e6;j+=i) 
        {
            if(!f[i]) mx[j]=max(mx[j],i);
            g[j].push_back(i);
        }
    }
    mx[1]=1;
}
int x;
int bfs(int t)
{
    queue<array<int,2>>q;
    q.push({1,0});
    set<int>st;
    while(!q.empty())
    {
        int v=q.front()[0];
        int c=q.front()[1];
        q.pop();
        if(st.count(v)) continue;
        st.insert(v);
        if(v==t) return c;
        for(auto j:g[t])
        {
            if(j==1) continue;
            if(j>x) break;
            if(v*j<=t) q.push({v*j,c+1});
        }
    }
}

void solve() 
{
    int a,b;
    cin>>a>>b>>x;
    int g=__gcd(a,b);
    a/=g;
    b/=g;
    if(mx[a]>x||mx[b]>x) cout<<"-1\n";
    else cout<<bfs(a)+bfs(b)<<"\n";
}


signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}