#include <iostream>
using namespace std;
int main()
{
  int n,ans,t;
  ans=0;
  cin>>n;
  while(n--)
  {
    cin>>t;
    if(t>=6) ans+=t/3-1;
  }
  cout<<ans<<"\n";
}
