#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		stack<int> s;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			s.push(a[i]);
			while (!s.empty() && s.top() == b[j])
			{
				s.pop();
				j++;
			}
		}
		if(s.empty())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}