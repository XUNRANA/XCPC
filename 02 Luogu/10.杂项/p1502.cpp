#include <bits/stdc++.h>
using namespace std;
#define N 100010

int n,w,h;
struct node
{
	int x,y,l;
}a[10010];
void solve()
{
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].l;
	cout<<(1ll<<31)<<"\n";//2e9
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
} 
