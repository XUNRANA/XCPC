#include <bits/stdc++.h>
using namespace std;
int c1,c2;
int main()
{
	string s;
	cin>>s;
	for(auto i:s) if(i=='<') c1++;
	else if(i=='>') c2++; 
	if(c1==c2&&c1==1) cout<<"Yes\n";
	else cout<<"No\n";
}
