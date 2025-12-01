#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
	if(s[0]==s[4]) cout<<s[0]<<endl;
	else
    {
		int a=0,b=0;
		for(int i=0;i<8;i++)
        {
			if(s[i]==s[0])a++;
			if(s[i]==s[4])b++;
		}
		if(a==b) cout<<"N"<<endl;
	    else if(a<b) cout<<s[4]<<endl;
		else cout<<s[0]<<endl; 
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