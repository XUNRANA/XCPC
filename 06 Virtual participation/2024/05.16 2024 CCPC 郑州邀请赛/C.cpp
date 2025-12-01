#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
10
1 10 2 6 10 8 9 4 4 5
*/
bool cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	int n;
	cin>>n;
	vector<int>a(n+1),l(n+1,n+1),r(n+1,0),d(n+1);
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		l[a[i]]=min(l[a[i]],i);//a[i]最左边的位置 
		r[a[i]]=i;//a[i]最右边的位置 
	}
	int tot=0;//总共多少个数 
	for(int i=1;i<=n;i++)
	if(l[i]<=r[i]) d[l[i]]++,d[r[i]]--,tot++;
	for(int i=2;i<=n;i++) d[i]+=d[i-1];
	/*
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	cout<<"\n";
	*/
	int lst=1;
	for(int i=2;i<=n+1;i++)
	{
		if(d[i-1]==0)
		{
			sort(a.begin()+lst,a.begin()+i,greater<int>());
			lst=i;
		}
	}
	/*
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<'\n';
	*/
	vector<int>b;
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		auto it=lower_bound(b.begin(),b.end(),x);
		if(it==b.end()) b.push_back(x);
		else *it=x;
	} 
	cout<<tot-b.size()<<'\n';
} 

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
