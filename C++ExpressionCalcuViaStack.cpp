// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include <list>
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <stack>

using namespace std;


int calculate(const int &first, const int &second, const char &op)
{
	switch (op)
	{
	case '+':
	{
		return first + second;
		break;
	}
	case '-':
	{
		return first - second;
		break;
	}
	case '/':
	{
		return first / second;
		break;
	}
	case '*':
	{
		return first * second;
		break;
	}
	case '%':
	{
		return first % second;
		break;
	}
	}
}


int compareOP(const char &current, const char &last)
{
	cout <<last << '/' <<current<< endl;
	switch (last)
	{
		case '\0':
		{
			if (current == '\0')
			{
				return 1;
			}
			else
			{
				return 2;
			}
			break;
		}
		case '(':
		{
			if (current == ')')
			{
				return 1;
			}
			else
			{
				return 2;
			}
			break;
		}
		case '*':
		case '/':
		case '%':
		{
			if (current == '\0' || current == '(')
			{
				return 2;
			}
			else
			{
				return 3;
			}
			break;
		}
		case '+':
		case '-':
		{
			if (current == '(')
			{
				return 2;
			}
			else
			{
				return 3;
			}
			break;
		}

	}
}

bool isOp(const char &op)
{
	if (op == '+' ||
		op == '-' ||
		op == '*' ||
		op == '/' ||
		op == '/0' ||
		op == '(' ||
		op == ')' ||
		op == '%')
	{
		return true;
	}
	return false;
}

int calculateExp(const string &a, int length)
{
	stack<int> number;
	stack<char> operater;
	operater.push('\0');
	int calculated = 0;
	int tempSecond = 0;
	int tempFirst = 0;
	int t;
	while (calculated != length)
	{
		if (!isOp(a[calculated]))
		{
			number.push(a[calculated]);
			calculated++;
		}
		else
		{
		
			t = compareOP(a[calculated], operater.top());
			switch (t)
			{			
				case 1:
				{
					operater.pop();
					break;
				}
				case 2:
				{
					operater.push(a[calculated]);
					calculated += 1;
					break;
				}
				case 3:
				{

					tempSecond = number.top();
					number.pop();
					tempFirst = number.top();
					number.pop();
					char opTemp = operater.top();
					operater.pop();
					number.push(calculate(tempFirst, tempSecond, opTemp));
					break;
				}
			}
		}
	}
	number.pop();
	return number.top();
}




int main()
{
	
	string exp = {1, '-', '(', 1, '*', 3, ')', '\0' };

	cout << calculateExp(exp, 8);

	while (true)
	{

	}
}
