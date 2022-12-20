#include <iostream>
#include <vector>

void Merge(std::vector<int>& arr, int first, int mid, int last) {
  int first_1 = first;
  int last_1 = mid + 1;
  int ind = 0;
  std::vector<int> arr_1(last - first + 1);
  while (first_1 <= mid && last_1 <= last) {
    if (arr[first_1] < arr[last_1]) {
      arr_1[ind++] = arr[first_1];
      first_1++;
    } else {
      arr_1[ind++] = arr[last_1];
      last_1++;
    }
  }
  while (first_1 <= mid) {
    arr_1[ind++] = arr[first_1];
    first_1++;
  }
  while (last_1 <= last) {
    arr_1[ind++] = arr[last_1];
    last_1++;
  }
  for (int i = 0; i <= last - first; ++i) {
    arr[first + i] = arr_1[i];
  }
  arr_1.clear();
}

void Sort(std::vector<int>& arr, int first, int last) {
  if (first == last) {
    return;
  }
  int mid = (first + last) / 2;
  Sort(arr, first, mid);
  Sort(arr, mid + 1, last);
  Merge(arr, first, mid, last);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  Sort(arr, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}