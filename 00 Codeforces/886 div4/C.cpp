#include <bits/stdc++.h>
using namespace std;
char a[9][9];
void solve()
{
    for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) cin>>a[i][j];

    for(int j=1;j<=8;j++)
    {
        string ans="";
        for(int i=1;i<=8;i++) if(a[i][j]!='.') ans+=a[i][j];
        if(ans!="")
        {
            cout<<ans<<"\n";
            return ;
        }
    }
    
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
