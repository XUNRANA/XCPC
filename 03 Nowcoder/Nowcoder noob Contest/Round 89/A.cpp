#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,mi,mx,t;
    cin>>n>>m;
    mi=m+1;
    mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        mx=max(mx,t);
        mi=min(mi,t);
    }
    if(mx-mi+1<m) cout<<"Yes\n";
    else cout<<"No\n";
}