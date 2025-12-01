#include <bits/stdc++.h>
using namespace std;
int n,mi,mx,a[200010];
int main()
{
    mx=-1e9;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,a[i]);
        cout<<mx-a[i]<<" ";
    }
    
}