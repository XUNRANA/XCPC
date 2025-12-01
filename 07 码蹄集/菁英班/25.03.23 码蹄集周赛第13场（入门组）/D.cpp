#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int tr[100010];
int lowbit(int x)
{
    return x&-x;
}
void add(int i,int x)
{
    while(i<=1e5)
    {
        tr[i]+=x;
        i+=lowbit(i);
    }
}

int query(int l,int r)
{
    if(l>r) return 0;
    int res=0;
    while(r)
    {
        res+=tr[r];
        r-=lowbit(r);
    }
    l--;
    while(l)
    {
        res-=tr[l];
        l-=lowbit(l);
    }
    return res;
}

vector<int>g[100010];
vector<pair<int,int>>v;
vector<int>vv;
int ck(int m)//m的值
{
    int cnt=0;
    int l=0;
    int r=0;

    while(r<=m&&r<=1e5) 
    {
        for(auto y:g[r]) add(y,1);
        r++;
    }

    for(auto i1:v)
    {
        int i=i1.first;//x
        int j=i1.second;//y
            
        // [i-m+1,i+m-1]
        int ri=i+m;       
        cnt+=vv.end()-lower_bound(vv.begin(),vv.end(),ri);
        
        while(l<i-m+1)
        {
            for(auto y:g[l]) add(y,-1);
            l++;
        }
        while(r<=i+m-1&&r<=1e5)
        {
            for(auto y:g[r]) add(y,1);
            r++;
        }

        for(auto y:g[i]) add(y,-1);
        cnt+=query(j+m,1e5);
        for(auto y:g[i]) add(y,1);
    }

    while(l<r) 
    {
        for(auto y:g[l]) add(y,-1);
        l++;
    }

    for(int i=1;i<=1e5;i++) 
    {
        for(auto j:g[i])
        {
            cnt+=(g[i].end()-lower_bound(g[i].begin(),g[i].end(),j+m));
        }
    }
    if(cnt>=k) return 1;
    else return 0;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        vv.push_back(x);
        v.push_back({x,y});
        g[x].push_back(y);
    }
    for(int i=1;i<=1e5;i++) sort(g[i].begin(),g[i].end());
    sort(v.begin(),v.end());
    int l=1,r=1e5;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) l=m+1;
        else r=m-1;
    }
    cout<<l-1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
