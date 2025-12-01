#include <bits/stdc++.h>
using namespace std;
int main() 
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    double a,b,n;
    cin>>a>>b>>n;
    double in=1.0/n;
    double ga=tgamma(in);
    double d=n*n*tgamma(1.0+2.0*in);
    double res=4.0*a*b*ga*ga/d;
    printf("%.6lf",res);
    return 0;
}