#include <bits/stdc++.h>
using namespace std;
long long i,j,n,m=1e18,ans=-1e18,W,w[1000010],d[1000010];
int main()
{
    cin>>n>>W;
    for(i=1;i<=n;i++) cin>>w[i],w[i]+=w[i-1];
    for(i=1;i<=n;i++) cin>>d[i],d[i]+=d[i-1];
    for(j=0,i=1;i<=n;i++)
    {
        while(w[i]-w[j]>=W) m=min(m,d[j]),j++;
        ans=max(ans,d[i]-m);
    }
    cout<<ans;
}