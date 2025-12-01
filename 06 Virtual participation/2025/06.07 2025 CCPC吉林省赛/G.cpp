#include <bits/stdc++.h>
using namespace std;
#define int long long




int n;
int a[7];
int b[7];
int fx()
{
    //剪刀 石头 布
    int ans=0;
    int t=min(a[1],a[6]);
    ans+=t;
    a[1]-=t;
    a[6]-=t;

    t=min(a[2],a[4]);
    ans+=t;
    a[2]-=t;
    a[4]-=t;
    
    t=min(a[3],a[5]);
    ans+=t;
    a[3]-=t;
    a[5]-=t;
    
    int ans2=0;
    for(int i=1;i<=3;i++) 
    {
        ans2+=min(a[i],a[i+3]);
        a[i]=a[i+3]=abs(a[i]-a[i+3]);
    }
    return ans-(n-(ans+ans2));
}

void solve()
{
    cin>>n;
    for(int i=1;i<=6;i++) cin>>a[i];
    swap(a[1],a[2]);
    swap(a[4],a[5]);

    for(int i=1;i<=6;i++) b[i]=a[i];
    int res1=fx();
    
    for(int i=1;i<=6;i++) a[i]=b[i];
    for(int i=1;i<=3;i++) swap(a[i],a[i+3]);
    int res2=fx();
    cout<<res1<<" "<<-res2<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}