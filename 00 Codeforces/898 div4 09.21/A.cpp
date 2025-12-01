#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s,s1,s2,s3;
	cin>>s;
	s1=s2=s3=s;
	swap(s1[0],s1[1]);
	swap(s2[0],s2[2]);
	swap(s3[1],s3[2]);
	if(s=="abc"||s1=="abc"||s2=="abc"||s3=="abc") cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
