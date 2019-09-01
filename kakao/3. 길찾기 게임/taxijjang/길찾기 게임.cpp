#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#define SIZE 100010
using namespace std;

typedef struct Data {
	int x, y, num;
	Data *left = NULL, *right = NULL;

	bool operator<(Data d) {
		if (x == d.x)
			return y < d.y;
		return x > d.x;
	}
}Data;

Data D[SIZE];
Data *root;
struct cmp {
	bool operator()(Data d1, Data d2) {
		if (d1.x == d2.x)
			return d1.y > d2.y;
		return d1.x < d2.x;
	}
};
vector<int> pre, post;
void preorder(Data *d) {
	if (d == NULL)
		return;
	pre.push_back(d->num);
	preorder(d->left);
	preorder(d->right);
}

void postorder(Data *d) {
	if (d == NULL)
		return;
	postorder(d->left);
	postorder(d->right);
	post.push_back(d->num);
}
void dfs(Data *curr, Data *newNode) {
	if (curr->y > newNode->y && curr->left != NULL) {
		dfs(curr->left, newNode);
	}
	else if (curr->y > newNode->y && curr->left == NULL) {
		curr->left = newNode;
	}
	else if (curr->y < newNode->y && curr->right != NULL) {
		dfs(curr->right, newNode);
	}
	else {
		curr->right = newNode;
	}
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	int n_size = nodeinfo.size();

	for (int i = 0; i < n_size; i++) {
		D[i].x = nodeinfo[i][1];
		D[i].y = nodeinfo[i][0];
		D[i].num = i + 1;
	}
	sort(D, D + n_size);
	Data *newnode;

	newnode = (Data *)malloc(sizeof(Data));
	newnode = &D[0];
	root = newnode;
	for (int i = 1; i < n_size; i++) {
		newnode = (Data *)malloc(sizeof(Data));
		newnode = &D[i];
		dfs(root, newnode);
	}

	preorder(root);
	postorder(root);
	answer.push_back(pre);
	answer.push_back(post);
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	vector<vector<int>> n({
		vector<int>({ 5,3 }),
		vector<int>({ 11,5 }),
		vector<int>({ 13,3 }),
		vector<int>({ 3,5 }),
		vector<int>({ 6,1 }),
		vector<int>({ 1,3 }),
		vector<int>({ 8,6 }),
		vector<int>({ 7,2 }),
		vector<int>({ 2,2 })
	});

	vector<vector<int>> res = solution(n);
}