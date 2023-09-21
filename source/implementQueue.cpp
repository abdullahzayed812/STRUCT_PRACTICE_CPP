#include <iostream>

using namespace std;

template <typename T>
struct Queue {
  T arr[100];
  int len;

  Queue();
  void addEnd(const T& element);
  void addFront(const T& element);
  T removeFront();
  void removeBack();
  void print();
};

template <typename T>
Queue<T>::Queue() {
  this->len = 0;
}

template <typename T>
void Queue<T>::addEnd(const T& element) {
  this->arr[len++] = element;
}

template <typename T>
void Queue<T>::addFront(const T& element) {
  for (int i = this->len - 1; i >= 0; i--) this->arr[i + 1] = this->arr[i];

  arr[0] = element;
  this->len++;
}

template <typename T>
T Queue<T>::removeFront() {
  T ret = this->arr[0];
  for (int i = 1; i < this->len; i++) {
    this->arr[i - 1] = this->arr[i];
  }
  this->len--;
  return ret;
}

template <typename T>
void Queue<T>::removeBack() {
  this->len--;
}

template <typename T>
void Queue<T>::print() {
  cout << "Queue element: ";
  for (int i = 0; i < this->len; i++) {
    cout << this->arr[i] << " ";
  }
  cout << "\n";
}

int main() {
  Queue<int> myQueue;

  myQueue.addFront(10);
  myQueue.addFront(20);
  myQueue.addFront(30);
  myQueue.addFront(40);

  myQueue.addEnd(5);
  myQueue.addEnd(2);
  myQueue.print();  // 40, 30, 20, 10, 5, 2

  myQueue.removeBack();
  myQueue.print();  // 40, 30, 20, 10, 5

  myQueue.removeFront();
  myQueue.print();  // 30, 20, 10, 5, 2

  return 0;
}
