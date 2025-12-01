#include <bits/stdc++.h>
using namespace std;
int main()
{
	int f=0;
	string s,ans;
	cin>>s;
	ans+=s[0];
	for(int i=1;i<s.size();i++) if(s[i]!=s[i-1]) ans+=s[i];
	if((ans.size()==3&&ans=="ABC")||(ans.size()==2&&(ans=="AB"||ans=="AC"||ans=="BC"))||ans.size()==1) cout<<"Yes\n";
	else cout<<"No\n";
}
