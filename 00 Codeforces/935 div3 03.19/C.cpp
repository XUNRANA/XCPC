#include <bits/stdc++.h>
using namespace std;
int a[300010];
int n,s1;
string s;
int ck(int x)
{
	//1-x x+1 n
	if(a[x]>x-a[x]) return 0;
	if(a[n]-a[x]<(n-x)-(a[n]-a[x])) return 0;
	return 1;
}
void solve()
{
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) a[i]=0;
	for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='1');
	/*
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	*/
	
	vector<int>v;
	if(n&1)
	{
		s1=n/2;
		for(int i=s1;i;i--)
		{
			v.push_back(i);
			v.push_back(n-i);
		}
		v.push_back(0);
		v.push_back(n);
		/*
		for(auto i:v) cout<<i<<" ";
		cout<<"\n";
		*/
		
		
		
	}
	else
	{
		s1=n/2;
		v.push_back(s1);
		for(int i=1;s1-i>=1;i++)
		{
			v.push_back(s1-i);
			v.push_back(s1+i);
		}
		v.push_back(0);
		v.push_back(n);
		/*
		for(auto i:v) cout<<i<<" ";
		cout<<"\n";
		*/
		
		
	}
	for(auto i:v)
	{
		if(ck(i))
		{
			cout<<i<<"\n";
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
