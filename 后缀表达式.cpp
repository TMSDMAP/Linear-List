#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<int> S;
	int num = 0;
	bool  readingNum = false;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (isdigit(c))
		{
			num = num * 10 + (c - '0');
			readingNum = true;
		}
		else if (c == '.')
		{
			S.push(num);
			num = 0;
			readingNum = false;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			int b = S.top(); S.pop();
			int a = S.top(); S.pop();
			int res = 0;
			if (c == '+') res += a + b;
			else if (c == '-') res += a - b;
			else if (c == '*') res += a * b;
			else if (c == '/') res += a / b;
			S.push(res);
		}
		else if (c == '@') break;;
	}
	cout << S.top() << endl;
	return 0;
}