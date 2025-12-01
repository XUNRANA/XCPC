#include <bits/stdc++.h>
using namespace std;
string s;
int n,l,r,m;
int ck(int x)
{
    map<string,int>mp;
    int c1=0;
	for(int i=1;i<=n;i+=x) 
	{
		string t=s.substr(i,x);
		mp[t]++;
		if(mp[t]==2) c1++;
		if(mp.size()>2||c1>=2) return 0;
	}
	
	if(mp.size()==2)
	{
		string a="",b="";
		for(auto i:mp) 
		{
			if(a=="") a=i.first;
			else b=i.first;
		}
		int c=0;
		for(int i=0;i<a.size();i++) if(a[i]!=b[i]) c++;
		if(c>1) return 0;
		return 1;
	}
	return 1;
}
void solve()
{
	cin>>n>>s;
	vector<int>a;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0) 
		{
			a.push_back(i);
			if(i*i!=n) a.push_back(n/i);
		}
	}
	sort(a.begin(),a.end());
	l=0,r=a.size()-1;
	s=" "+s;
	while(l<=r)
	{
		//cout<<l<<" "<<r<<" "<<a[l+r>>1]<<"\n";
		m=l+r>>1;
		if(ck(a[m])) r=m-1;
		else l=m+1;
	}
	cout<<a[l]<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
