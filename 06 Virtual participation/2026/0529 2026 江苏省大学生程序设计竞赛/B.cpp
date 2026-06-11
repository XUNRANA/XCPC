#include <bits/stdc++.h>
using namespace std;

int cnt=999990000;
void solve()
{
    int n;
    n = cnt++;
    // cin>>n;
    int x=sqrt(n);
    int ans=abs(x-(n-x*x));
    // 2 * sqrt(sqrt(n))
    for(int i = -550;i <= 0;i++){
        for(int j = i;j <= 550;j++){
            int a = x + i, b = x + j;
            int c = n - a * b;
            if(a>=0&&b>=0&&c>=0)
            {
                ans=min(ans,abs(max({a,b,c})-min({a,b,c})));
            }
        }
    }
    // for(int i=0;i<=1000&&x-i>=0;i++)
    // {
    //     for(int j=0;j<=1000&&n-(x-i)*(x+j)>=0;j++)
    //     {
    //         int a=x-i;
    //         int b=x+j;
    //         int c=n-a*b;
    //         if(a>=0&&b>=0&&c>=0)
    //         {
    //             ans=min(ans,abs(max({a,b,c})-min({a,b,c})));
    //         }
    //     }
    // }
    cout<<cnt-1<<" "<<ans<<"\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}