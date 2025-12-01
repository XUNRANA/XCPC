#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    double a,b;
}a[1010];
bool cmp(node a1,node a2)
{
    return a1.b*a2.a>a2.b*a1.a;
}
void solve()
{
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i].a;
    for(int i=1;i<=n;i++) cin>>a[i].b;
    sort(a+1,a+1+n,cmp);
    int s=0;
    double ans;
    for(int i=1;i<=n;i++)
    {
        if(s+a[i].a<=d) 
        {
            s+=a[i].a;
            ans+=a[i].b;
        }
        else
        {
            ans+=1.0*(d-s)*a[i].b/a[i].a;
            break;
        }
    }
    printf("%.2f",ans);
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

