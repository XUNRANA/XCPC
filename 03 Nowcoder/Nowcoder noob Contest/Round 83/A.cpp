#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,A,B,C,D;
    cin>>a>>b>>c>>d>>e;
    cin>>A>>B>>C>>D;
    if(a*A+b*B+c*C-d*D>e) cout<<"YES";
    else cout<<"NO";
}