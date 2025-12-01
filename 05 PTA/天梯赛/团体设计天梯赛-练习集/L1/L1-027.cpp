#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
int f(int x)
{
	for(int i=0;i<a.size();i++) 
	if(a[i]==x) return i;
}
void solve()
{
	string s;
	cin>>s;
	set<int>st;
	for(auto i:s) st.insert(i-'0');
	for(auto i:st) a.push_back(i);
	sort(a.begin(),a.end(),greater<int>());
	cout<<"int[] arr = new int[]{"<<a[0];
	for(int i=1;i<a.size();i++) cout<<","<<a[i];
	cout<<"};\n";
	cout<<"int[] index = new int[]{"<<f(s[0]-'0');
	for(int i=1;i<s.size();i++) cout<<","<<f(s[i]-'0');
	cout<<"};\n";
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

