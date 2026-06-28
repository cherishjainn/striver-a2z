#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
    vector<int> ans;
    int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            if (ans.empty() || ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }
        else {
            if (ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n) {
        if (ans.empty() || ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        if (ans.empty() || ans.back() != arr2[j])
            ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5};

    vector<int> result = findUnion(arr1, arr2);

    cout << "Union: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}