#include <bits/stdc++.h>
using namespace std;
int n,k,t,s,a[110];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(k--)
    {
        cin>>t;
        s+=a[t];
    }
    cout<<s;
}