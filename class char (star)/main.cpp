#include "Header.h"

int main()
{
	try
	{
		int ind;
		bool w = 0;
		cout << "Inputting 3 strings\nDo you want to input(1) or to use (2) \"Hello, world!\" instead?\n";
		cin >> ind;
		Char str1, str2, str3;
		while (true)
		{
			switch (ind)
			{
			case 1:
			{
					  char h[1];
					  gets(h);
					  cin >> str1;
					  w = 1;
					  break;
			}
			case 2:
			{
					  Char str("Hello, world!");
					  str1 = str;
					  w = 1;
					  break;
			}
			default:
			{
					   cout << "Wrong input\n";
			}
			}
			if (!w)
			{
				cout << "Try again\nDo you want to input(1) or to use \"Hello, world!\" instead?\n";
				cin >> ind;
			}
			else break;
		}
		cout << "\n2nd string\n\nDo you want to input(1) or to use \" My name is Alina.\" instead?\n";
		cin >> ind;
		w = 0;
		while (true)
		{
			switch (ind)
			{
			case 1:
			{
					  char h[1];
					  gets(h);
					  cin >> str2;
					  w = 1;
					  break;
			}
			case 2:
			{
					  Char str("My name is Alina.");
					  str2 = str;
					  w = 1;
					  break;
			}
			default:
			{
					   cout << "Wrong input\n";
			}
			}
			if (!w)
			{
				cout << "Try again\nDo you want to input(1) or to use \" My name is Alina.\" instead?\n";
				cin >> ind;
			}
			else break;
		}
		cout << "\n3rd string\nDo you want to input(1) or to use \" The sun shines.\" instead?\n";
		cin >> ind;
		w = 0;
		while (true)
		{
			switch (ind)
			{
			case 1:
			{
					  char h[1];
					  gets(h);
					  cin >> str3;
					  w = 1;
					  break;
			}
			case 2:
			{
					  Char str("The sun shines.");
					  str3 = str;
					  w = 1;
					  break;
			}
			default:
			{
					   cout << "Wrong input\n";
			}
			}
			if (!w)
			{
				cout << "Try again\nDo you want to input(1) or to use \" The sun shines.\" instead?\n";
				cin >> ind;
			}
			else break;
		}
		cout << str1 << "\n" << str2 << "\n" << str3 << "\n";
		Char s[3];
		s[0] = str1;
		s[1] = str2;
		s[2] = str3;
		cout << s[0] << s[1] << s[2] << "\n";
		cout << "\nNext\nWhat do you want to do with the strings?\nTo compare for an equality two strings input 1\n";
		cout << "To find their sum input 2\nTo see if one string is greater than another - 3\nLess - 4\nTo find length - 5\nTo output i symbol of the string - 6\n";
		cout << "To print string stolbikom - 7\nEND - 0\n";
		cin >> ind;
		int num1, num2, num;
		w = 0;
		while (true)
		{
			if (ind >= 1 && ind <= 4)
			{
				cout << "Which of the strings (2) do you want to use? (1, 2 or 3)\n";
				while (true)
				{
					cin >> num1 >> num2;
					if (num1 < 0 || num1 > 3 || num2 < 0 || num2 > 3)
					{
						cout << "Wrong input\n";
						w = 1;
					}
					else
					{
						cout << "Strings:\n" << s[num1 - 1] << s[num2 - 1] << "\n";
					}
					if (!w)
						break;
					else
					{
						cout << "Try again\n";
					}
				}
			}
			if (ind == 5 || ind == 6 || ind == 7)
			{
				cout << "Which one of the strings (1) do you want to use? (1, 2 or 3)\n";
				while (true)
				{
					w = 0;
					cin >> num;
					if (num < 0 || num > 3)
					{
						cout << "Wrong input\n";
						w = 1;
					}
					if (!w)
						break;
					else
					{
						cout << "Try again\n";
					}
				}
			}
			switch (ind)
			{
			case 1:
			{
					  if (s[num1 - 1] == s[num2 - 1])
					  {
						  cout << s[num1 - 1] << "\nis equal to\n" << s[num2 - 1] << "\n";

					  }
					  else
						  cout << "Strings " << s[num1 - 1] << " and " << s[num2 - 1] << " are not equal\n";
					  break;
			}
			case 2:
			{
					  Char sum;
					  sum = s[num1 - 1] + s[num2 - 1];
					  cout << sum;
					  cout << "\n";
					  break;
			}
			case 3:
			{
					  if (s[num1 - 1] > s[num2 - 1])
					  {
						  cout << s[num1 - 1] << "is greater than" << s[num2 - 1] << "\n";
					  }
					  else
						  cout << s[num1 - 1] << "is not greater than" << s[num2 - 1] << "\n";
					  break;
			}
			case 4:
			{
					  if (s[num1 - 1] < s[num2 - 1])
					  {
						  cout << s[num1 - 1] << "is less than" << s[num2 - 1] << "\n";
					  }
					  else
						  cout << s[num1 - 1] << "is not less than" << s[num2 - 1] << "\n";
					  break;
			}
			case 5:
			{
					  Char str = s[num - 1];
					  cout << "Length of the str" << num << " is " << str.length() << "\n";
					  break;
			}
			case 6:
			{
					  cout << "Input index\n"; int n;
					  while (true)
					  {
						  cin >> n;
						  if (n > (s[num - 1]).length())
						  {
							  cout << "Try again\n";
							  cin >> n;
						  }
						  else break;
					  }
					  cout << "\n" << s[num - 1][n - 1] << "\n";
					  break;
			}
			case 7:
			{
					  for (int i = 0; i < (s[num - 1]).length(); i++)
						  cout << (s[num - 1])[i] << "\n";
					  break;
			}
			case 0:
			{
					  return 0;
			}
			default:
			{
					   cout << "Wrong input\n";
			}
			}
			cout << "\nNext\nWhat do you want to do with the strings?\nTo compare for an equality two strings input 1\n";
			cout << "To find their sum input 2\nTo see if one string is greater than another - 3\nLess - 4\nTo find length - 5\nTo output i symbol of the string - 6\n";
			cout << "To print string stolbikom - 7\nEND - 0\n";
			cin >> ind;
		}
	}
	catch (MyException e)
	{
		cout << e.what() << "\n";
	}
}