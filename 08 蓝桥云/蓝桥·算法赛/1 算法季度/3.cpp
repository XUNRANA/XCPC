#include <iostream>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long x,y;
    string s;
    cin>>x>>s>>y;
    if(s=="KB") x*=1024;
    if(s=="MB") x*=1024*1024;
    cout<<x/y<<"\n";
  }
  return 0;
}
