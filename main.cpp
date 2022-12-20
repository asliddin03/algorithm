#include <iostream>

class Queue{
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
  int* arr;
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
  Queue q(10);
  for (int i = 0; i < 10; ++i) {
    int x;
    int y;
    std::cin >> x >> y;
    if (x == 1) {
      q.Push(y);
    } else if (x == 2) {
      q.Pop();
    } else {
      q.Print();
    }
  }
}