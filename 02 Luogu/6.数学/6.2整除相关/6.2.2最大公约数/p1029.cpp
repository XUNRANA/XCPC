#include <bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	int x,y;
	cin>>x>>y;
    if(x==y) ans--;
    y*=x;
    for(int i=1;i*i<=y;i++)
    if(y%i==0&&__gcd(i,y/i)==x) ans+=2;
    cout<<ans;
}
