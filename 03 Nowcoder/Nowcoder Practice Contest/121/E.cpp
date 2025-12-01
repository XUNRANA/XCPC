#include <bits/stdc++.h>
using namespace std;
#define N 5050
int t,n,a,b,p[2*N],x[N],y[N];
long double dp[N][N],s,mx;
bool cmp(int a,int b) {return a>b;}
int main()
{
    cin>>t;
    while(t--)
    {
        s=mx=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i],s+=p[i];
        cin>>a;
        for(int i=1;i<=a;i++) cin>>x[i],x[i]=100-x[i];
        cin>>b;
        for(int i=1;i<=b;i++) cin>>y[i];
        sort(p+1,p+1+n,cmp);
        sort(x+1,x+1+a,cmp);
        sort(y+1,y+1+b,cmp);
        for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) dp[i][j]=0;
        for(int i=0;i<=a;i++) for(int j=0;j<=b;j++)
        {
            if(j>0) dp[i][j]=fmaxl(dp[i][j-1]+min(p[i+j],y[j]),dp[i][j]);
            if(i>0) dp[i][j]=fmaxl(dp[i-1][j]+0.01*p[i+j]*x[i],dp[i][j]);
            mx=fmaxl(mx,dp[i][j]);
        }
        printf("%.15llf\n",s-mx);
    }
}