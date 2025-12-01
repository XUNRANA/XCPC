#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
    int f;
    int a;
}a[100010];
bool cmp(node a1,node a2)
{
    if(a1.f==a2.f) return a1.a<a2.a;
    return a1.f<a2.f;
}
bool cmp1(node a1,node a2)
{
    return a1.a<a2.a;
}
void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++) cin>>a[i].a;
    
    int mi=a[n].a;
    a[n].f=0;
    for(int i=n-1;i>=1;i--)
    if(a[i].a>mi) 
    {
        a[i].a++;
        a[i].f=1;
    }
    else 
    {
        mi=min(mi,a[i].a);
        a[i].f=0;
    }
    
    sort(a+1,a+1+n,cmp);
    // for(int i=1;i<=n;i++) cout<<a[i].a<<" "<<a[i].f<<"\n";
    
    mi=1e9+1;
    for(int i=n;i>=1;i--) 
    if(a[i].f) mi=a[i].a;
    else if(a[i].a>mi) a[i].a++;
    
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++) cout<<a[i].a<<" \n"[i==n];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

