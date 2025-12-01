#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i+3<s.size()&&s.substr(i,4)=="2024") 
        {
            cout<<"2025";
            i+=3;
            continue;
        }
        cout<<s[i];
    }
    cout<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
