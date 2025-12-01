#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s,p;
	cin>>n>>s>>p;
	s+=s;
	for(auto &i:p) if(i>='a') i-=32;
	else i+=32;
	
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
	
	
	int j;
	i=j=0;
	while(i<2*n&&j<n)
	{
		if(s[i]==p[j]) i++,j++;
		else 
	    {
	      if(j) j=next[j-1];
	      else i++;
	    }
	}
	if(j==n)
	{
		cout<<"Yes\n";
		cout<<min(i-j,n-i+j)<<"\n";
	}
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
