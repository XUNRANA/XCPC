#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int id;
    int s;
    int f;
}g[31];
bool cmp(node g1,node g2)
{
    
    if(g1.s==g2.s) 
    {
        if(g1.f==g2.f) return g1.id<g2.id;
        return g1.f>g2.f;
        
    }
    return g1.s>g2.s;
}
int s[]={0,25,21,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=30;i++) 
    {
        g[i].id=i;
        g[i].s=0;
        g[i].f=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=20;j++)
        {
            int c,p;
            cin>>c>>p;
            g[c].s+=s[p];
            g[c].f=1;
        }
    }
    sort(g+1,g+1+30,cmp);

    for(int i=1;g[i].f;i++)
    cout<<g[i].id<<" "<<g[i].s<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}