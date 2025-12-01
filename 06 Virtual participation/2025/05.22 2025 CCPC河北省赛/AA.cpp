#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[3][200010];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=2;i++) 
    for(int j=1;j<=n;j++) 
    cin>>a[i][j];
    
    if(n==1) 
    {
        if(a[1][1]>a[2][1]) cout<<"Mandy\n";
        else if(a[1][1]<a[2][1]) cout<<"brz\n";
        else if(a[1][1]==a[2][1]) cout<<"draw\n";
    }
    else if(n==2)
    {
        if(a[1][1]+a[1][2]>a[2][1]+a[2][2]||a[1][1]+a[2][1]>a[1][2]+a[2][2]) cout<<"Mandy\n";
        else if(a[1][1]+a[1][2]==a[2][1]+a[2][2]||a[1][1]+a[2][1]==a[1][2]+a[2][2]) cout<<"draw\n";
        else cout<<"brz\n";
    }
    else
    {
        if(n&1)
        {
            //1 2 3 4 5
            int s=0;
            int s1=0;
            int s2=0;
            int f1=0;
            int f2=0;
            for(int i=1;i<=n;i++)
            {
                s+=a[1][i]+a[2][i];
                if(i<=n/2) s1+=a[1][i]+a[2][i];
                if(i>n/2+1) s2+=a[1][i]+a[2][i];
            }

            if(s1>s-s1) 
            {
                cout<<"Mandy\n";
                return ;
            }
            else if(s1==s-s1) f1=1;

            if(s2>s-s2)
            {
                cout<<"brz\n";
                return ;
            }
            else if(s2==s-s2) f2=1;

            

            int ss=0;
            for(int i=1;i<=n;i++) ss+=a[1][i];

            if(ss>s-ss)
            {
                if(!f2) cout<<"Mandy\n";
                else cout<<"draw\n";
            }
            else if(ss==s-ss) cout<<"draw\n";
            else 
            {
                if(!f1) cout<<"brz\n";
                else cout<<"draw\n";
            } 

        }
        else
        {
            int f1=0;
            int f2=0;
            int s1=0;
            int s=0;
            int s2=0;
            //4
            // 1 2 3 4
            for(int i=1;i<=n;i++) 
            {
                if(i<=n/2) s1+=a[1][i]+a[2][i];
                s+=a[1][i]+a[2][i];
                if(i>n/2+1) s2+=a[1][i]+a[2][i];
            }

            if(s1>s-s1) 
            {
                cout<<"Mandy\n";
                return ;
            }
            else if(s1==s-s1) f1=1;

            if(s2>s-s2)
            {
                cout<<"brz\n";
                return ;
            }
            else if(s2==s-s2) f2=1;

            int ss=0;
            for(int i=1;i<=n;i++) ss+=a[1][i];

            if(ss>s-ss)
            {
                if(!f2) cout<<"Mandy\n";
                else cout<<"draw\n";
            }
            else if(ss==s-ss) cout<<"draw\n";
            else 
            {
                if(!f1) cout<<"brz\n";
                else cout<<"draw\n";
            } 
        }
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
