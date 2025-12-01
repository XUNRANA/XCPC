#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[1010][1010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            set<char>s;
            s.insert(a[i][j]);
            s.insert(a[i+1][j]);
            s.insert(a[i][j+1]);
            s.insert(a[i+1][j+1]);
            if(s.find('y')!=s.end()&&s.find('o')!=s.end()&&s.find('u')!=s.end()) ans++;
        }
    }
    cout<<ans<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
