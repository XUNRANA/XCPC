#include <iostream>
#include <stack>
using namespace std;
void test()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	while(!s.empty())
	{
		cout<<"栈的大小： " <<s.size()<<endl; 
		cout<<"栈顶元素 "<<s.top()<<endl;
		s.pop();
	}
}
int main()
{
	test();
}
