#include <bits/stdc++.h>
using namespace std;
char ns[26],nx[26];
void solve()
{
    for(int i=0;i<26;i++) 
    {
        ns[i]=char('a'+(i-1+26)%26);
        nx[i]=char('A'+(i+1)%26);
    }
    string s;
    cin>>s;
    for(auto i:s)
    {
        if(islower(i)) cout<<ns[i-'a'];
        else if(isupper(i)) cout<<nx[i-'A'];
        else cout<<i;
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
