#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort(vector<int> nums) {
    vector<int> arr = nums;
    int count = 0;
    while (count < arr.size()) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        count++;
    }
    return arr;
}

int main() {
    int n;
    cout << "Enter size of Array: ";
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    vector<int> output = BubbleSort(arr);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}

