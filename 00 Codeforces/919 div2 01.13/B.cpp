#include <bits/stdc++.h>
using namespace std;
long long t,n,k,x,ans,c[200010];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x;
        ans=-1e18;
        for(int i=1;i<=n;i++) cin>>c[i];
        sort(c+1,c+1+n);
        for(int i=1;i<=n;i++) c[i]+=c[i-1];
        for(int i=n-k,j;i<=n;i++)
        {
        	j=max(i-x,0ll);
        	ans=max(ans,-(c[i]-c[j])+c[j]);
		}
		cout<<ans<<"\n";
    } 
}
