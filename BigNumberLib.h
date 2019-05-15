#pragma once

#include <iostream>
#include <vector>

namespace BigNumbers
{
	class BigNumber
	{
	private:
		std::vector<int> num;
		bool positive;
	public:
        BigNumber(std::vector<int> n);

        BigNumber();

		~BigNumber();
		
		void SetPos();

		std::vector<int> GetNum();

		bool GetPos();

		void PrintNum();

		BigNumber Reverse();

		void ChangeSign();

		void operator=(const BigNumber &rightSide);

		BigNumber operator+(const BigNumber &rightSide);

		BigNumber operator-(const BigNumber &rightSide);
		
		BigNumber operator%(const BigNumber &rightSide);		

		BigNumber operator*(const BigNumber &rightSide);
		
		BigNumber operator/(const BigNumber &rightSide);
		
		bool operator >(const BigNumber &right);
		
		bool operator==(const BigNumber &right);
		
	};
}
