#include <bits/stdc++.h>
using namespace std;
int main()
{
    double r,a,b,h;
    cin>>r>>a>>b>>h;
    if(2*r<=b) cout<<"Drop\n";
    else
    {
        cout<<"Stuck\n";
        double s=(a+b)*h/2-sqrt(h*h+(a-b)*(a-b)/4)*r;
        double x=(2*s-h*a)/(b-a);
        printf("%.10f\n",x);
    }
}
