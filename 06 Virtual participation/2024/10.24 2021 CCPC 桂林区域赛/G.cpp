#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool ck(int x)
{
	int len=0;
	for(auto i:s)
	{
		if(i=='0') len++;
		else
		{
			if(len<x) len=-x;
			else if(len==x) len=-max(x-1,0);
			else return 0;
		}
	}
	if(len>0) return 0;
	return 1;
}
void solve()
{
	cin>>n>>s;
	if(count(s.begin(),s.end(),'0')==0)
	{
		cout<<"0\n";
		return ;
	}
	
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ck(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
