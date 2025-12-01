#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[200010][30];
int a[200010];
int s;
bool ck(int l,int r)
{
    int x=0;
    for(int i=0;i<30;i++)
    {
        if(p[r][i]-p[l-1][i]!=0)
        {
            x+=1ll<<i;
        }
    }
    return x==s;
}
void solve()
{
    int n;
    cin>>n;
    s=0;
    for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i],s|=a[i];
    for(int i=1;i<=2*n;i++) 
    {
        int x;
        x=a[i];
        for(int j=0;j<30;j++) 
        if(x>>j&1) 
        {
            p[i][j]=p[i-1][j]+1;        
        }
        else p[i][j]=p[i-1][j];
    }

    int ans=0;
    for(int i=1,j=1;j<=n&&i<=2*n;i++)
    {
        while(j<=n&&ck(j,i))
        {
            ans=max(ans,i-j);
            j++;
        }
    }
    int sum=0,cnt=0,j=1;
    while(sum<ans)
    {
        sum+=j;
        j++;
        cnt++;
    }
    cout<<cnt<<"\n";
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