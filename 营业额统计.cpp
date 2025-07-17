/*#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int n;
vector<int> a;
//priority_queue<int, vector<int>, greater<int>> q;
int binary_search(int l,int r,int target)
{
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (a[mid] >= target) r = mid;
		else l = mid + 1;
	}
	return l;
}



int main()
{
	cin >> n;
	a.resize(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (i == 0) {
			sum += a[i]; continue;
		}
		sort(a.begin(), a.begin() + i);
		//int t = *min_element(a.begin(), a.begin() + i,a[i]);
		//cout << t << endl;
		int t = binary_search(0, i - 1, a[i]);
		int min1 = 0x3f3f3f3f;
		min1 = min(min1, abs(a[t] - a[i]));
		if(t>0)
		min1 = min(min1, abs(a[t - 1] - a[i]));
		sum += min1;
		//cout << sum << endl;
	}
	cout << sum << endl;
	return 0;
}*/


#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<int> s;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i == 0) {
			sum += x;
			s.insert(x);
			continue;
		}
		auto it = s.lower_bound(x);
		int min1 = 0x3f3f3f3f;
		if (it != s.end()) min1 = min(min1, abs(*it - x));
		if (it != s.begin()) min1 = min(min1, abs(*prev(it) - x));
		sum += min1;
		s.insert(x);
	}
	cout << sum << endl;
	return 0;
}