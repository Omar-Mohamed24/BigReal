// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "BigReal.h"

BigReal::BigReal()
{
	sign = '+';
	integer = "0";
	fraction = "0";
	isValid = 0;
}

BigReal::BigReal(const BigReal& other)
{
	sign = other.sign;
	integer = other.integer;
	fraction = other.fraction;
	isValid = other.isValid;
}

BigReal::BigReal(string realNumber)
{
	if (regex_match(realNumber, regex("[+-]?\\d*.?\\d+")))
	{
		isValid = 1;
		if (realNumber[0] == '-')
		{
			sign = '-';
			realNumber.erase(0, 1);
		}
		else if (realNumber[0] == '+')
		{
			realNumber.erase(0, 1);
		}

		if (realNumber.find('.') != string::npos)
		{
			integer = realNumber.substr(0, realNumber.find('.'));
			fraction = realNumber.substr(integer.size() + 1, realNumber.size() - integer.size() - 1);
			if (integer.size() == 0) integer = '0';
		}
		else
		{
			integer = realNumber;
			fraction = '0';
		}
	}
	if (realNumber == "") isValid = 1;
	if (!isValid)
	{
		cout << "The number is invalid\n";
	}
}

bool BigReal::operator > (BigReal& other)
{
	if (sign == other.sign)
	{
		if (sign == '+')
		{
			bool isBigger = 0;
			if (integer.size() == other.integer.size())
			{
				for (int i = 0; i < integer.size(); i++)
				{
					if (integer[i] - '0' == other.integer[i] - '0') continue;
					else
					{
						if (integer[i] - '0' > other.integer[i] - '0') isBigger = 1;
						break;
					}
				}

				if (!isBigger)
				{
					string fraction1 = fraction;
					string other_fraction = other.fraction;
					if (fraction.size() > other.fraction.size())
					{
						other_fraction += string(fraction.size() - other.fraction.size(), '0');
					}
					else if (fraction.size() < other.fraction.size())
					{
						fraction1 += string(other.fraction.size() - fraction.size(), '0');
					}

					for (int i = 0; i < fraction1.size(); i++)
					{
						if (fraction1[i] - '0' == other_fraction[i] - '0') continue;
						else
						{
							if (fraction1[i] - '0' > other_fraction[i] - '0') isBigger = 1;
							break;
						}

					}
				}
			}
			else
			{
				if (integer.size() > other.integer.size()) isBigger = 1;
			}
			if (isBigger) return true;
			else return false;
		}

		else if (sign == '-')
		{
			bool isSmaller = 0;
			if (integer.size() == other.integer.size())
			{
				for (int i = 0; i < integer.size(); i++)
				{
					if (integer[i] - '0' == other.integer[i] - '0') continue;
					else
					{
						if (integer[i] - '0' < other.integer[i] - '0') isSmaller = 1;
						break;
					}
				}
				if (!isSmaller)
				{
					string fraction1 = fraction;
					string other_fraction = other.fraction;
					if (fraction.size() > other.fraction.size())
					{
						other_fraction += string(fraction.size() - other.fraction.size(), '0');
					}
					else if (fraction.size() < other.fraction.size())
					{
						fraction1 += string(other.fraction.size() - fraction.size(), '0');
					}

					for (int i = 0; i < fraction1.size(); i++)
					{
						if (fraction1[i] - '0' == other_fraction[i] - '0') continue;
						else
						{
							if (fraction1[i] - '0' < other_fraction[i] - '0') isSmaller = 1;
							break;
						}
					}
				}
			}
			else
			{
				if (integer.size() < other.integer.size()) isSmaller = 1;
			}
			if (isSmaller) return true;
			else return false;
		}
	}

	else
	{
		if (sign == '+') return true;
		else return false;
	}
}

