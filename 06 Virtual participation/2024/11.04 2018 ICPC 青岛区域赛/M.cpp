#include <bits/stdc++.h>
using namespace std;

int a[]={1,0,0,0,1,0,1,0,2,1};
void solve()
{
	int x;
	int k;
	cin>>x>>k;
	if(k==0)
	{
		cout<<x<<"\n";
		return ;
	}
	while(x!=0&&x!=1&&k)
	{
		int x1=0;
		while(x)
		{
			x1+=a[x%10];
			x/=10;
		}
		x=x1;
		k--;
	}
	if(k&1) x^=1;
	cout<<x<<"\n";
}
/*
6
123456789 1
888888888 1
888888888 2
888888888 999999999
98640 12345
1000000000 0
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
