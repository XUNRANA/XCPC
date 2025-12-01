#include <bits/stdc++.h>
using namespace std;
int n,ans,f1,f2;
string a,b,a1,b1;
bool ck(string p,string s)
{
	vector<int>next(p.size());
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
	while(i<s.size())
	{
		if(s[i]==p[j]) i++,j++;
		else 
		{
			if(j) j=next[j-1];
			else i++;
		}
		if(j==p.size()) return 1;
	}
	return 0;
}

void solve()
{
	cin>>n>>a>>b;
	b=b+b;
	for(int i=0;i<26;i++)
	{
		a1=b1="";
		f1=f2=0;
		for(auto j:a)
		{
			if(j!='a'+i) a1+='?';
			else f1=1,a1+=j;
		}
		for(auto j:b)
		{
			if(j!='a'+i) b1+='?';
			else f2=1,b1+=j;
		}
		if(f1&&f2&&ck(a1,b1)) ans++;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