bool BigReal::operator < (BigReal& other)
{
	if (sign == other.sign)
	{
		if (sign == '+')
		{
			bool isSmaller = 0;
			if (integer.size() == other.integer.size())
			{
				for (int i = 0; i < integer.size(); i++)
				{
					if (integer[i] - '0' == other.integer[i] - '0') continue;
					else
					{
						if (integer[i] - '0' < other.integer[i] - '0') isSmaller = 1;
						break;
					}
				}
				if (!isSmaller)
				{
					string fraction1 = fraction;
					string other_fraction = other.fraction;
					if (fraction.size() > other.fraction.size())
					{
						other_fraction += string(fraction.size() - other.fraction.size(), '0');
					}
					else if (fraction.size() < other.fraction.size())
					{
						fraction1 += string(other.fraction.size() - fraction.size(), '0');
					}

					for (int i = 0; i < fraction1.size(); i++)
					{
						if (fraction1[i] - '0' == other_fraction[i] - '0') continue;
						else
						{
							if (fraction1[i] - '0' < other_fraction[i] - '0') isSmaller = 1;
							break;
						}
					}
				}
			}
			else
			{
				if (integer.size() < other.integer.size()) isSmaller = 1;
			}
			if (isSmaller) return true;
			else return false;
		}
		else if (sign == '-')
		{
			bool isBigger = 0;
			if (integer.size() == other.integer.size())
			{
				for (int i = 0; i < integer.size(); i++)
				{
					if (integer[i] - '0' == other.integer[i] - '0') continue;
					else
					{
						if (integer[i] - '0' > other.integer[i] - '0') isBigger = 1;
						break;
					}
				}

				if (!isBigger)
				{
					string fraction1 = fraction;
					string other_fraction = other.fraction;
					if (fraction.size() > other.fraction.size())
					{
						other_fraction += string(fraction.size() - other.fraction.size(), '0');
					}
					else if (fraction.size() < other.fraction.size())
					{
						fraction1 += string(other.fraction.size() - fraction.size(), '0');
					}

					for (int i = 0; i < fraction1.size(); i++)
					{
						if (fraction1[i] - '0' == other_fraction[i] - '0') continue;
						else
						{
							if (fraction1[i] - '0' > other_fraction[i] - '0') isBigger = 1;
							break;
						}

					}
				}
			}
			else
			{
				if (integer.size() > other.integer.size()) isBigger = 1;
			}
			if (isBigger) return true;
			else return false;
		}
	}
	else
	{
		if (sign == '-') return true;
		else return false;
	}
}

bool BigReal::operator == (BigReal& other)
{
	if (sign == other.sign && integer == other.integer && fraction == other.fraction) return true;
	else return false;
}

