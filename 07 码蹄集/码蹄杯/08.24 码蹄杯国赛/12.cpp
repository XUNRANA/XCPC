#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];
int b[110][110][4];
void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='#') b[i][j][0]=1;
            else b[i][j][0]=0;
        }
    }
    for(int f=1;f<4;f++)
    {
        int i1=1,j1=1;
        for(int j=1;j<=m;j++)
        for(int i=m;i>=1;i--)
        {
            b[i1][j1][f]=b[i][j][f-1];
            j1++;
            if(j1==m+1)
            {
                i1++;
                j1=1;
            }
        }
    }

    // for(int i=1;i<=m;i++,cout<<"\n")
    // for(int j=1;j<=m;j++) cout<<b[i][j][0]<<" ";


    // for(int i=1;i<=m;i++,cout<<"\n")
    // for(int j=1;j<=m;j++) cout<<b[i][j][1]<<" ";


    // for(int i=1;i<=m;i++,cout<<"\n")
    // for(int j=1;j<=m;j++) cout<<b[i][j][2]<<" ";


    // for(int i=1;i<=m;i++,cout<<"\n")
    // for(int j=1;j<=m;j++) cout<<b[i][j][3]<<" ";


    int f=0;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1) f=(f+1)%4;
        else 
        {
            int x,y;
            cin>>x>>y;
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    a[i+x-1][j+y-1]+=b[i][j][f];
                }
            }
        }
    }

    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}