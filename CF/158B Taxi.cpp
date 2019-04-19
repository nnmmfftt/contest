#include<bits/stdc++.h>

using namespace std;
vector<int> init_taxi_io() {
	vector<int> vec;
	int i;
	cin >> i;
	while (i--) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	return vec;
}
int solve_taxi(vector<int>& vec) {
	sort(vec.begin(), vec.end());
	int left = 0, right = vec.size()-1;
	int ret = 0;
	int pos = -1;
	while (left < right ) {
		if (vec[right] == 4) {
			ret++;
			right--;
		}
		else if (vec[left] + vec[right] > 4) {
			ret++;
			right--;
		}
		else if (vec[left] + vec[right] == 4) {
			ret++;
			right--;
			left++;
		}
		else {
			vec[right] = vec[left]+vec[right];
			left++;
			pos = right;
		}
	}
	if (left == right) ret++;
	if (right == pos) ret++;
	return ret+1;
}

//int main() {
//	vector<int> vec;
//	vec = init_taxi_io();
//	int ret = solve_taxi(vec);
//	cout << ret;
//	getchar();
//	getchar();
//	return 0;
//
//}