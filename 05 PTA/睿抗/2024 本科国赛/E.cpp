#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[110][110];
int s[110][110];
int s1[110][110];
int is[110][110];
void init()
{
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        is[i][j]=(a[i][j]==0);
        s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1]+is[i][j];
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
}
int g1(int x1,int y1,int x2,int y2)
{
    return s1[x2][y2]-s1[x1-1][y2]-s1[x2][y1-1]+s1[x1-1][y1-1];
}
int g2(int x1,int y1,int x2,int y2)
{
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int ax1,ax2,ay1,ay2;
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];


    int sum=0;
    while(1)
    {
        int ans=0;
        init();
        for(int x1=1;x1<=n;x1++)
        {
            for(int y1=1;y1<=n;y1++)
            {
                for(int x2=x1;x2<=n;x2++)
                {
                    for(int y2=y1;y2<=n;y2++)
                    {
                        if(g1(x1,y1,x2,y2)) continue;
                        if(g2(x1,y1,x2,y2)>ans)
                        {
                            ans=g2(x1,y1,x2,y2);
                            ax1=x1;
                            ay1=y1;
                            ax2=x2;
                            ay2=y2;
                        }
                    }
                }
            }
        }
        if(!ans) break;
        sum+=ans;
        printf("(%d, %d) (%d, %d) %d\n",ay1,ax1,ay2,ax2,ans);
        for(int i=ax1;i<=ax2;i++) 
        {
            for(int j=ay1;j<=ay2;j++) 
            {
                a[i][j]=0;
            }
        }

        for(int i=1;i<=ax1;i++)
        {
            for(int j=ay1;j<=ay2;j++)
            {
                a[i+ax2-ax1+1][j]=a[i][j];
                a[i][j]=0;
            }
        }
    }
    printf("%d\n",sum);
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}