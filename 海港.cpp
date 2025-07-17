#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct ship {
	int t;
	vector<int> nations;
};

int main()
{
	int n;
	cin >> n;
	queue<ship> q;
	unordered_map<int, int> nation_cnt;
	const int Window = 86400;
	for (int i = 0; i < n; i++)
	{
		int t, k;
		cin >> t >> k;
		vector<int> nations(k);
		for (int j = 0; j < k; j++)
		{
			cin >> nations[j];
		}
		while (!q.empty() && q.front().t <= t - Window) {
			for (int x : q.front().nations) {
				nation_cnt[x]--;
				if( nation_cnt[x] == 0) {
					nation_cnt.erase(x);
				}
			}
			q.pop();
		}
		for(int x: nations) {
			nation_cnt[x]++;
		}
		q.push({ t, nations });
		cout << nation_cnt.size() << endl;
	}
	return 0;
}