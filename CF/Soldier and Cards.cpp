#include<bits/stdc++.h>

using namespace std;
int init_sacIO(deque<int>& q1, deque<int>& q2) {
	int times;
	cin >> times;
	int numberq1, numberq2;
	cin >> numberq1;
	while (numberq1--) {
		int tmp;
		cin >> tmp;
		q1.push_back(tmp);
	}
	cin >> numberq2;
	while (numberq2--) {
		int tmp;
		cin >> tmp;
		q2.push_back(tmp);
	}
	return times;
}

int movedeq(deque<int>& q1, deque<int>& q2) {
	map<deque<int>, deque<int>> m;
	/*volatile bool flag = ((q1[q1.size() - 1] > q2[q2.size() - 1] &&
		q2[q2.size() - 2] > q2[q2.size() - 1]))&& (q1.size() == 1 ||q2.size() == 1)||
		((q1[q1.size() - 1] < q2[q2.size() - 1]) && (q1[q1.size()-2] > q2[q2.size()-1]) && (q1.size() == 1 || q2.size() == 1));
	*/
	int count = 0;

	while (!(q1.empty() || q2.empty())) {

		if (q1[0] > q2[0]) {
			q1.push_back(q2.front()); q2.pop_front();
			q1.push_back(q1.front()); q1.pop_front();
			count++;
			cout << "        count : " << count << endl;
			if ((m[q1] == q2 || m[q2] == q1)&& !(q1.empty() || q2.empty())) return -1;
			else {
				m[q1] = q2; m[q2] = q1;
			}
		}

		else if (q1[0] < q2[0]) {
			q2.push_back(q1.front()); q1.pop_front();
			q2.push_back(q2.front()); q2.pop_front();
			count++;
			cout << "        count : " << count << endl;
			if ((m[q1] == q2 || m[q2] == q1)&&!(q1.empty() || q2.empty())) return -1;
			else {
				m[q1] = q2; m[q2] = q1;
			}
		}
		
	}return count;

}

//int main() {
//	deque<int> q1, q2;
//	init_sacIO(q1, q2);
//	int count = movedeq(q1, q2);
//	cout << count;
//	getchar();
//	getchar();
//	return 0;
//	
//}