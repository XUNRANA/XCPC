#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c,x1,y1,x2,y2,k; 
void solve() 
{
    cin>>n>>m;
    cout<<"? 1 1\n";
    cin>>a;
    cout<<"? "<<n<<" "<<1<<endl;
    cin>>b;
    cout<<"? "<<n<<" "<<m<<endl;
    cin>>c;
    x1=(a-b+n+1)/2,y1=(a+b-n+3)/2;
    x2=(2*n+m-1-b-c)/2,y2=(b-c+1+m)/2;
    if(x1<=0||y1<=0||x1>n||y1>m) cout<<"! "<<x2<<" "<<y2<<endl;
    else 
	{
        cout<<"? "<<x1<<" "<<y1<<endl;
        cin>>k;
        if(k==0) cout<<"! "<<x1<<" "<<y1<<endl;
        else cout<<"! "<<x2<<" "<<y2<<endl;
    }
}

int main()
{
	int t;
	cin>>t;
	cout<<"\n\n";
	while(t--) solve();
}
