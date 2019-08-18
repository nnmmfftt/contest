#include<bits/stdc++.h>

using namespace std;

int is_luckynumber(int number) {
	if (number == 1) return -1;
	while (number >1) {
		int oops = number % 10;
		if (oops != 4 && oops != 7) {
			return -1;
		}number /= 10;
	}return 0;
}
vector<int> luckyset() {
	int i = 1;
	vector<int> vec;
	while (i++ < 1000) {
		if (is_luckynumber(i) == 0) vec.push_back(i);
	}return vec;
}

int is_likelylucy(int number,vector<int> set) {
	for (int i = 0; i < set.size(); ++i) {
		if (number% set[i] == 0) return 0;
	}
	return -1;
}

int main() {
	int tmp;
	int val;
	cin >> val;
	if (val == 1) { cout << "NO"; return 0; }
	tmp = is_luckynumber(val);
	if (0 == tmp) cout << "YES";
	else if (0 == is_likelylucy(val, luckyset()))cout << "YES";
	else cout << "NO";
	return 0;
}