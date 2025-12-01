#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int a,b,i,ans;
}a[100010];
bool cmp(node a1,node a2)
{
    if(a1.a==a2.a) return a1.b<a2.b;
    return a1.a<a2.a;
}
bool cmpi(node a1,node a2)
{
    return a1.i<a2.i;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].a,a[i].i=i;
    for(int i=1;i<=n;i++) cin>>a[i].b;
    sort(a+1,a+1+n,cmp);
    a[1].ans=0;
    int pre=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i].a!=a[i-1].a) pre=i-1;

        if(a[i].a==a[1].a) a[i].ans=0;
        else 
        {
            if(a[i].b>=pre) a[i].ans=pre;
            else a[i].ans=max(2*a[i].b-pre,0ll);
        }
    }
    sort(a+1,a+1+n,cmpi);
    for(int i=1;i<=n;i++) cout<<a[i].ans<<" \n"[i==n];
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
