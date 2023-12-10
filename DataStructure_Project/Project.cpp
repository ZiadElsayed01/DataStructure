#include <iostream>
using namespace std;
#include "Project.h"

doctors_list::doctors_list()
{
  first = last = NULL;
  count = 0;
}

bool doctors_list::isEmpty()
{
  return (first == NULL);
}
void doctors_list::display()
{
  Node *temp = first;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

bool doctors_list::search(string D_name)
{
  Node *temp = first;
  while (temp != NULL)
  {
    if (temp->data == D_name)
    {
      return true;
    }
    else
    {
      temp = temp->next;
    }
    return false;
  }
}

void doctors_list::insertFirst(string D_name)
{
  Node *newNode = new Node();
  newNode->data = D_name;
  if (isEmpty())
  {
    first = last = newNode;
  }
  else
  {
    first->prev = newNode;
    newNode->next = first;
    newNode->prev = NULL;
    first = newNode;
  }
  count++;
}

void doctors_list::insertBetween(string item, string D_name)
{
  if (search(item))
  {
    Node *newNode = new Node();
    newNode->data = D_name;
    Node *temp = first;
    while (temp != NULL && temp->next->data != item)
    {
      temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    temp->next->prev = newNode;
  }
  else
  {
    cout << "Item Not Found" << endl;
  }
}

void doctors_list::insertLast(string D_name)
{
  Node *newNode = new Node();
  newNode->data = D_name;
  if (isEmpty())
  {
    first = last = newNode;
  }
  else
  {
    last->next = newNode;
    newNode->prev = last;
    newNode->next = NULL;
    last = newNode;
  }
  count++;
}

void doctors_list::deleteFirst()
{
  if (isEmpty())
  {
    cout << "Empty List!" << endl;
  }
  else if (count == 1)
  {
    delete first;
    delete last;
  }
  else
  {
    Node *temp = first;
    first = first->next;
    first->prev = NULL;
    delete temp;
  }
  count--;
}

void doctors_list::deleteBetween(string item)
{
  if (isEmpty())
  {
    cout << "Empty List!" << endl;
  }
  else if (!search(item))
  {
    cout << "Doctor Name Not Found!" << endl;
  }
  else
  {
    if (first->data == item)
    {
      deleteFirst();
    }
    else if (last->data == item)
    {
      deleteLast();
    }
    else
    {
      Node *temp = first;
      while (temp != NULL && temp->data != item)
      {
        temp = temp->next;
      }
      temp->prev->next = temp->next;
      temp->next->prev = temp->next;
      delete temp;
    }
  }
}

void doctors_list::deleteLast()
{
  if (isEmpty())
  {
    cout << "Empty List!" << endl;
  }
  else if (count == 1)
  {
    delete first;
    delete last;
  }
  else
  {
    Node *temp = first;
    last = last->next;
    last->next = NULL;
    delete temp;
  }
  count--;
}