#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
	int x,y,k;
}a[100010];
bool cmp(node a1,node a2)
{
	return a1.k>a2.k;
}
void solve()
{
	cin>>n;
	vector<int>b;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y;
		b.push_back(a[i].x);
		b.push_back(a[i].y);
	}
	sort(b.begin(),b.end());
	
	for(int i=1;i<=n;i++)
	{
		a[i].k=0;
		a[i].k+=2*n-(upper_bound(b.begin(),b.end(),a[i].x)-b.begin());
		a[i].k+=2*n-(upper_bound(b.begin(),b.end(),a[i].y)-b.begin());
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<" ";
	cout<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
