#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool unvalid[200];
stack<pair<char,int>> st;
void isValid(string& s)
{
	int i = 0;
	for (;i<s.length();i++)
	{
		char c = s[i];
		if (c == '(' || c == '[') st.push({ c,i });
		else if (c == ')' || c == ']')
		{
			if (st.empty())
			{
				unvalid[i] = true;
				continue;
			}
			if (c == ')' && st.top().first != '(' || c == ']' && st.top().first != '[')
			{
				unvalid[i] = true;
				continue;
			}
			st.pop();
		}
	}
	while (!st.empty())
	{
		unvalid[st.top().second] = true;
		st.pop();
	}
}

int main()
{
	string s;
	cin >> s;
	isValid(s);
	for (int i = 0; i < s.length(); i++)
	{
		if (!unvalid[i]) cout << s[i];
		else
		{
			if (s[i] == '(') cout << "()";
			else if (s[i] == ')') cout << "()";
			else if (s[i] == '[') cout << "[]";
			else if (s[i] == ']') cout << "[]";
		}
	}
}



