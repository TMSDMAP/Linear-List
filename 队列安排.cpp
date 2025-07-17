#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
struct Node {
	int id;
	Node* next;
	Node* prev;
};
Node S[100005];
int main()
{
	cin >> n;
	S[1].id = 1;
	for (int i = 1; i <= n; i++)
	{
		S[i].id = i;
		S[i].next = NULL;
		S[i].prev = NULL;
	}
	Node* head = &S[1];
	for (int i = 2; i <= n; i++)
	{
		S[i].id = i;
		int k, p;
		cin >> k >> p;
		if (p == 0)
		{
			S[i].next = &S[k];
			S[i].prev = S[k].prev;
			if (S[k].prev != NULL)
			{
				S[k].prev->next = &S[i];
			}
			S[k].prev = &S[i];
			if(head== &S[k]) {
				head = &S[i];
			}
		}
		else
		{
			S[i].prev = &S[k];
			S[i].next = S[k].next;
			if (S[k].next != NULL)
			{
				S[k].next->prev = &S[i];
			}
			S[k].next = &S[i];
		}
	}
	int M;
	cin >> M;
	while (M--)
	{
		int x;
		cin >> x;
		if(S[x].prev== NULL && S[x].next == NULL) {
			continue;
		}
		if (S[x].prev == NULL)
		{
			S[x].next->prev = NULL;
			head = S[x].next;
			S[x].next = NULL;
		}
		else if (S[x].next == NULL)
		{
			S[x].prev->next = NULL;
			S[x].prev = NULL;
		}
		else
		{
			S[x].prev->next = S[x].next;
			S[x].next->prev = S[x].prev;
			S[x].next = NULL;
			S[x].prev = NULL;
		}
	}
	int t = head->id;
	/*for (int i = 1; i <= n; i++)
	{
		if (S[i].prev == NULL)
		{
			if (S[i].next == NULL) continue;
			else {
				t = i; break;
			}
		}
	}*/
	while(t&&S[t].next != NULL) {
		cout << t << " ";
		t = S[t].next->id;
	}
	cout << t << endl;
	return 0;
}


