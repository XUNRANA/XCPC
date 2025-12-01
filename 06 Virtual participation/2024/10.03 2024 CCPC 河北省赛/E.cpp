#include <bits/stdc++.h>
using namespace std;
int dx[5];
int dy[5];
int x[1010];
int y[1010];
double dp[1010][8];
double ans[1010][1010];
double dis1(int i,int j)//学生-食堂
{
    return sqrt((x[i]-dx[j])*(x[i]-dx[j])+(y[i]-dy[j])*(y[i]-dy[j]));
}
double dis2(int i,int j)//食堂-食堂
{
    return sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
}
void solve()
{
    int n,m,k,b,e;
    cin>>n>>m>>k;
    cin>>b>>e;
    for(int i=0;i<4;i++) cin>>dx[i]>>dy[i];
    for(int i=1;i<=k;i++) cin>>x[i]>>y[i];

    for(int i=1;i<=k;i++)
    {
        dp[i][0]=0;
        dp[i][1]=min({dis1(i,0)+dis2(0,3),dis1(i,1)+dis2(1,3),dis1(i,2)+dis2(2,3)});

        //0 1  
        //0 2
        //1 2

        dp[i][2]=min({dis1(i,0)+dis2(0,1)+dis2(1,3),dis1(i,0)+dis2(0,2)+dis2(2,3),dis1(i,1)+dis2(1,2)+dis2(2,3),dis1(i,1)+dis2(1,0)+dis2(0,3),dis1(i,2)+dis2(2,0)+dis2(0,3),dis1(i,2)+dis2(2,1)+dis2(1,3)});

        dp[i][3]=1e18;
        vector<int>a;
        a.push_back(0);
        a.push_back(1);
        a.push_back(2);
        do
        {
            // 0 1 2
            double res=dis1(i,a[0]);
            for(int j=1;j<3;j++)
            {
                res+=dis2(a[j-1],a[j]);
            }
            res+=dis2(a.back(),3);
            dp[i][3]=min(dp[i][3],res);
        }while(next_permutation(a.begin(),a.end()));
    }
    int c=(n+b-1)/b;
    c=max(c,(m+e-1)/e);    
    for(int i=0;i<=k;i++) for(int j=1;j<=c;j++) ans[i][j]=1e18;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=c;j++)
        {
            ans[i][j]=min(ans[i][j],ans[i-1][j]+dp[i][0]);
            if(j-1>=0) ans[i][j]=min(ans[i][j],ans[i-1][j-1]+dp[i][1]);
            if(j-2>=0) ans[i][j]=min(ans[i][j],ans[i-1][j-2]+dp[i][2]);
            if(j-3>=0) ans[i][j]=min(ans[i][j],ans[i-1][j-3]+dp[i][3]);
        }
    }
    printf("%.10f\n",ans[k][c]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
