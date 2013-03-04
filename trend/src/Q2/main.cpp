#include <string.h>
#include <iostream>

using namespace std;

class Base {

public:
	Base ()
	{

	}

	~Base()
	{

	}
	//virtual void Output() = 0;
};

class Derived : public Base {

public:
	Derived() : Base()
	{

	}
	Derived(const char* patr) : Base(), m_patr(NULL)
	{
		const size_t arStrLen = 10;
		//m_patr = new char[arStrLen + 1];
		//strncpy(m_patr, patr ? patr : "(NULL)", arStrLen);
		//m_patr[arStrLen] = '\0';
	}
	
	~Derived()
	{
		delete[] m_patr;
		m_patr = NULL;
	}
	
	void Output()
	{
		//cout << m_patr << endl;
	}

private:
	char *m_patr;
};

int main(int argc, char* argv[])
{
	const char *str = "test";
	//Base *p = new Derived(str);
	Base *p = new Derived;
	//p->Output();
	//delete p;
	//p = NULL;
	return 0;
}
