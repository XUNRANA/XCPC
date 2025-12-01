#include <bits/stdc++.h>
using namespace std;
#define int long long
map<string,int>ans;
string a[10]={ "jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren","gui"};
string b[12]={"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
void init()
{
	int i=0;
	int j=0;
	int y=1984;
	while(y<=2043)
	{
		ans[a[i]+b[j]]=y;
		j++;
		i++;
		i%=10;
		j%=12;
		y++;
	}
}
void solve()
{
	string s;
	cin>>s;
	cout<<ans[s]<<"\n";
}

signed main() 
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

