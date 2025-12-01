#include <bits/stdc++.h>
using namespace std;
string a,b,s;
bool ck(int x)
{
//	16
//  88 8 90
	int s1=0,v=1;
	for(auto i:a)
	{
		int y;
		if(isdigit(i)) y=i-'0';
		else y=i-'A'+10;
		if(y>=x) return 0;
		s1+=y*v;
		v=v*x;
	}
	
	int s2=0;
	v=1;
	for(auto i:b)
	{
		int y;
		if(isdigit(i)) y=i-'0';
		else y=i-'A'+10;
		if(y>=x) return 0;
		s2+=y*v;
		v=v*x;
	}
	
	int s3=0;
	v=1;
	for(auto i:s)
	{
		int y;
		if(isdigit(i)) y=i-'0';
		else y=i-'A'+10;
		if(y>=x) return 0;
		s3+=y*v;
		v=v*x;
	}
//	cout<<s1<<" "<<s2<<" "<<s3<<"\n";
	if(s1+s2==s3) return 1;
	else return 0;
}
void solve()
{
//0 1 2 3 4 5 6 7 8 9 A B C D E F
	cin>>a>>b>>s;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(s.begin(),s.end());
	for(int x=1;x<=16;x++)
	{
		if(ck(x))
		{
			cout<<x<<"\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
