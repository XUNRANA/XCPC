#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int b[200010];
int l[200010];
int r[200010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    int j=1;
    for(int i=1;i<=m;i++)
    {
        while(j<=n&&a[j]<b[i]) j++;
        l[i]=j++;
        j=min(j,n+1);
    }

    j=n;
    for(int i=m;i>=1;i--)
    {
        while(j>=1&&a[j]<b[i]) j--;
        r[i]=j--;
        j=max(j,0);
    }
    if(l[m]<=n)
    {
        cout<<"0\n";
        return ;
    }
    int ans=2e9;

    // for(int i=1;i<=m;i++) cout<<l[i]<<" \n"[i==m];
    
    // for(int i=1;i<=m;i++) cout<<r[i]<<" \n"[i==m];
    
    if(r[2]!=0) ans=min(ans,b[1]);
    
    if(l[m-1]!=n+1) ans=min(ans,b[m]);
    
    for(int i=2;i<=m-1;i++) if(l[i-1]<r[i+1]) ans=min(ans,b[i]);

    if(ans==2e9) ans=-1;
    cout<<ans<<"\n";
    
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
