#include <bits/stdc++.h>
using namespace std;
 
int cnt;                
void Merge(vector<int> &a,vector<int> &b, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;                      
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        }
        else {
            cnt += j - k;
            b[k++] = a[j++];
        }
    }
    while (i <= mid){
        b[k++] = a[i++];
    }
    while (j <= end){
        b[k++] = a[j++];
    }
    for (int i = start; i <= end; i++){
        a[i] = b[i];
    }
}

void MergeSort(vector<int> &a, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, start, mid, end);
    }
}
int main() {
    static const auto io_sync_off = [](){
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return nullptr;
    }();
    int n; 
    while (cin >> n) { 
        long num = pow(2, n);
        vector<int> a(num);    
        vector<int> b(num);    
        for (int i = 0; i < num; i++) {
            cin >> a[i];
        }
        // q
        int m;
        cin >> m;
        while (m--) {
            int q;
            cnt = 0;
            int pos = 0;
            cin >> q;
            int bias = pow(2, q);
            if (bias <= num && bias != 1) {
                while (pos + bias < num) {
                    reverse(a.begin() + pos, a.begin() + pos + bias);
                    pos += bias;
                }
                reverse(a.begin() + pos, a.begin() + num);
            }
            auto tmp_a = a;
            MergeSort(tmp_a, 0, num - 1);
            cout << cnt << endl;
        }
    }
    return 0;
}