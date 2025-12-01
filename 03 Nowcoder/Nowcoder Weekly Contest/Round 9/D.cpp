#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,ans,a[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    sort(a+1,a+1+n);
    if(s%n==0)
    {
        for(int i=1;i<=n;i++) if(a[i]<s/n) ans+=s/n-a[i];
        cout<<ans<<"\n";
    }
    else
    {
        int s1=0,s2=0,ans1,ans2,ans3,ans4;
        sort(a+1,a+1+n);
        
        int t=(s-a[1])/(n-1);
        for(int i=2;i<=n;i++) 
            if(a[i]<t) s1+=t-a[i];
            else if(a[i]>t) s2+=a[i]-t;
        ans1=max(s1,s2);
        s1=s2=0;
        t++;
        for(int i=2;i<=n;i++) 
            if(a[i]<t) s1+=t-a[i];
            else if(a[i]>t) s2+=a[i]-t;
        ans2=max(s1,s2);
        
        s1=s2=0;
        t=(s-a[n])/(n-1);
        for(int i=1;i<n;i++) 
            if(a[i]<t) s1+=t-a[i];
            else if(a[i]>t) s2+=a[i]-t;
        ans3=max(s1,s2);

        s1=s2=0;
        t++;
        for(int i=1;i<n;i++) 
            if(a[i]<t) s1+=t-a[i];
            else if(a[i]>t) s2+=a[i]-t;

        ans4=max(s1,s2);

        cout<<min({ans1,ans2,ans3,ans4});
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
