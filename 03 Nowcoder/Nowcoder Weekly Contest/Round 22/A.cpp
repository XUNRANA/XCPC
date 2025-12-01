#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    cout<<(s.find("red")==s.rfind("red")?"No":"Yes");

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

