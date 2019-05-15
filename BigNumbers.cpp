#include "stdafx.h" 
#include "BigNumberLib.h" 


namespace BigNumbers
{

	BigNumber::BigNumber(std::vector<int> n)
	{
		num = n;
		if (n[0] < 0)
		{
			positive = false;
		}
		else
		{
			positive = true;
		}
	}

	BigNumber::BigNumber()
	{

	}

	BigNumber::~BigNumber()
	{

	}

	void BigNumber::SetPos()
	{
		if (num[0] < 0)
			positive = false;
		else
			positive = true;
	}

	std::vector<int> BigNumber::GetNum()
	{
		return num;
	}

	bool BigNumber::GetPos() 
	{
		return positive; 
	}

	void BigNumber::PrintNum()
	{
		for (int i = 0; i < num.size(); i++)
		{
			std::cout << num.at(i);
		}
	}

	BigNumber BigNumber::Reverse()
	{
		BigNumber rev;

		for (auto i = num.rbegin(); i != num.rend(); i++)
		{
			rev.num.push_back(*i);
		}

		return rev;
	}

	void BigNumber::ChangeSign()
	{
		positive = !positive;
		num[0] -= 2 * num[0];
	}

	void BigNumber::operator=(const BigNumber &rightSide)
	{
		num = rightSide.num;
		positive = rightSide.positive;
	}

	BigNumber BigNumber::operator+(const BigNumber &rightSide)
	{
		int leftPos;
		int rightPos;

		if (positive)
			leftPos = 1;
		else
			leftPos = -1;

		if (rightSide.positive)
			rightPos = 1;
		else
			rightPos = -1;

		BigNumber temp;

		BigNumber left(num);
		BigNumber right(rightSide);

		if (leftPos == 1 && rightPos == 1)
		{
			left = left.Reverse();
			right = right.Reverse();

			if (left.num.size() != right.num.size())
			{
				if (left.num.size() > right.num.size())
				{
					right.num.resize(left.num.size());
				}
				else
				{
					left.num.resize(right.num.size());
				}
			}

			for (int i = 0; i < left.num.size(); i++)
			{
				temp.num.push_back(left.num[i] + right.num[i]);
				if (temp.num.back() > 9)
				{
					temp.num.back() -= 10;
					if (i == left.num.size() - 1)
					{
						temp.num.push_back(1);
					}
					else
					{

						left.num[i + 1] ++;
					}
				}
			}

			temp = temp.Reverse();
		}
		else if (leftPos == -1 && rightPos == -1)
		{
			left.ChangeSign();
			right.ChangeSign();

			temp = left + right;
			temp.ChangeSign();
		}
		else if (leftPos == -1 && rightPos == 1)
		{
			left.ChangeSign();
			temp = left - right;
			temp.ChangeSign();
		}
		else
		{
			right.ChangeSign();
			temp = right - left;
			temp.ChangeSign();
		}
		temp.SetPos();
		return temp;
	}

	BigNumber BigNumber::operator-(const BigNumber &rightSide)
	{
		int leftPos;
		int rightPos;

		if (positive)
			leftPos = 1;
		else
			leftPos = -1;

		if (rightSide.positive)
			rightPos = 1;
		else
			rightPos = -1;

		BigNumber temp;

		BigNumber left(num);
		BigNumber right(rightSide);

		if (leftPos == 1 && rightPos == 1)
		{
			if (left > right)
			{
				left = left.Reverse();
				right = right.Reverse();

				if (left.num.size() != right.num.size())
				{
					if (left.num.size() > right.num.size())
					{
						right.num.resize(left.num.size());
					}
					else
					{
						left.num.resize(right.num.size());
					}
				}
				for (int i = 0; i < left.num.size(); i++)
				{
					temp.num.push_back(left.num[i] - right.num[i]);
					if (temp.num.back() < 0)
					{
						temp.num.back() += 10;
						left.num[i + 1] --;
					}
				}
			}
			else if (left == right)
			{
				temp.num.push_back(0);
			}
			else
			{
				temp = right - left;
				temp.ChangeSign();
				temp = temp.Reverse();
			}
			while (temp.num.back() == 0 && temp.num.size() != 1)
			{
				temp.num.pop_back();
			}
			temp = temp.Reverse();
		}
		else
		{
			right.ChangeSign();
			temp = left + right;
		}

		temp.SetPos();
		return temp;
	}

