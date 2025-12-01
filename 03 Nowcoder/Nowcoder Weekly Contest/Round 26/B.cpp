#include <bits/stdc++.h>
using namespace std;
string s,s1;
void solve()
{
    cin>>s;
    s1=s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='0'&&i+1<s.size())
        {
            s[i]='0';
            s[i+1]=((s[i+1]-'0')^1)+'0';
        }
    }
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!='1'&&i+1<s1.size())
        {
            s1[i]='1';
            s1[i+1]=((s1[i+1]-'0')^1)+'0';
        }
    }
    //cout<<s<<" "<<s1<<"\n";
    if(s.find('1')==-1||s1.find('0')==-1) cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

