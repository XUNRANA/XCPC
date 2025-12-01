#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int l=stoi(s.substr(2));
	l=l/2+1;
	int cr=0,cp=0;
	cin>>s;
	for(auto i:s)
	{
		if(i=='R') cr++;
		else cp++;
		if(cp==l||cr==l)
		{
			if(cr==l) cout<<"kou!\n"<<cp+cr;
			else cout<<"yukari!\n"<<cp+cr;
            return ;
		}
	}
    
	cout<<"to be continued.\n"<<cr+cp;
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
