#include <bits/stdc++.h>
using namespace std;
#define int long long
double dis(int a,int b,int c,int d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    printf("%.10f\n",min(dis(-a,b,c,d),dis(a,-b,c,d)));

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}