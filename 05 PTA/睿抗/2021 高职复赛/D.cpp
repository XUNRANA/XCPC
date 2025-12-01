#include <bits/stdc++.h>
using namespace std;

struct node
{
    string s;
    int r;
    int x;
}a[1010];
bool cmp(node a1,node a2)
{
    if(a1.x==a2.x) return a1.s<a2.s;
    return a1.x>a2.x;
}
int ss[]={0,30,50,60,80,100};
void solve()
{
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i].s>>a[i].x;
        if(a[i].x<=30) a[i].r=1;
        else if(a[i].x<=50) a[i].r=2;
        else if(a[i].x<=60) a[i].r=3;
        else if(a[i].x<=80) a[i].r=4;
        else a[i].r=5;
    }
    a[0].r=0;
    sort(a+1,a+1+n,cmp);
    int cnt=0;
    int pre=0;
    int p=1;
    for(int i=1;i<=n;i++)
    {
        if(!a[i].x) cout<<a[i].s<<"\n";
        else if(a[i].r!=a[i-1].r) 
        {
            pre+=(i-p);
            p=i;
            cnt=1;
            cout<<a[i].s<<" "<<a[i].r<<" "<<a[i].x<<"/"<<ss[a[i].r]<<" "<<cnt<<"/"<<n-pre<<"\n";
        }
        else
        {
            if(a[i].x!=a[i-1].x) cnt=i-p+1;
            cout<<a[i].s<<" "<<a[i].r<<" "<<a[i].x<<"/"<<ss[a[i].r]<<" "<<cnt<<"/"<<n-pre<<"\n";
        }    
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
