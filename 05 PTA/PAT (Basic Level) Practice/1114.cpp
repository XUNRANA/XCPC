#include <bits/stdc++.h>
using namespace std;


int f=1;
bool is(int y)
{
    if(y<2) return 0;
    for(int i=2;i*i<=y;i++) if(y%i==0) return 0;
    return 1;
}
void ck(string x)
{
    int y=stoi(x);
    if(is(y)) cout<<x<<" Yes\n";
    else 
    {
        f=0;
        cout<<x<<" No\n"; 
    }
}
void solve()
{
    string a;
    cin>>a;
    for(int i=0;i<8;i++)
    {
        ck(a.substr(i,8-i));
    }
    if(f) cout<<"All Prime!\n";
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
