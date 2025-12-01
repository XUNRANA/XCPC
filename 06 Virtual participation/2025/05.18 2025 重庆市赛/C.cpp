#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
void solve()
{
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<"1 2\n2 1\n";
        return ;
    }
    else if(n==3)
    {
        cout<<"1 2 3\n1 2 3\n3 3 3\n";
        return ;        
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1) a[i][j]=j;
                else 
                {
                    a[i][j]=(a[i-1][j]-(i-1)+n-1)%n+1;
                }
            }
        }   
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<a[i][j]<<" \n"[j==n];
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


