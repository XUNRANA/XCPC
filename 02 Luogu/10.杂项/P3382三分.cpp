#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
double a[14];
double fx(double x)
{
    double s=0;
    for(int i=n;i>=0;i--)
    {
        int j=i;
        double y=a[i];
        while(j--) y*=x;
        s+=y; 
    }
    return s;
}
void solve()
{
    double L,R;
    cin>>n>>L>>R;
    for(int i=n;i>=0;i--) cin>>a[i];
    const double EPS=1e-9;
    while(R-L>EPS)
    {
        // cout<<L<<" "<<R<<"\n";
        double m1=L+(R-L)/3;
        double m2=R-(R-L)/3;
        if(fx(m1)>fx(m2)) R=m2;//f(m1)<f(m2) 极大值时刚好相反 
        else L=m1;
    }
    printf("%.5f\n",L);
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}