BigReal BigReal::operator + (BigReal& other)
{
	string ans = "";
	if (sign == other.sign)
	{
		string fraction1 = fraction;
		string other_fraction = other.fraction;
		if (fraction.size() > other.fraction.size())
		{
			other_fraction += string(fraction.size() - other.fraction.size(), '0');
		}
		else if (fraction.size() < other.fraction.size())
		{
			fraction1 += string(other.fraction.size() - fraction.size(), '0');
		}
		string fractionSum = "";
		int carry = 0;
		for (int i = fraction1.size() - 1; i >= 0; --i)
		{
			int sum = carry + (fraction1[i] - '0') + (other_fraction[i] - '0');
			if (sum > 9)
			{
				carry = 1;
				sum -= 10;
				char c = '0' + sum;
				fractionSum = c + fractionSum;
			}
			else
			{
				carry = 0;
				char c = '0' + sum;
				fractionSum = c + fractionSum;
			}
		}

		string integer1 = integer;
		string other_integer = other.integer;
		if (integer.size() > other.integer.size())
		{
			other_integer = string(integer.size() - other.integer.size(), '0') + other_integer;
		}
		else if (integer.size() < other.integer.size())
		{
			integer1 = string(other.integer.size() - integer.size(), '0') + integer1;
		}
		string integerSum = "";
		for (int i = integer.size() - 1; i >= 0; --i)
		{
			int sum = carry + (integer1[i] - '0') + (other_integer[i] - '0');
			if (sum > 9)
			{
				carry = 1;
				sum -= 10;
				char c = '0' + sum;
				integerSum = c + integerSum;
			}
			else
			{
				carry = 0;
				char c = '0' + sum;
				integerSum = c + integerSum;
			}
		}
		if (carry == 1) integerSum = "1" + integerSum;
		ans = sign + integerSum + '.' + fractionSum;

		return BigReal(ans);
	}
	else
	{
		string real = integer + '.' + fraction;
		char other_sign = other.sign;
		other.sign = '+';
		string ans = "";
		if (BigReal(real) > other)
		{
			string fraction1 = fraction;
			string other_fraction = other.fraction;
			if (fraction.size() > other.fraction.size())
			{
				other_fraction += string(fraction.size() - other.fraction.size(), '0');
			}
			else if (fraction.size() < other.fraction.size())
			{
				fraction1 += string(other.fraction.size() - fraction.size(), '0');
			}

			string fractionDiff = "";
			int carry = 0;
			for (int i = fraction1.size() - 1; i >= 0; --i)
			{
				int diff = (fraction1[i] - '0') - (other_fraction[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				fractionDiff = c + fractionDiff;
			}

			string integer1 = integer;
			string other_integer = other.integer;
			if (integer.size() > other.integer.size())
			{
				other_integer = string(integer.size() - other.integer.size(), '0') + other_integer;
			}
			else if (integer.size() < other.integer.size())
			{
				integer1 = string(other.integer.size() - integer.size(), '0') + integer1;
			}

			string integerDiff = "";
			for (int i = integer1.size() - 1; i >= 0; --i)
			{
				int diff = (integer1[i] - '0') - (other_integer[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				integerDiff = c + integerDiff;
			}

			integerDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			fractionDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			if (fractionDiff.empty()) fractionDiff = "0";
			if (integerDiff.empty()) integerDiff = "0";
			ans = sign + integerDiff + '.' + fractionDiff;
		}
		else if (BigReal(real) < other)
		{
			string fraction1 = fraction;
			string other_fraction = other.fraction;
			if (fraction.size() > other.fraction.size())
			{
				other_fraction += string(fraction.size() - other.fraction.size(), '0');
			}
			else if (fraction.size() < other.fraction.size())
			{
				fraction1 += string(other.fraction.size() - fraction.size(), '0');
			}

			string fractionDiff = "";
			int carry = 0;
			for (int i = fraction1.size() - 1; i >= 0; --i)
			{
				int diff = (other_fraction[i] - '0') - (fraction1[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				fractionDiff = c + fractionDiff;
			}

			string integer1 = integer;
			string other_integer = other.integer;
			if (integer.size() > other.integer.size())
			{
				other_integer = string(integer.size() - other.integer.size(), '0') + other_integer;
			}
			else if (integer.size() < other.integer.size())
			{
				integer1 = string(other.integer.size() - integer.size(), '0') + integer1;
			}

			string integerDiff = "";
			for (int i = integer1.size() - 1; i >= 0; --i)
			{
				int diff = (other_integer[i] - '0') - (integer1[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				integerDiff = c + integerDiff;
			}

			integerDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			fractionDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			if (fractionDiff.empty()) fractionDiff = "0";
			if (integerDiff.empty()) integerDiff = "0";
			other.sign = other_sign;
			ans = other.sign + integerDiff + '.' + fractionDiff;
		}
		else
		{
			ans = "0.0";
		}
		return BigReal(ans);
	}
}

BigReal BigReal::operator - (BigReal& other)
{
	if (sign == other.sign)
	{
		string real = integer + '.' + fraction;
		string ans = "";
		if (BigReal(real) > other)
		{
			string fraction1 = fraction;
			string other_fraction = other.fraction;
			if (fraction.size() > other.fraction.size())
			{
				other_fraction += string(fraction.size() - other.fraction.size(), '0');
			}
			else if (fraction.size() < other.fraction.size())
			{
				fraction1 += string(other.fraction.size() - fraction.size(), '0');
			}

			string fractionDiff = "";
			int carry = 0;
			for (int i = fraction1.size() - 1; i >= 0; --i)
			{
				int diff = (fraction1[i] - '0') - (other_fraction[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				fractionDiff = c + fractionDiff;
			}

			string integer1 = integer;
			string other_integer = other.integer;
			if (integer.size() > other.integer.size())
			{
				other_integer = string(integer.size() - other.integer.size(), '0') + other_integer;
			}
			else if (integer.size() < other.integer.size())
			{
				integer1 = string(other.integer.size() - integer.size(), '0') + integer1;
			}

			string integerDiff = "";
			for (int i = integer1.size() - 1; i >= 0; --i)
			{
				int diff = (integer1[i] - '0') - (other_integer[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				integerDiff = c + integerDiff;
			}

			integerDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			fractionDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			if (fractionDiff.empty()) fractionDiff = "0";
			if (integerDiff.empty()) integerDiff = "0";
			ans = sign + integerDiff + '.' + fractionDiff;
		}
		else if (BigReal(real) < other)
		{
			string fraction1 = fraction;
			string other_fraction = other.fraction;
			if (fraction.size() > other.fraction.size())
			{
				other_fraction += string(fraction.size() - other.fraction.size(), '0');
			}
			else if (fraction.size() < other.fraction.size())
			{
				fraction1 += string(other.fraction.size() - fraction.size(), '0');
			}

			string fractionDiff = "";
			int carry = 0;
			for (int i = fraction1.size() - 1; i >= 0; --i)
			{
				int diff = (other_fraction[i] - '0') - (fraction1[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				fractionDiff = c + fractionDiff;
			}

			string integer1 = integer;
			string other_integer = other.integer;
			if (integer.size() > other.integer.size())
			{
				other_integer = string(integer.size() - other.integer.size(), '0') + other_integer;
			}
			else if (integer.size() < other.integer.size())
			{
				integer1 = string(other.integer.size() - integer.size(), '0') + integer1;
			}

			string integerDiff = "";
			for (int i = integer1.size() - 1; i >= 0; --i)
			{
				int diff = (other_integer[i] - '0') - (integer1[i] - '0') - carry;
				if (diff < 0)
				{
					carry = 1;
					diff += 10;
				}
				else
				{
					carry = 0;
				}
				char c = '0' + diff;
				integerDiff = c + integerDiff;
			}
			if (other.sign == '-') other.sign = '+';
			else if (other.sign == '+') other.sign = '-';
			integerDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			fractionDiff.erase(0, integerDiff.find_first_not_of('0'));
			reverse(fractionDiff.begin(), fractionDiff.end());
			if (fractionDiff.empty()) fractionDiff = "0";
			if (integerDiff.empty()) integerDiff = "0";
			ans = other.sign + integerDiff + '.' + fractionDiff;
			other.sign = sign;
		}
		else
		{
			ans = "0.0";
		}
		return BigReal(ans);
	}
	else
	{
		string ans = "";
		string fraction1 = fraction;
		string other_fraction = other.fraction;
		if (fraction.size() > other.fraction.size())
		{
			other_fraction += string(fraction.size() - other.fraction.size(), '0');
		}
		else if (fraction.size() < other.fraction.size())
		{
			fraction1 += string(other.fraction.size() - fraction.size(), '0');
		}
		string fractionSum = "";
		int carry = 0;
		for (int i = fraction1.size() - 1; i >= 0; --i)
		{
			int sum = carry + (fraction1[i] - '0') + (other_fraction[i] - '0');
			if (sum > 9)
			{
				carry = 1;
				sum -= 10;
				char c = '0' + sum;
				fractionSum = c + fractionSum;
			}
			else
			{
				carry = 0;
				char c = '0' + sum;
				fractionSum = c + fractionSum;
			}
		}

		string integer1 = integer;
		string other_integer = other.integer;
		if (integer.size() > other.integer.size())
		{
			other_integer = string(integer.size() - other.integer.size(), '0') + other_integer;
		}
		else if (integer.size() < other.integer.size())
		{
			integer1 = string(other.integer.size() - integer.size(), '0') + integer1;
		}
		string integerSum = "";
		for (int i = integer1.size() - 1; i >= 0; --i)
		{
			int sum = carry + (integer1[i] - '0') + (other_integer[i] - '0');
			if (sum > 9)
			{
				carry = 1;
				sum -= 10;
				char c = '0' + sum;
				integerSum = c + integerSum;
			}
			else
			{
				carry = 0;
				char c = '0' + sum;
				integerSum = c + integerSum;
			}
		}
		if (carry == 1) integerSum = "1" + integerSum;
		ans = sign + integerSum + '.' + fractionSum;

		return BigReal(ans);
	}
}

ostream& operator<<(ostream& out, BigReal realNumber)
{
	if (realNumber.sign == '+') out << realNumber.integer << '.' << realNumber.fraction;
	else out << realNumber.sign << realNumber.integer << '.' << realNumber.fraction;

	return out;
}

void BigReal::print()
{
	// if (isValid == 1)
	// {
	if (sign == '+') cout << integer << "." << fraction << '\n'; // If the sign is +ve we don't print it.
	else cout << sign << integer << "." << fraction << '\n'; // We print the -ve sign.
	// }
	// else cout << "Error, please enter a valid real number\n";
	//
	//  
	// the previous code prints 0.0 when realNumber is empty or invalid real.
	// we can modify it to print error message when invalid and 0.0 when empty as shown. 
}



