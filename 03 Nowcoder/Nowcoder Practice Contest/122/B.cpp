#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],f;
int main()
{
    cin>>t;
    while(t--)
    {
        f=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        map<int,int>m;
        for(int i=1;i<=n;i++)
        {
            if(m.count(a[i])&&m[a[i]]!=b[i]) 
            {
                f=1;
                break;
            }
            else m[a[i]]=b[i];
        }
                   if(f==1) cout<<"No\n";
                   else cout<<"Yes\n";
    }
}