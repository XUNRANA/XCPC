#include <bits/stdc++.h>
using namespace std;
int n,A,x,y;
vector<int> f(int A,int x)
{
    vector<int>a;
    while(x)
    {
        a.push_back(x%A);
        x/=A;
    }
    return a;
}
vector<int> fx1(vector<int>a,vector<int>b)
{
    vector<int>c;
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        c.push_back(min(a[i],b[i]));
    }
    return c;
}
vector<int> fx2(vector<int>a,vector<int>b)
{
    vector<int>c;
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        c.push_back(max(a[i],b[i]));
    }
    while(c.size()<a.size())
    {
        int i=c.size();
        c.push_back(a[i]);
    }
    while(c.size()<b.size())
    {
        int i=c.size();
        c.push_back(b[i]);
    }
    return c;
}
vector<int> fx3(vector<int>a,vector<int>b)
{
    vector<int>c;
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        c.push_back((a[i]+b[i])%A);
    }
    while(c.size()<a.size())
    {
        int i=c.size();
        c.push_back(a[i]);
    }
    while(c.size()<b.size())
    {
        int i=c.size();
        c.push_back(b[i]);
    }
    return c;
}
void solve()
{
    cin>>n>>A>>x;
    set<vector<int>>a;
    a.insert(f(A,x));
    while(n--)
    {
        cin>>y;
        set<vector<int>>na;
        for(auto c:a)
        {
            auto b=f(A,y);
            na.insert(fx1(b,c));
            na.insert(fx2(b,c));
            na.insert(fx3(b,c));
        }
        a=na;
    }
    int ans=0;
    for(auto i:a)
    {
        int res=0;
        for(auto j:i) res=res*A+j;
        ans+=res;
        cout<<res<<"\n";
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
