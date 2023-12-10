#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
  string data;
  Node *prev;
  Node *next;
};

class doctors_list
{
public:
  int count;
  Node *first;
  Node *last;

  doctors_list();

  bool isEmpty();
  bool search(string D_name);
  void display();

  void insertFirst(string D_name);
  void insertBetween(string item, string D_name);
  void insertLast(string D_name);

  void deleteFirst();
  void deleteBetween(string item);
  void deleteLast();
};
#endif