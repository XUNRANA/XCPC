#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    for(int i=0;i<4;i++)
    {
        if(s1[i]==s2[i]||s1[i]==s3[i]) cout<<s1[i];
        else cout<<s2[i];
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
