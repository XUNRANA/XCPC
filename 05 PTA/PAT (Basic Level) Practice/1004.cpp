#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int mx=0;
    int mi=100;
    int n;
    cin>>n;
    string name_mi,name_mx,id_mi,id_mx;
    while(n--)
    {
        string name,id;
        int g;
        cin>>name>>id>>g;
        if(g<=mi)
        {
            mi=g;
            name_mi=name;
            id_mi=id;
        }

        if(g>=mx)
        {
            mx=g;
            name_mx=name;
            id_mx=id;
        }
    }
    cout<<name_mx<<" "<<id_mx<<"\n";
    cout<<name_mi<<" "<<id_mi<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}