#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int i,p,ti,tp;
}a[100010];

bool cmp(node a1,node a2)
{
    return a1.p<a2.p;
}
bool cmp1(node a1,node a2)
{
    return a1.i<a2.i;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].p;
        a[i].i=i;
        a[i].tp=0;
    }
    sort(a+1,a+1+n,cmp);
    a[1].ti=a[2].i;
    a[n].ti=a[n-1].i;
    for(int i=2;i<=n-1;i++)
    {
        if(a[i].p-a[i-1].p<=a[i+1].p-a[i].p) a[i].ti=a[i-1].i;
        else a[i].ti=a[i+1].i;
    }

    for(int i=1;i<=n;i++)
    if(i+1<=n&&a[i+1].ti==a[i].i&&a[i].ti==a[i+1].i)
    {
        a[i].tp=a[i+1].tp=(a[i].p+a[i+1].p)/2;
        i++;
    }
    else if(i-1>=1&&a[i].ti==a[i-1].i&&a[i-1].tp)
    {
        a[i].tp=a[i-1].tp;
    }

    for(int i=n;i>=1;i--)
    if(i+1<=n&&a[i].ti==a[i+1].i&&a[i+1].tp)
    {
        a[i].tp=a[i+1].tp;
    }

    sort(a+1,a+1+n,cmp1);

    for(int i=1;i<=n;i++) cout<<a[i].tp<<" ";
    cout<<"\n";
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
