#include <bits/stdc++.h>
using namespace std;
int n;
void solve() 
{
    cin>>n;
    if(n==1) 
	{
        cout<<"1\n";
        return;
    }
    cout<<196<<string(n-3,'0')<<"\n";
    for(int i=0;i<n/2;i++) 
	{
        cout<<1<<string(i,'0')<<6<<string(i,'0')<<9<<string(n-3-2*i,'0')<<"\n";
		cout<<9<<string(i,'0')<<6<<string(i,'0')<<1<<string(n-3-2*i,'0')<<"\n";
    }
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}

