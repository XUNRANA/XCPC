#include <bits/stdc++.h>
using namespace std;
int a[500][20];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z<240)
        {
            if(!a[x][y])
            {
                a[x][y]=1;
                a[x][0]++;
                cout<<y<<"\n";
            }
            else cout<<"0\n";
        }
        else
        {
            if(!a[x][y]&&a[x][0]<3)
            {
                a[x][0]++;
                a[x][y]=1;
                cout<<y<<"\n";
            }
            else cout<<"0\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}