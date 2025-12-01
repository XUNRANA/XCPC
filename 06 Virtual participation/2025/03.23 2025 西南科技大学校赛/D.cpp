#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int a,b;
}a[100010];
bool cmp(node a1,node a2)
{
    return a1.a>a2.a;
}
void solve()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].a;
    for(int i=1;i<=n;i++) cin>>a[i].b;
    sort(a+1,a+1+n,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i].a*(a[i].b-cnt);
        cnt++;
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
