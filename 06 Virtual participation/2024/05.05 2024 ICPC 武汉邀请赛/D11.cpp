#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
int a[N];
int p[N];
int res[N][2*N];
void solve()
{
    int n;
	cin>>n;
	for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n;j++)
        {
            int l=max(1ll,i-j);
            int r=min(i+j,n);
            res[i][j]=max(p[i]-p[l-1],p[r]-p[i-1]);
        }
    }
    for(int j=1;j<=2*n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i+1<=n) res[i][j]=max(res[i][j],res[i+1][j-1]);
            if(i-1>=1) res[i][j]=max(res[i][j],res[i-1][j-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int ans1=0;
        for(int j=1;j<=2*n;j++) ans1^=j*res[i][j];
        ans^=(ans1+i);
    }
	cout<<ans<<"\n";
}
signed main()
{
	int T=1;
	// cin>>T;
	while(T--) solve();
}