#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010];
int c[100010][3];
void solve() 
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        c[i][0]=1;
        while(x%2==0)
        {
            c[i][0]*=2;
            x/=2;
        }

        x=a[i];
        c[i][1]=1;
        while(x%2==0&&x/2!=a[i-1])
        {
            c[i][1]*=2;
            x/=2;
        }


        if(x%2==0&&x/2==a[i-1]) 
        {
            c[i][1]--;
            while(x%2==0)
            {
                c[i][1]*=2;
                x/=2;
            }
            c[i][1]++;
        } 

        x=a[i];
        c[i][2]=1;
        while(x%2==0&&x/2!=a[i+1])
        {
            c[i][2]*=2;
            x/=2;
        }
        

        if(x%2==0&&x/2==a[i+1]) 
        {
            c[i][2]--;
            while(x%2==0)
            {
                c[i][2]*=2;
                x/=2;
            }
            c[i][2]++;
        } 

        c[i][1]+=c[i-1][1];
        c[i][2]+=c[i-1][2];
    }


    for(int i=1;i<=n;i++)//枚举中间位置
    {
        ans=max(ans,c[i][0]+c[i-1][2]-c[0][2]+c[n][1]-c[i][1]);
    }


    if(ans>=k) cout<<"YES\n";
    else cout<<"NO\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}