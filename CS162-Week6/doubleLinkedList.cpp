/**************************************************************************
** Program name: Lab 6  - doubleLinkedList.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This file will hold the implementations for all of the 
**               function avaible to choose from in the menu besides the
**               traverse list function which will be implemented in the
**               add or delete functions. 
****************************************************************************/
#include <iostream>
#include "doubleLinkedList.hpp"

using std::cout;
using std::endl;

/******************************************************
* This is the constructor of the linkedlist function
* that will initialize the head and tail holders as a
* NULL from the beginning or unless all the values
* were deleted by the user.
*****************************************************/
LinkedList::LinkedList()
{
     head = NULL;
     tail = NULL;
}
/*****************************************************
*This addFront function will be used in the program
*to add a new node to the head (front) 
****************************************************/
void LinkedList::addFront(int val) 
{
     Node *n = new Node();
     n->val = val;
     
     if (tail == NULL) 
     {
          head = tail = n;
     }

     else 
     {
          n->next = head;
          head->prev = n;
          head = n;
     }

     this->traverseList();
}

/**************************************************
*This addback function will add a new value to
* the tail holder. 
***************************************************/
void LinkedList::addBack(int val) 
{
     Node *n = new Node();
     n->val = val;
     if (head == NULL) {
          head = tail = n;
     }
     else {
          n->prev = tail;
          tail->next = n;
          tail = n;
     }
     this->traverseList();
}

/**************************************************
*This deleteFront function will be used to delete
*the head of the node.
**************************************************/
int LinkedList::deleteFront()
{
     if (head == NULL)
     {
          return -1;
     }
     Node* tmp = head;
     if (head->next != NULL)
          head->next->prev = NULL;
     head = head->next;
     int val = tmp->val;
     this->traverseList();
     delete tmp;
     return val;
}

/*******************************************************
*This deleteBack function will delete the tail value
*when it is called from the menu function.
*******************************************************/
int LinkedList::deleteBack() 
{
     if (tail == NULL)
          return -1;
     Node* tmp = tail;
     if (tail->prev != NULL)
          tail->prev->next = NULL;
     tail = tail->prev;
     int val = tmp->val;
     this->traverseList();
     delete tmp;
     return val;
}

/**********************************************************
*This traverseReverse function will be used in the menu
*that will reverse the entire list to the exaxt opposite.
**********************************************************/
void LinkedList::traverseReverse()
{
     Node *tmp = tail;
     if (tmp == NULL) {
          cout << "The list is empty! Please add a value." << endl;
          return;
     }

     cout << "Your linked list: ";

     while (tmp != NULL)
     {
          cout << tmp->val << " ";
          tmp = tmp->prev;
     }
     cout << endl;
}

/********************************************************
*The traverseList function will be used most in the
*the program to show the user what is in their linked
*list.
*******************************************************/
void LinkedList::traverseList()
{
     Node *tmp = head;
     if (tmp == NULL) {
          cout << "The list is empty! Please add a value.";
          return;
     }
     cout << "Your linked list: ";

     while (tmp != NULL)
     {
          cout << tmp->val << " ";
          tmp = tmp->next;
     }
     cout << endl;
}

/***********************************************************
*This function will get the head value and return it to 
*show the user who wanted to see it
***********************************************************/
int LinkedList::getAtHead() 
{
     if (head == NULL)
          return -1;
     return head->val;
}

/*********************************************************
*This getAttail function will retrieve the value that is
*in the head spot on the list.
*********************************************************/
int LinkedList::getAtTail()
{
     if (tail == NULL)
          return -1;
     return tail->val;
}