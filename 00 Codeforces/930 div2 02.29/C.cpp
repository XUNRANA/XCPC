#include <bits/stdc++.h>
using namespace std;
long long n,id_mx,id;
char e,c;
void solve()
{
	cin>>n;
    id_mx=0;
    for(int i=1;i<=n-1;++i)
	{
        cout<<"? "<<id_mx<<" "<<id_mx<<" "<<i<<" "<<i<<"\n";
        cin>>e;
        if(e=='<') id_mx=i;
    }
    id=0;
    if(id==id_mx) id=1;
    for(int i=0;i<=n-1;++i)
	{
        if(i==id_mx||i==id) continue;
        cout<<"? "<<id_mx<<" "<<id<<" "<<id_mx<<" "<<i<<endl;
        cin>>e;
        if(e=='<') id=i;
        else if(e=='=')
		{
            cout<<"? "<<id<<" "<<id<<" "<<i<<" "<<i<<endl;
            cin>>c;
            if(c=='>') id=i;  
        }
    }
    cout<<"! "<<id_mx<<" "<<id<<"\n";
}
int main()
{
	/*
	ios::sync_with_stdio(0);
	cin.tie(0);*/
	int t;
	cin>>t;
	while(t--) solve();
}
