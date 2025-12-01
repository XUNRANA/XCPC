#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s,p;
    double sm=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='.') p+=s[i];
        else 
        {
            if(i+1<s.size()) p+=s[++i];
            sm+=stoll(p)*0.1;
            p="";
        }
    }
    if(p!="") sm+=stoi(p);
    printf("%.1f",sm);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

