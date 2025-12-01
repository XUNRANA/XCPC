#include <bits/stdc++.h>
using namespace std;

struct node
{
	string name;
	int d;
	int c;
}a[110];
bool cmp(node a1,node a2)
{
	if(a1.d==a2.d) return a1.c<a2.c;
	return a1.d>a2.d;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].name;
		cin>>a[i].c;
		set<int>st;
		for(int j=1;j<=a[i].c;j++)
		{
			int x;
			cin>>x;
			st.insert(x);
		}
		a[i].d=st.size();
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=3;i++)
	{
		if(i!=1) cout<<" ";
		if(i<=n) cout<<a[i].name; 
		else cout<<"-";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
