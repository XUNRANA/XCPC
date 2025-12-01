#include <bits/stdc++.h>
using namespace std;
#define int long long
char ans[110][110];
void solve()
{
    int n,k;
    cin>>n>>k;
    int d=n*n-k;//留下的
    if(d==0)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<'R';
    }
    else if(d==1) cout<<"NO\n";
    else 
    {
        d-=2;
        ans[1][1]='D';
        ans[2][1]='U';

        for(int i=1;i<=2;i++)
        for(int j=2;j<=n;j++)
        if(d)
        {
            ans[i][j]='L';
            d--;
        }
        else ans[i][j]='R';
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d)
                {
                    if(j==1) ans[i][j]='U';
                    else ans[i][j]='L';
                    d--;
                }
                else ans[i][j]='R';
            }
        }

        cout<<"YES\n";
        for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<ans[i][j];
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
