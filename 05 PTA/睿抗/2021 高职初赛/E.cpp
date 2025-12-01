#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(int x)
{
	vector<int>a;
    int y=x;
	while(x)
	{
		a.push_back(x%10);
		x/=10;
	}
	int s1=0,s2=0;
	if(a.size()%2==1) return 0;
    int n=a.size()/2;
    int d=pow(10,n);
    if(y/d+1==y%d) return 1;
    return 0;
}
void solve()
{
	int n;
	cin>>n;
	int t=sqrt(n);
	if(ck(n)) 
	{
		if(t*t==n) cout<<"2\n";
		else cout<<"1\n";
	}
	else cout<<"0\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
