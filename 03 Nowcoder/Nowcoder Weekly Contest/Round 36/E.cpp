#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[1010][1010];
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n==3&&m==3)
    {
        cout<<"aac\nbba\nacc\n";
        return ;
    }
    for(int i=1;i<=n;i++) a[i][1]=(i&1? 'a':'b');
    for(int j=2;j<=m-1;j++) a[n][j]=(j&1? 'c':'d');
    a[n][m]=a[n][m-1];
    for(int i=1;i<=n-1;i++) for(int j=2;j<=m;j++) a[i][j]=a[i][j-1];
    a[n-1][m]=(a[n-1][m-1]=='a'? 'b':'a');
    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

