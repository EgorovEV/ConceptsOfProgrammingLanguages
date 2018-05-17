
#include "header.h"
#include <iostream>
#include <vector>

using namespace std;

void B_() {
	cout << "Func B_" << endl << "throw exc_ 0 in B_()" << endl;
	THROW(BAD_FILE);
}

void A_() {
	cout << "Func A_" << endl;
	B_();
}

int main() {
	TRY(
		cout << "throw exc_ 1" << endl;
	THROW(DEVIDE_ZERO);
	) CATCH(DEVIDE_ZERO,
		cout << "catch exc_ 1" << endl;
	) END

	cout << endl;


	TRY(
		std::cout << "throw exc_ 1" << std::endl;
	THROW(DEVIDE_ZERO);
	) CATCH(BAD_FILE,
		std::cout << "catch exc_ 0" << std::endl;
	) CATCH(DEVIDE_ZERO,
		std::cout << "catch exc_ 1" << std::endl;
	) END


	TRY(
		TRY(
			std::cout << "throw exc_ 1" << std::endl;
			THROW(DEVIDE_ZERO);
		) CATCH(DEVIDE_ZERO,
			std::cout << "catch exc_ 1" << std::endl;
		) END

		TRY(
			std::cout << "throw exc_ 1" << std::endl;
			THROW(DEVIDE_ZERO);
		) CATCH(DEVIDE_ZERO,
			std::cout << "catch exc_ 1" << std::endl;
		) END

		A_();

	) CATCH(BAD_FILE,
		std::cout << "catch exc_ 0" << std::endl;
	) CATCH(DEVIDE_ZERO,
		std::cout << "catch exc_ 1" << std::endl;
	) END

	return 0;
}