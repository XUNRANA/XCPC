#include <iostream>
#include <string>
using namespace std;
void test()
{
	//第一种
	pair<string,int>p1("Tom",20);
	cout<<"Name: "<<p1.first<<" Age: "<<p1.second<<endl; 
	//第二种
	pair<string,int>p2=make_pair("Jerry",50); 
	cout<<"Name: "<<p2.first<<" Age: "<<p2.second<<endl; 
}

int main()
{
	test();
}
