#include <iostream>

using namespace std;

class ListNode
{
public:
  int val;
  ListNode *previous;
  ListNode *next;

  ListNode(int data)
  {
    previous = next = nullptr;
    this->val = data;
  }
};

class List
{
  ListNode *head;
  ListNode *tail;
  int length = 0;
  bool add_to_empty(int data)
  {
    ListNode *newNode = new ListNode(data);
    if (head == nullptr)
    {
      head = tail = newNode;
      length += 1;
      return true;
    }
    return false;
  }

public:
  List()
  {
    head = tail = nullptr;
  };

  int size()
  {
    return this->length;
  }

  void push_front(int data)
  {
    bool result = this->add_to_empty(data);
    if (result)
      return;

    ListNode *newNode = new ListNode(data);

    head->previous = newNode;
    newNode->next = head;
    head = newNode;

    length += 1;
  }

  void push_back(int data)
  {
    bool result = this->add_to_empty(data);
    if (result)
      return;

    ListNode *newNode = new ListNode(data);

    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;

    length += 1;
  }

  void pop_back()
  {
    if (head == NULL)
      throw runtime_error("Invalid pop request, List is empty.");

    ListNode *temp = head;

    while (temp->next != tail)
    {
      temp = temp->next;
    }

    ListNode *itemToPop = tail;
    tail = temp;
    tail->next = NULL;

    delete itemToPop;
    length -= 1;
  }

  void pop_front()
  {
    if (head == NULL)
      throw runtime_error("Invalid pop request, List is empty.");

    ListNode *element = head;

    head = head->next;
    delete element;

    length -= 1;
  }

  void print(bool reverse = false)
  {
    if (reverse)
    {
      ListNode *i = tail;
      while (i != nullptr)
      {
        cout << i->val << " <-> ";
        i = i->previous;
      }
    }
    else
    {
      ListNode *i = head;
      while (i != nullptr)
      {
        cout << i->val << " <=> ";
        i = i->next;
      }
    }

    cout << "null" << endl;
    cout << "Size: " << this->size() << endl;
  }
};

int main()
{
  List *dl = new List();
  dl->push_back(1);
  dl->push_back(2);
  dl->push_front(3);
  dl->push_front(4);
  dl->push_back(9);
  dl->pop_back();
  dl->pop_front();

  dl->print();
  return 0;
}