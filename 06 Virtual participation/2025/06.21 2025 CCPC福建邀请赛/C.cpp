#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int b[100010];
int c[100010];
bool ck(int x)
{
    vector<int>d,c;
    a[0]=1e9;
    a[n+1]=1e9;
    for(int i=1;i<=n;i++) 
    {
        int y=(a[i]>=x);
        if(y==1&&(a[i-1]<x&&a[i+1]<x)) y=0;
        if(d.empty()||y!=d.back())
        {
            d.push_back(y);
            c.push_back(1);
        }
        else 
        {
            c.back()++;
        }
    }

    for(int i=0;i<d.size();i++)
    if(d[i]==0) 
    {
        if(c[i]&1) c[i]=1;
        else c[i]=2;
    }
    // 0 0 1 0 1 0 0 
    int s0=0,s1=0;
    for(int i=0;i<d.size();i++)
    if(d[i]==0) s0+=c[i];
    else s1+=c[i];

    return s1>s0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);

    int l=1,r=n;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(b[m])) l=m+1;
        else r=m-1;
    }
    // l=min(l,n);
    l--;
    cout<<b[l]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}