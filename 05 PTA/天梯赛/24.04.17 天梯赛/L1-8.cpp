#include <bits/stdc++.h>
using namespace std;
int n,m,h[11],k,a[11][11],c[110];
string s[110];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        getline(cin,s[i]);
    }
    for(int i=1;i<=m;i++) cin>>h[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++) cin>>c[i];
}
