#include <iostream>

class Queue {
 public:
  Queue(int sz) {
    size = sz;
    front = -1;
    rear = -1;
    arr = new int[sz];
  }

  void Push(int elem);
  int Pop();
  void Print();

 private:
  int size;
  int front;
  int rear;
  int *arr;
};

void Queue::Push(int elem) {
  if (front == -1) {
    front = 0;
  }
  rear = (rear + 1) % size;
  arr[rear] = elem;
}

int Queue::Pop() {
  if (front == -1) {
    return -1;
  }
  int elem = arr[front];
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front = (front + 1) % size;
  }
  return elem;
}

void Queue::Print() {
  int i;
  for (i = front; i != rear; i = (i + 1) % size) {
    std::cout << arr[i] << " ";
  }
  std::cout << arr[i] << '\n';
}

int main() {
  int sz;
  std::cin >> sz;
  Queue q(sz);
  int n;
  std::cin >> n;
  std::string s;
  int x;
  for (int i = 0; i < n; ++i) {
    std::cin >> s;
    if (s == "push") {
      std::cin >> x;
      q.Push(x);
    } else if (s == "pop") {
      q.Pop();
    } else if (s == "print") {
      q.Print();
    }
  }
}