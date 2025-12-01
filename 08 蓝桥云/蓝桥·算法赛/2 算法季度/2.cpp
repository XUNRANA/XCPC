#include <iostream>
using namespace std;
long long t,x,y,a;
void solve()
{
  cin>>x>>y>>a;
  if(2*x>=y) cout<<a*x<<"\n";
  else
  {
    if(a<=3) cout<<a*x<<"\n";
    else
    {
      if(a%3==0) cout<<a/3*(3*x+y-(2*x))-(y-(2*x))<<"\n";
      else cout<<a/3*(3*x+y-(2*x))+a%3*x<<"\n";
    }
  }
}
int main()
{
  cin>>t;
  while(t--) solve();
}
