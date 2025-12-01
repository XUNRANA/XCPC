#include <iostream>
using namespace std;
#define int long long
int a[200010],b[200010],t[200010],h[200010],n,x,ans;
int lowbit(int x)
{
    return x&-x;
}
int sum(int *t,int i)
{
    int res=0;
    while(i)
    {
        res+=t[i];
        i-=lowbit(i);
    }
    return res;
}
void add(int *t,int i,int x)
{
    while(i<=n)
    {
        t[i]+=x;
        i+=lowbit(i);
    }
} 
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x,h[x]=i;
    for(int i=1;i<=n;i++) cin>>x,a[i]=h[x];
    for(int i=1;i<=n;i++)
    {
        add(t,a[i],1);
        add(b,a[i],a[i]);
        ans+=a[i]*sum(t,a[i]-1)-sum(b,a[i]-1);
    }
    cout<<ans;
}
