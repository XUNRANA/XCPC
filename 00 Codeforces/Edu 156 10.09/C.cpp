#include <bits/stdc++.h>
using namespace std;
string s;
long long n,pos,l,x,y;
void solve()
{
	cin>>s>>pos;
	pos--;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		l=n-i;
		if(pos<l)
		{
			x=i;
			y=pos;
			break;
		}
		pos-=l;
	}
	string t;
	for(auto c:s)
	{
		while(x>0&&!t.empty()&&c<t.back())
		{
			t.pop_back();
			x--;
		}
		t+=c;
	}
	cout<<t[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
