#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,x,y;
    cin>>n>>x>>y;
    if(x*x+y*y<=n*n) 
    {
        cout<<"Yes\n0\n";   
    }
    else if((x-n)*(x-n)+y*y<=n*n)
    {
        cout<<"Yes\n"<<n<<"\n";
    }
    else cout<<"No\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
