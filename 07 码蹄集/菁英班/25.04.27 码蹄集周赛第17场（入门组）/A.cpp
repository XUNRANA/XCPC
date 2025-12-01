#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int b[1010];
struct node
{
    int i;
    string s;
}t[1010];

bool cmp(node t1,node t2)
{
    return t1.s<t2.s;
}

struct pp
{
    string s;
    int p;
    int i;
    vector<int>b;
}p[1010];

bool cmp1(pp p1,pp p2)
{

    if(p1.p==p2.p) 
    {
        if(p1.b==p2.b) return p1.s<p2.s;
        return p1.b>p2.b;
    }
    return p1.p>p2.p;
}
void solve() 
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i].s;
    
    for(int i=1;i<=m;i++) 
    {
        cin>>t[i].s;
        t[i].i=i;
    }
    sort(t+1,t+1+m,cmp);
    
    for(int i=1;i<=m;i++) cin>>b[i];
    
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=m;j++) 
        {
            cin>>a[i][j];
            sum+=a[i][j]*b[j];
        }
        p[i].p=sum;
        p[i].i=i;
        for(int j=1;j<=m;j++) 
        {
            p[i].b.push_back(a[i][t[j].i]);
        }
    }
    sort(p+1,p+1+n,cmp1);
    for(int i=1;i<=n;i++) cout<<p[i].i<<" \n"[i==n];
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