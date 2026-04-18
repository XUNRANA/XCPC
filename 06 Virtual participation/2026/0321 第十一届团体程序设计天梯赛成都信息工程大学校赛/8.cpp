#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m,k;
struct node
{
    int i;
    int s;
    int sum;
    vector<int>b;
    int cnt;//-1
}a[400010];
bool cmp(node a1,node a2)
{
    return a1.s<a2.s;
}
bool cmpi(node a1,node a2)
{
    return a1.i<a2.i;
}
void print()
{
    cout<<"Yes\n";
    sort(a+1,a+1+n,cmpi);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<a[i].b[j]<<" \n"[j==m];
    }
}
void solve()
{
    
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s;
        a[i].i=i;
        a[i].sum=a[i].cnt=0;
        a[i].b.clear();
        a[i].b.resize(m+1);
        for(int j=1;j<=m;j++)
        {
            cin>>a[i].b[j];
            if(a[i].b[j]==-1) a[i].cnt++;
            else a[i].sum+=a[i].b[j];
        }
    }

    sort(a+1,a+1+n,cmp);
    int mx1=0;
    int mx2=0;
    for(int i=1;i<=n&&a[i].s==a[1].s;i++)
    {
        for(int j=1;j<=m;j++) if(a[i].b[j]==-1) a[i].b[j]=0;
        mx1=max(mx1,a[i].sum);
        mx2=max(mx2,a[i].sum);
    }

    
    for(int i=1;i<=n;i++)
    {
        if(a[i].s==a[1].s) continue;

        if(a[i].s!=a[i-1].s) mx1=mx2;
        
        
        if(a[i].sum<=mx1)
        {
            if(a[i].cnt*k+a[i].sum<=mx1)
            {
                cout<<"No\n";
                return ;
            }
            int ss=mx1+1-a[i].sum;
            for(int j=1;j<=m;j++) 
            if(a[i].b[j]==-1)
            {
                if(ss>=k)
                {
                    a[i].b[j]=k;
                    ss-=k;
                }
                else
                {
                    a[i].b[j]=ss;
                    ss-=ss;
                }
            }
            mx2=max(mx2,mx1+1);
        }
        else
        {
            for(int j=1;j<=m;j++) 
            if(a[i].b[j]==-1) a[i].b[j]=0;
            mx2=max(mx2,a[i].sum);
        }
        
    }
    // for(int i=1;i<=n;i++) cout<<a[i].s<<" "<<a[i].sum<<" "<<a[i].cnt<<"\n";
    print();
}
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}