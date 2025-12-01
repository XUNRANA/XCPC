#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res,ans,t;
vector<int>b,c;
void insert(int x)
{
	for(auto i:b) x=min(x,x^i);
	for(auto &i:b) i=min(i,i^x);
	if(x) b.push_back(x);
}
void insertc(int x)
{
	for(auto i:c) x=min(x,x^i);
	for(auto &i:c) i=min(i,i^x);
	if(x) c.push_back(x);
}
int ck(int x,int l)
{
	c.clear();
	for(auto i:b) insertc(i-(i>>(l+1)<<(l+1)));
	for(auto i:c) x=min(x,x^i);
	if(x) return 0;
	return 1;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans^=t;
		insert(t);
	}
	for(int i=0;i<=60;i++) if(ck((1ll<<i)-1,i)) res=max(res,ans^((1ll<<(i+1))-1));
	cout<<res<<"\n";
}
