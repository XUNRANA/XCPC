#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int i=0;
    while(i<n)
    {
        if(i+4<n&&s.substr(i,5)=="avava") i+=5;
        else if(i+2<n&&s.substr(i,3)=="ava") i+=3;
        else
        {
            cout<<"No\n";
            return ;
        }
        //cout<<i<<"\n";
    }
    cout<<"Yes\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}