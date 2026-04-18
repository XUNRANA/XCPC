#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];
int r[1010];
int c[1010];
struct node
{
    int x,y,v;
}b[1000010];
bool cmp(node b1,node b2)
{
    return b1.v>b2.v;
}
void solve()
{
    int n,m,k1;
    cin>>n>>m>>k1;
    int k=1;
    for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
    {
        cin>>a[i][j];
        b[k].x=i;
        b[k].y=j;
        b[k].v=a[i][j];
        k++;
    }
    sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        // cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].v<<"\n";
        if(r[b[i].x]||c[b[i].y]) continue;
        r[b[i].x]=c[b[i].y]=1;
        k1--;
        if(k1==0) break;
    }
    int f1=0;
    for(int i=1;i<=n;i++)
    {
        if(r[i]) continue;
        int f=0;
        if(f1) cout<<"\n";
        for(int j=1;j<=m;j++)
        {
            if(c[j]) continue;
            if(f) cout<<" ";
            cout<<a[i][j];
            f=1;
        }
        f1=1;
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