#include <bits/stdc++.h>
using namespace std;
void solve()
{
    double a,b,c,d,p1,p2,r1,r2;
    cin>>r1>>p1>>r2>>p2;
    a=r1*cos(p1);
    b=r1*sin(p1);
    c=r2*cos(p2);
    d=r2*sin(p2);
    double A=a*c-b*d;
    double B=a*d+b*c;
    if(fabs(A)<0.005) printf("0.00");
	else printf("%.2f",A);
	if(fabs(B)<0.005) printf("+0.00i");
	else printf("%+.2fi",B);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
