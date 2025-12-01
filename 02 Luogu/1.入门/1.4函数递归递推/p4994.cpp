#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[10000000],m,i=1;
ll fx(ll x)
{
	if(f[x]) return f[x];
	if(x==1||x==2) return f[x]=1;
	else return f[x]=(fx(x-1)+fx(x-2))%m;
}
int main()
{
	cin>>m;
	while(fx(i)!=0||fx(i+1)!=1) i++;
	cout<<i;
}
