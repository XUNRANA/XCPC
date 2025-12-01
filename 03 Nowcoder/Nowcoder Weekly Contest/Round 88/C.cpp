#include <bits/stdc++.h>
using namespace std;

double x1,x2,x3,y11,y2,y3;
bool ck(double a,double b,double c)
{
    return 2*a==b+c||2*b==a+c||2*c==a+b;
}
void solve()
{
    cin>>x1>>y11>>x2>>y2>>x3>>y3;
    if(ck(x1,x2,x3)||ck(y11,y2,y3)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
