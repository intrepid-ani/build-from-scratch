#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data;
  Node *next = nullptr;

  Node(int data)
  {
    this->data = data;
  }
};

class Queue
{
  Node *front;
  Node *rare;
  int length;

  bool add_to_empty(Node *newNode)
  {
    if (rare == nullptr)
    {
      front = rare = newNode;
      length += 1;
      return true;
    }

    return false;
  }

public:
  Queue(vector<int> elements = {})
  {
    front = rare = nullptr;
    length = 0;
    for (int element : elements)
    {
      this->enqueue(element);
    }
  }

  void print()
  {
    if (front == nullptr)
    {
      cout << "Empty List." << endl;
      return;
    }
    Node *temp = front;

    cout << "front -> ";
    while (temp != nullptr)
    {
      cout << temp->data << " - ";
      temp = temp->next;
    }

    cout << "end" << endl;
  }

  int size()
  {
    return length;
  }

  int get_front()
  {
    return this->front->data;
  }

  void enqueue(int data)
  {
    Node *newNode = new Node(data);
    if (this->add_to_empty(newNode))
      return;

    this->rare->next = newNode;
    this->rare = newNode;
    length += 1;

    return;
  }

  void dequeue()
  {
    Node *delete_this_element = front;

    front = delete_this_element->next;
    delete delete_this_element;

    length -= 1;
  }
};

int main()
{
  Queue qu({1, 2, 3, 4, 5, 12, 13, 14});
  qu.print();

  qu.dequeue();
  qu.dequeue();
  qu.dequeue();
  qu.print();
  return 0;
}