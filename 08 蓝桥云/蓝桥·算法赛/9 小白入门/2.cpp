#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        char ch;
        cin>>ch;
        ans+=ch-'0';
    }
    for(int i=0;i<=k;i++) 
    if(ans==i*2+(k-i)*3)
    {
        cout<<k-i<<" "<<i<<"\n";
        return 0;
    }
}
