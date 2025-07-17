#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<ll, unordered_map<ll, ll>> a;

int main()
{
	ll n, q;
	cin >> n >> q;
	while (q--) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll x, y, z;
			cin >> x >> y >> z;
			if (z == 0) {
				a[x].erase(y);
			}
			else {
				a[x][y] = z;
			}
		}
		else
		{
			ll x, y;
			cin >> x >> y;
			cout << a[x][y] << endl;
		}
	}
}