	BigNumber BigNumber::operator%(const BigNumber &rightSide)
	{
		BigNumber temp;

		BigNumber left(num);
		BigNumber right(rightSide);

		BigNumber negRight(right);
		negRight.ChangeSign();

		if (right > left)
		{
			temp = left;
		}
		else
		{
			temp = left - (left / right)*right;
			if (temp == right || temp == negRight)
			{
				temp = right - right;
			}
		}
		return temp;
	}

	BigNumber BigNumber::operator*(const BigNumber &rightSide)
	{
		int leftPos;
		int rightPos;

		if (positive)
			leftPos = 1;
		else
			leftPos = -1;

		if (rightSide.positive)
			rightPos = 1;
		else
			rightPos = -1;

		BigNumber temp;

		BigNumber left(num);
		BigNumber right(rightSide);

		if (leftPos == -1)
		{
			left.ChangeSign();
		}
		if (rightPos == -1)
		{
			right.ChangeSign();
		}

		left = left.Reverse();
		right = right.Reverse();

		temp.num.resize(left.num.size() + right.num.size());

		for (int j = 0; j < right.num.size(); j++)
		{
			for (int i = 0; i < left.num.size(); i++)
			{
				temp.num[i + j] += left.num[i] * right.num[j];
				if (temp.num[i + j] > 9)
				{
					temp.num[i + j + 1] += temp.num[i + j] / 10;
					temp.num[i + j] %= 10;
				}
			}
		}

		while (temp.num.back() == 0 && temp.num.size() != 1)
		{
			temp.num.pop_back();
		}

		temp = temp.Reverse();
		temp.SetPos();

		if ((leftPos == -1 && rightPos == 1) || (leftPos == 1 && rightPos == -1))
		{
			temp.ChangeSign();
		}

		return temp;
	}

	BigNumber BigNumber::operator/(const BigNumber &rightSide)
	{
		BigNumber temp;

		if (rightSide.num[0] == 0)
		{
			std::cout << "Error!" << std::endl;
		}
		else
		{
			int leftPos;
			int rightPos;

			if (positive)
				leftPos = 1;
			else
				leftPos = -1;

			if (rightSide.positive)
				rightPos = 1;
			else
				rightPos = -1;

			BigNumber left(num);
			BigNumber right(rightSide);

			if (leftPos == -1)
			{
				left.ChangeSign();
			}
			if (rightPos == -1)
			{
				right.ChangeSign();
			}

			BigNumber count({ 0 });
			BigNumber inc({ 1 });

			temp = right * count;

			while (left > (right * count))
			{
				count = count + inc;
			}

			if (temp == left)
			{
				temp = count;
			}
			else
			{
				temp = count - inc;
			}

			if ((leftPos == -1 && rightPos == 1) || (leftPos == 1 && rightPos == -1))
			{
				temp.ChangeSign();
			}

			temp.SetPos();

		}
		return temp;
	}

	bool BigNumber::operator >(const BigNumber &right)
	{
		bool greaterThan = true;

		if (num.size() < right.num.size())
		{
			greaterThan = false;
		}
		else if (num.size() == right.num.size())
		{
			int i = 0;
			while (i < num.size() && num[i] == right.num[i])
			{
				i++;
			}

			if (i == num.size() || num[i] < right.num[i])
			{
				greaterThan = false;
			}
		}

		return greaterThan;
	}
	bool BigNumber::operator==(const BigNumber &right)
	{
		bool equal = true;

		if (num.size() != right.num.size())
		{
			equal = false;
		}
		else
		{
			int i = 0;
			while (i < num.size() && num[i] == right.num[i])
			{
				i++;
			}

			if (i != num.size())
			{
				equal = false;
			}
		}

		return equal;
	}
}