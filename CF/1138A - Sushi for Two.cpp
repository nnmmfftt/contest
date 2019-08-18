#include<bits/stdc++.h>

using namespace std;


int handler(vector<vector<int>>& vec, int pos) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i][0] <= pos && vec[i][1] > pos) {
			return vec.size() - i - 1;
		}
	}
}
int main() {
	int chapter;
	vector<vector<int>> vec;
	vector<int> tmp;
	cin >> chapter;
	while (chapter--) {
		int first;
		int second;
		cin >> first >> second;
		tmp.push_back(first);
		tmp.push_back(second);
		vec.push_back(tmp);
		tmp.clear();
	}
	int now;
	cin >> now;
	int ret = handler(vec, now);
	cout << ret;
	return ret;
}