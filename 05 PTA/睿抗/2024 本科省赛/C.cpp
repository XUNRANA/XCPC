#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
char a[1010][1010];
int f[1010][1010];
int ans[1010][1010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='m')
            {
                for(int k=0;k<8;k++)
                {
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    f[ni][nj]=1;
                }
            }
            else if(a[i][j]=='c')
            {
                for(int k=0;k<8;k++)
                {
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    ans[ni][nj]=1;//ban
                }
            }
        }
    }

    int f1=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='w'&&!f[i][j])
            {
                for(int k=0;k<8;k++)
                {
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(a[ni][nj]=='.'&&!ans[ni][nj])
                    {
                        cout<<ni<<" "<<nj<<"\n";
                        f1=1;
                    }
                }
            }
        }
    }
    if(!f1) cout<<"Too cold!\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
