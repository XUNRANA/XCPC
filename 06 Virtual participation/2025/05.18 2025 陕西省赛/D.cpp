#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<double>a,b;
double ans;
int n;
void dfs(int i,int j,double now,double sum)
{
    if(i==a.size()&&j==b.size())
    {
        ans=max(ans,sum/(1.0*n));
        return ;
    }
    if(i<a.size())
    {
        dfs(i+1,j,now+a[i],sum+now+a[i]);
    }
    if(j<b.size())
    {
        dfs(i,j+1,now*b[j],sum+now*b[j]);
    }
}
void solve()
{
    double v;
    cin>>n>>v;
    for(int i=1;i<=n;i++)
    {
        char ch;
        double x;
        cin>>ch>>x;
        if(ch=='+') a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(),a.end(),greater<double>());
    sort(b.begin(),b.end(),greater<double>());
    dfs(0,0,v,0);
    printf("%.9f",ans);
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}