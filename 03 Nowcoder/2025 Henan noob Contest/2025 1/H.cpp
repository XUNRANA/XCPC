#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans[1010][1010];
void solve()
{
    int n;
    cin>>n;
    int left=0,right=n-1,top=0,bottom=n-1;
    int num=n*n;
    int l,t,r,b;
    while(num)
    {
        l=left;
        while(l<=right) ans[top][l++]=num--;
        top++;
        t=top;
        while(t<=bottom) ans[t++][right]=num--;
        right--;
        r=right;
        while(r>=left) ans[bottom][r--]=num--;
        bottom--;
        b=bottom;
        while(b>=top) ans[b--][left]=num--;
        left++;
    }

    if(n%2==0)
    {
        for(int i=n;i>=1;i--,cout<<"\n") for(int j=1;j<=n;j++) cout<<ans[i-1][j-1]-1<<" ";
    }
    else 
    {
        for(int i=1;i<=n;i++,cout<<"\n") for(int j=n;j>=1;j--) cout<<ans[i-1][j-1]-1<<" ";

    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}