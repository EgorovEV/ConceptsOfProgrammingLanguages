#include <iostream>
#include "ParentClass.h"
#include "DerivedClass.h"
using namespace std;

VIRTUAL_CLASS(Base)
DECLARE_METHOD(Both, Base)
DECLARE_METHOD(OnlyBase, Base)
END

// методы


CONSTRUCTOR(Base)
SETINFO(1)
LINK_METHOD(Both)
LINK_METHOD(OnlyBase)
END_CONSTRUCTOR


//// класс-наследник
VIRTUAL_CLASS_DERIVED(Derived, Base)

DECLARE_METHOD(OnlyDerived, Derived)
DECLARE_METHOD(Both, Derived)
END_DERIVE


//// методы
DERIVED_CONSTRUCTOR(Derived)
SETINFO(2)
LINK_DERIVE_METHOD(Both)
LINK_DERIVE_METHOD(OnlyDerived)
END_DERIVED_CONSTRUCTOR(Derived, Base)


void main()
{

	Base base;// = // как-то создали базовый класс 
	base.info = 10; // работаем как со структурой
	Derived derived;// = // ... как-то создали наследник 

	// полиморфизм
	Base* reallyDerived = reinterpret_cast<Base*>(&derived);

	VIRTUAL_CALL((&base), Both); // печатает УBase::Both info = 10Ф
	cout << endl;
	VIRTUAL_CALL(reallyDerived, Both); // печатает УDerived::Both info = 2Ф
	cout << endl;
	VIRTUAL_CALL(reallyDerived, OnlyBase);  // печатает УBase::OnlyBase info = 2Ф
	cout << endl;
	VIRTUAL_CALL(reallyDerived, OnlyDerived);	//Derived::OnlyDerived info = 2
	cout << endl;
}
