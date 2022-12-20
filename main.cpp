#include <iostream>
#include <string>

struct Node {
  int value;
  Node* next;
  Node* prev;
};

class List {
 public:
  List() : head(nullptr), tail(nullptr) {};
  ~List();
  void Show();
  void Add(int value);
 private:
  Node* head;
  Node* tail;
};

List::~List() {
  while (head != nullptr) {
    tail = head->next;
    delete head;
    head = tail;
  }
}

void List::Add(int value) {
  Node* temp = new Node;
  temp->next = nullptr;
  temp->value = value;
  if (head != nullptr) {
    temp->prev = head;
    tail->next = temp;
    tail = temp;
  } else {
    temp->prev = nullptr;
    head = tail = temp;
  }
}

void List::Show() {
  Node* temp = tail;
  while (temp != nullptr) {
    std::cout << temp->value << " ";
    temp = temp->prev;
  }
  std::cout << '\n';

  temp = head;
  while (temp != nullptr) {
    std::cout << temp->value << " ";
    temp = temp->next;
  }
  std::cout << '\n';
}

int main() {
  List list;
  int n;
  std::cin >> n;
  std::string s;
  int val;
  for (int i = 0; i < n; ++i) {
    std::cin >> s;
    if (s == "add") {
      std::cin >> val;
      list.Add(val);
    } else if (s == "show"){
      list.Show();
    }
  }
}