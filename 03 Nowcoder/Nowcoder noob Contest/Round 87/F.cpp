#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],b[200010],c[200010],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-2;i++) b[i]=a[i]^b[i-1];
    for(int i=n-1;i>=2;i--) c[i]=a[i]|c[i+1];
    for(int i=1;i<n-1;i++) ans=max(ans,b[i]+c[i+1]+a[n]);
    cout<<ans;
}