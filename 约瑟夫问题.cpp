#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
struct Node {
	int num;
	Node* next;
};

Node* create()
{
	Node* head = new Node;
	head->next = head;
	Node* p = head;
	head->num = 1;
	int i = 1;
	while (i < n)
	{
		Node* node = new Node;
		node->num = i + 1;
		p->next = node;
		p = node;
		i++;
	}
	p->next = head;
	return head;
}

int main()
{
	cin >> n;
	int m;
	cin >> m;
	Node* head = create();
	Node* p = head;
	while (p->next != p)
	{
		for (int i = 0; i < m - 2; i++)
			p = p->next;
		Node* q = p->next;
		p->next = q->next;
		v.push_back(q->num);
		delete q;
		p = p->next;
	}
	v.push_back(p->num);
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
			cout << v[i];
		else
			cout << v[i] << " ";
	}
}