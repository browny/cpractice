#include <iostream>

using namespace std;

//notice virtual destructor
class A {
public:
	A() 
	{
		cout << 1;
	}
	/*virtual*/ ~A()
	{
		cout << 2;
	}
};

class B : public A
{
public:
	B()
	{
		cout << 3;
	}
	~B()
	{
		cout << 4;
	}
};

int main(int argc, char** argv)
{
	A *b = new B;
	delete b;
	b = NULL;
	cout << endl;
	return 0;
}
