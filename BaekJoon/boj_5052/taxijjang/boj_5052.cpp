#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 11
#define MAX 10011
using namespace std;

typedef long long int ll;

struct Trie {
	Trie *next[SIZE];
	bool finish;

	Trie() {
		fill(next, next + SIZE, nullptr);
		finish = false;
	}

	~Trie() {
		for (int i = 0; i < SIZE; i++) {
			if (next[i])
				delete next[i];
		}
	}

	void insert(const char *key) {
		if (*key == NULL)
			finish = true;
		else {
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	bool find(const char *key) {
		if (*key == NULL)
			return false;
		if (finish)
			return true;
		int curr = *key - '0';
		return next[curr]->find(key + 1);
	}
};

char arr[MAX][SIZE];

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {


		int N; scanf("%d", &N);
		Trie *trie = new Trie;

		for (int i = 0; i < N; i++) {
			scanf("%s", arr[i]);
			trie->insert(arr[i]);
		}

		bool res = true;
		for (int i = 0; i < N; i++) {
			bool toggle = trie->find(arr[i]);
			if (toggle)
				res = false;
		}

		if (res)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}