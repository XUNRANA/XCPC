#include <bits/stdc++.h>
using namespace std;
int ans[100010],j=1,n,cnt;
double t;
struct node
{
    double v;
    int i;
}a[7];
bool cmp(node a1,node a2)
{
    return a1.v>a2.v;
}
int main()
{
    cin>>n;
    for(int i=1;i<=6;i++) cin>>a[i].v,a[i].i=i;
    sort(a+1,a+1+6,cmp);
    for(int i=1;i<=n-6;i++)
    {
        cin>>t;
        if(t>a[6].v) 
        {
            ans[j++]=a[6].i;
            cnt++;
            a[6].v=t;
            a[6].i=i+6;
            sort(a+1,a+1+6,cmp);
        }
        else ans[j++]=0;
    }
    cout<<cnt+6<<"\n0";
    for(int i=1;i<=5;i++) cout<<" 0";
    for(int i=1;i<j;i++) cout<<" "<<ans[i];
}