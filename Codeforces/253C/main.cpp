#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> pii;

istream& operator>> (istream &input, pii &p) {
	input >> p.first >> p.second;
	p.first --; p.second --;
	return input;
}

inline bool bet(const int v, const int begin, const int end) {
	return v >= begin && v < end;
}

int N;
const int MaxN = 100;
const int MaxM = 1e5 + 1;

vector<int> lines;
pii start, goal;
queue<pii> q;
vector<vector<int> > dis(MaxN, vector<int>(MaxM, -1));

inline bool isValid(const pii &node) {
	return bet(node.first, 0, N) && bet(node.second, 0, lines[node.first]);
}

inline pii doAction(const pii &node, const int i) {
	pii res = node;

	if (i == 0) {
		res.first --;
		if (res.first < 0)
			res.first ++;
		if (res.second > lines[res.first] - 1)
			res.second = lines[res.first] - 1;
	} else if (i == 1) {
		res.first ++;
		if (res.first >= N)
			res.first --;
		if (res.second > lines[res.first] - 1)
			res.second = lines[res.first] - 1;
	} else if (i == 2) {
		res.second ++;
		if (res.second > lines[res.first] - 1)
			res.second --;
	} else if (i == 3) {
		res.second --;
		if (res.second < 0)
			res.second ++;
	}

	return res;
}

inline void add(const pii &node, const int par) {
	q.push(node);
	dis[node.first][node.second] = par;
}

int BFS() {
	add(start, 0);

	while (q.front() != goal) {
		pii node = q.front();
		q.pop();

		for (int i = 0; i < 4; i ++) {
			pii child = doAction(node, i);
			if (isValid(child) && dis[child.first][child.second] == -1)
				add(child, dis[node.first][node.second] + 1);
		}
	}

	return dis[q.front().first][q.front().second];
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> N;
	lines.resize(N);
	for (int i = 0; i < N; i ++) {
		fin >> lines[i];
		lines[i] ++;
	}
	fin >> start >> goal;

	fout << BFS() << endl;

	return 0;
}
