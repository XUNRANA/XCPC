#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,c;
int x[100010];
int y[100010];
double gety(double x)
{
    return (-a*x-c)*1.0/b;
}
double getx(double y)
{
    return (-b*y-c)*1.0/a;
}
double dis(double x,double y,int x1,int y1)
{
    return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

double fx(double x1)
{
    double y1=gety(x1);
    double m=0;
    for(int i=1;i<=n;i++) m=max(m,dis(x1,y1,x[i],y[i]));
    return m;
}

double fy(double y1)
{
    double x1=getx(y1);
    double m=0;
    for(int i=1;i<=n;i++) m=max(m,dis(x1,y1,x[i],y[i]));
    return m;
}

void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];


    cin>>a>>b>>c;

    if(!a)//二分x
    {
        double L=-1e4,R=1e4;
        const double EPS=1e-9;
        while(R-L>EPS)
        {
            double m1=L+(R-L)/3;
            double m2=R-(R-L)/3;
            // cout<<L<<" "<<R<<"\n";
            if(fx(m1)<=fx(m2)) R=m2;//f(m1)<f(m2) 极大值时刚好相反 
            else L=m1;
        }
        // cout<<L<<"\n";
        printf("%.18f\n",sqrt(fx(L)));
        // cout<<fx(L)<<"\n";//f（L）即为函数极小值

    }
    else if(!b)//二分y
    {
        double L=-1e4,R=1e4;
        const double EPS=1e-9;
        while(R-L>EPS)
        {
            double m1=L+(R-L)/3;
            double m2=R-(R-L)/3;
            // cout<<L<<" "<<R<<"\n";
            if(fy(m1)<=fy(m2)) R=m2;//f(m1)<f(m2) 极大值时刚好相反 
            else L=m1;
        }
        // cout<<L<<"\n";
        printf("%.18f\n",sqrt(fy(L)));
        // cout<<fx(L)<<"\n";//f（L）即为函数极小值
    }
    else
    {
        double L=-1e4,R=1e4;
        const double EPS=1e-9;
        while(R-L>EPS)
        {
            double m1=L+(R-L)/3;
            double m2=R-(R-L)/3;
            // cout<<L<<" "<<R<<"\n";
            if(fx(m1)<=fx(m2)) R=m2;//f(m1)<f(m2) 极大值时刚好相反 
            else L=m1;
        }
        // cout<<L<<"\n";
        printf("%.18f\n",sqrt(fx(L)));
        // cout<<fx(L)<<"\n";//f（L）即为函数极小值
    }



}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}