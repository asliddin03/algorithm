#include <iostream>
#include <vector>

void SiftUp(std::vector<int>& arr, int pos) {
  int i = pos;
  while (i > 0 && arr[i] < arr[(i - 1) / 2]) {
    std::swap(arr[i], arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void SiftDown(std::vector<int>& arr, int pos) {
  int j;
  int left;
  int right;
  int sz = arr.size();
  while (2 * pos + 1 < sz) {
    left = 2 * pos + 1;
    right = 2 * pos + 2;
    j = left;
    if (2 * pos + 2 < sz && arr[j] > arr[2 * pos + 2]) {
      j = right;
    }
    if (arr[pos] <= arr[j]) {
      break;
    }
    std::swap(arr[pos], arr[j]);
    pos = j;
  }
}

void Insert(std::vector<int>& arr, int value) {
  arr.push_back(value);
  SiftUp(arr, arr.size() - 1);
}

int ExtractMin(std::vector<int>& arr) {
  int mn = arr[0];
  arr[0] = arr[arr.size() - 1];
  arr.pop_back();
  SiftDown(arr, 0);
  return mn;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr;
  int val;
  for (int i = 0; i < n; ++i) {
    std::cin >> val;
    Insert(arr, val);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ExtractMin(arr) << " ";
  }
  std::cout << '\n';
  return  0;
}