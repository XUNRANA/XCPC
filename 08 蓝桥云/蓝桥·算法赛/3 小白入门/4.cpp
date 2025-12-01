#include <iostream>
using namespace std;
int main()
{
  int t,a,b,c,cnt;
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>c;
    int cnt=(a+c-1)/c;
    cout<<(b+cnt-1)/cnt<<"\n";
  }
}
