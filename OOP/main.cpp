#include <iostream>
#include "ParentClass.h"
#include "DerivedClass.h"
using namespace std;

VIRTUAL_CLASS(Base)
DECLARE_METHOD(Both, Base)
DECLARE_METHOD(OnlyBase, Base)
END

// ������


CONSTRUCTOR(Base)
SETINFO(1)
LINK_METHOD(Both)
LINK_METHOD(OnlyBase)
END_CONSTRUCTOR


//// �����-���������
VIRTUAL_CLASS_DERIVED(Derived, Base)

DECLARE_METHOD(OnlyDerived, Derived)
DECLARE_METHOD(Both, Derived)
END_DERIVE


//// ������
DERIVED_CONSTRUCTOR(Derived)
SETINFO(2)
LINK_DERIVE_METHOD(Both)
LINK_DERIVE_METHOD(OnlyDerived)
END_DERIVED_CONSTRUCTOR(Derived, Base)


void main()
{

	Base base;// = // ���-�� ������� ������� ����� 
	base.info = 10; // �������� ��� �� ����������
	Derived derived;// = // ... ���-�� ������� ��������� 

	// �����������
	Base* reallyDerived = reinterpret_cast<Base*>(&derived);

	VIRTUAL_CALL((&base), Both); // �������� �Base::Both info = 10�
	cout << endl;
	VIRTUAL_CALL(reallyDerived, Both); // �������� �Derived::Both info = 2�
	cout << endl;
	VIRTUAL_CALL(reallyDerived, OnlyBase);  // �������� �Base::OnlyBase info = 2�
	cout << endl;
	VIRTUAL_CALL(reallyDerived, OnlyDerived);	//Derived::OnlyDerived info = 2
	cout << endl;
}
