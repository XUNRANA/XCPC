
#include <bits/stdc++.h>
using namespace std;
#define int long long
const double pi=3.1415926535;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<double>a;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        a.push_back(atan2(y,x)+pi);
        a.push_back(atan2(y,x)+pi+pi+pi);
    }
    sort(a.begin(),a.end());
    double mx=0;
    for(int i=0;i<n;i++) mx=max(mx,a[i+k]-a[i]);
    printf("%.10lf\n",mx);
} 
 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}