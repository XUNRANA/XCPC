#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b;
    cin>>a>>b;
    double ans1=(exp(-b)*cos(a)+exp(b)*cos(-a))/2.0;
    double ans2=(exp(b)*sin(-a)+exp(-b)*sin(a))/2.0;
    printf("%.10f %.10f ",ans1,ans2);
    double ans4=(exp(-b)*cos(a)-exp(b)*cos(-a))/(-2.0);
    double ans3=(exp(-b)*sin(a)-exp(b)*sin(-a))/2.0;
    printf("%.10f %.10f\n",ans3,ans4);
    // cout<<ans1<<" "<<ans2<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
