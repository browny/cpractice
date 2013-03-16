
// Q3: If we create an object from class B, what will be the result
// A. 3412, B. 3142, C. 3124, D. 1342 E.1324 F.1234

#include <iostream>

using namespace std;

//notice virtual destructor
class A {
public:
	A() { cout << 1; }
	/*virtual*/ 
	~A() { cout << 2; }
};

class B : public A
{
public:
	B() { cout << 3; }
	~B() { cout << 4; }
};

int main(int argc, char** argv)
{
	A *b = new B;
	delete b;
	b = NULL;
	cout << endl;
	return 0;
}
