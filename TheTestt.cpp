#include "pch.h" 
#include "BigNumberLib.h"


int main()
{
	std::vector<int> num1 = { 2,7,6,7,8,6,1,7,0,4,3 };
	std::vector<int> num2 = {1,3,4,9,0,3,5,1};

	BigNumbers::BigNumber n1(num1);
	BigNumbers::BigNumber n2(num2);

	BigNumbers::BigNumber n3(n1 + n2);
	BigNumbers::BigNumber n4(n1 - n2);
	BigNumbers::BigNumber n5(n1 * n2);
	BigNumbers::BigNumber n6(n1 / n2);
	BigNumbers::BigNumber n7(n1 % n2);


	std::cout << "27678617043 + 13490351  = ";
	n3.PrintNum();
	std::cout << std::endl;

	std::cout << "27678617043 - 13490351  = ";
	n4.PrintNum();
	std::cout << std::endl;

	std::cout << "27678617043 * 13490351  = ";
	n5.PrintNum();
	std::cout << std::endl;

	std::cout << "27678617043 / 13490351  = ";
	n6.PrintNum();
	std::cout << std::endl;

	std::cout << "27678617043 % 13490351  = ";
	n7.PrintNum();
	std::cout << std::endl;



	return 0;
}
