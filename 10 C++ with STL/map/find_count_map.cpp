#include <map>
#include <iostream>
using namespace std;

void test()
{
	map<int,int>m;
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(3,40));//key重复了 插不进去 
	
	map<int,int>::iterator pos=m.find(3);
	if(pos!=m.end()) cout<<"Key = "<<pos->first<<" Value = "<<pos->second<<endl;
	else "Not Find!\n";
	
	int num=m.count(3);  //1 or 0  mulitmap可能大于1 
	cout<<"num = "<<num<<endl;
}
int main()
{
	test();	
}
