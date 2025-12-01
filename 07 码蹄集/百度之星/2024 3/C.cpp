#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p=0,p1=0,now=0,ans=0;
	map<int,int>mp;
	while(n--)
	{
		int x;
		char ch;
		cin>>x>>ch;
		if(ch=='R') now+=x-1;
		else now-=x-1;
		mp[min(p,now)]++;
		mp[max(p,now)+1]--;
		p=now;
	}
	p=0;
	for(auto &i:mp)
	{
		i.second+=p;
		p=i.second;
	}
	ans=p=p1=0;
	for(auto i:mp) 
	{
		if(p1%4==1) ans+=i.first-p; 
		p=i.first;
		p1=i.second;
	}
	cout<<ans<<"\n";
	
} 
