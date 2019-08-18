#include<bits/stdc++.h>
#include<xtree>
#include<map>
#include<unordered_map>
#include<typeinfo>
#include<functional>

using namespace std;
int Domino_piling(int m, int n) {
	return m * n < 2 ? 0 : m * n / 2;

}


int main() {
	int m, n;
	cin >> m >> n;
	cout << Domino_piling(m, n);
	return 0;
}