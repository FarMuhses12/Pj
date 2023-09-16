#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return true; // число найдено
        }
        
        if (arr[mid] < target) {
            left = mid + 1; // искать в правой половине
        } else {
            right = mid - 1; // искать в левой половине
        }
    }
    
    return false; // число не найдено
}

int main() {
    int n, k;
    cout << "Введите два числа n и k: ";
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // генерация случайных чисел от 0 до 99
    }
    
    sort(arr.begin(), arr.end()); // сортировка массива
    
    for (int i = 0; i < k; i++) {
        int target;
        cout << "Введите целое число для проверки: ";
        cin >> target;
        
        if (binarySearch(arr, target)) {
            cout << "Число " << target << " содержится в массиве." << endl;
        } else {
            cout << "Число " << target << " не содержится в массиве." << endl;
        }
    }
    
    return 0;
}

