#include <iostream>
#include <algorithm>
using namespace std;

const long long N = 2e6 + 5;
int n, m;
long long a[N];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (m--)
	{
		int c;
		cin >> c;
		cout << a[c] << endl;
	}
	return 0;
}

