#include<bits/stdc++.h>

using namespace std;

int plus_or_minus(string s) {
	int len = s.size();
	while (len) {
		if (s[len-1] == '+') return 1;
		if (s[len-1] == '-') return -1;
		len--;
	} return 0;
}
//int main() {
//	int round;
//	cin >> round;
//	int ret = 0;
//	round += 1;
//	while (round) {
//		string s = "";
//		getline(cin, s);
//		ret += plus_or_minus(s);
//		round--;
//	}
//	cout << ret;
//	getchar();
//	getchar();
//}