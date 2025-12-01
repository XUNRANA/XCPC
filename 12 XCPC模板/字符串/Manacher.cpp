#include <bits/stdc++.h>
using namespace std;
string s,t;
void init()
{
	t+="$";
	t+="#";	
	for(auto i:s)
	{
		t+=i;
		t+="#";
	}
	t+="^";
}
int p[22000010];
void manacher()
{
	init();
	int n=t.size();
	int mr=0,mid;
	for(int i=1;i<n;i++)
	{
		if(i<mr) p[i]=min(p[mid*2-i],mr-i);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]]) p[i]++;
		if(i+p[i]>mr) mr=i+p[i],mid=i;
	}
}
void solve()
{
	int res=0;
	cin>>s;
	manacher();
	for(int i=0;i<t.size();i++) res=max(res,p[i]);
	cout<<res-1<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}