#pragma once
#include <iostream>

enum type {
	A_CLASS,
	B_CLASS,
	C_CLASS
};

class Base {
	public:
		virtual ~Base();
};

class A : public Base {
	public :
		A();
};

class B : public Base {
	public :
		B();
};

class C : public Base {
	public :
		C();
};