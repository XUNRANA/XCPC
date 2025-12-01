#include <bits/stdc++.h>
using namespace std;
#define N 2000010
int a[N];
int ck(int x,int y)
{
	int cnt=0;
	for(int i=30;i>=0;i--) if((x>>i&1)!=(y>>i&1)) cnt++;
	return cnt;
}
void init()
{
	for(int i=2;i<N;i++) a[i]=a[i-1]+ck(i-1,i);
}
void solve()
{
	init();
	int t,l,r;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		cout<<a[l+r]-a[l]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
