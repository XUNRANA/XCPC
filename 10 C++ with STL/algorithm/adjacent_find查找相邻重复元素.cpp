#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);  //pos所指的位置 
	v.push_back(3);
	//0 2 0 3 1 4 3 3
	vector<int>::iterator pos=adjacent_find(v.begin(),v.end());
	if(pos==v.end()) cout<<"Not find"<<endl;
	else cout<<"Find:"<<*pos<<endl;
}
int main()
{
	test();
}
