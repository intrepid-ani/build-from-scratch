#include <iostream>
#include <vector>
#include <errorrep.h>
#include <stdexcept>

using namespace std;

class Node
{
public:
  int val;
  Node *nextPointer;
  Node(int val)
  {
    this->val = val;
    this->nextPointer = NULL;
  }
};

class List
{
  Node *head;
  Node *tail;
  int length;

public:
  List(vector<int> input = {})
  {
    head = tail = NULL;
    length = 0;

    if (input.empty())
      return;

    for (int i : input)
    {
      this->push_back(i);
    }
  }

  int size()
  {
    return length;
  }

  void push_back(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->nextPointer = newNode;
      tail = newNode;
    }

    length += 1;
  }

  void push_front(int val)
  {

    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->nextPointer = head;
      head = newNode;
    }

    length += 1;
  }

  void pop_back()
  {
    if (head == NULL)
      throw runtime_error("Invalid pop request, List is empty.");

    Node *temp = head;

    while (temp->nextPointer != tail)
    {
      temp = temp->nextPointer;
    }

    Node *itemToPop = tail;
    tail = temp;
    tail->nextPointer = NULL;

    delete itemToPop;
    length -= 1;
  }

  void pop_front()
  {
    if (head == NULL)
      throw runtime_error("Invalid pop request, List is empty.");

    Node *element = head;

    head = head->nextPointer;
    delete element;

    length -= 1;
  }

    void insert(int val, int pos)
  {
    if (pos >= length || pos < 0)
      throw out_of_range("Invalid position to insert node.");

    Node *newNode = new Node(val);
    int count = 0;
    Node *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
      temp = temp->nextPointer;
    }

    newNode->nextPointer = temp->nextPointer;
    temp->nextPointer = newNode;

    length++;
  }

  void print()
  {
    if (head == NULL)
    {
      cout << "Empty List." << endl;
      return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->val << "-> ";
      temp = temp->nextPointer;
    }

    cout << "NULL" << endl;
    cout << "Size: " << this->size();
  }

  Node search(int val)
  {
    Node *temp = head;
    while (temp != NULL)
    {
      if (temp->val == val)
        return *temp;

      temp = temp->nextPointer;
    }

    return NULL;
  }
};

int main()
{
  List *ll = new List({0, 1, 2, 3, 4, 5, 6, 7, 8});

  ll->pop_back();
  ll->pop_front();

  ll->push_front(0);
  ll->push_back(9);

  ll->insert(55, 5);

  Node l = ll->search(55);

  ll->print();

  cout << "\nFound element: " << l.val << endl;

  return 0;
}