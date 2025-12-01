#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,ns;
	string s,p;
	cin>>s>>p;


	n=p.size(),ns=s.size();
	vector<int>next(n);//求p的next数组 
	next[0]=0;
	int pre=0,i=1;
	while(i<n)
	{
		if(p[pre]==p[i]) next[i++]=++pre;
		else
		{
			if(pre==0) next[i++]=0;
			else pre=next[pre-1];
		}
	}
	
	vector<int>ans;
	int j;
	i=j=0;
	while(i<ns)
	{
		if(s[i]==p[j]) i++,j++;
		else 
		{
			if(j) j=next[j-1];
			else i++;
		}
		if(j==n) 
		{
			ans.push_back(i-j+1);
			j=next[j-1];
		}
	}
	for(auto i:ans) cout<<i<<"\n";
	for(auto i:next) cout<<i<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 