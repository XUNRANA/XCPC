#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    cin>>x>>y;
    if(sqrt(x*x+y*y)<=1.0) cout<<10<<"\n";
    else if(sqrt(x*x+y*y)<=2.0) cout<<9<<"\n";
    else if(sqrt(x*x+y*y)<=3.0) cout<<8<<"\n";
    else if(sqrt(x*x+y*y)<=4.0) cout<<7<<"\n";
    else if(sqrt(x*x+y*y)<=5.0) cout<<6<<"\n";
    else if(sqrt(x*x+y*y)<=6.0) cout<<5<<"\n";
    else if(sqrt(x*x+y*y)<=7.0) cout<<4<<"\n";
    else if(sqrt(x*x+y*y)<=8.0) cout<<3<<"\n";
    else if(sqrt(x*x+y*y)<=9.0) cout<<2<<"\n";
    else if(sqrt(x*x+y*y)<=10.0) cout<<1<<"\n";
	else cout<<0<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
