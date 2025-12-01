#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[1010][1010];
int s[1010][1010];
void solve() 
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) s[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        s[x][y]+=x*y;
    }
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+s[i][j];
        }
    }

    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1++;
        y1++;
        x2--;
        y2--;
        if(x1>x2||y1>y2) cout<<"0\n";
        else cout<<p[x2][y2]+p[x1-1][y1-1]-p[x1-1][y2]-p[x2][y1-1]<<"\n";
    }
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