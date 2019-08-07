/**************************************************************************
** Program name: Lab 7  - QueueClass.cpp
** Author:       Jacob Hendry
** Date:         5/19/2019
** Description:  This cpp file will implement the protoypes from the queue
**               header file. It will describe the constructor, destructor,
**               functions such as isEmpty, addBack, or getFront. All of
**               the functions will be used in the menu function.
****************************************************************************/
#include <iostream>
#include "QueueClass.hpp"

using std::cout;
using std::endl;

/******************************************************
* This is the constructor of the QueueClass function
* that will initialize the head holder as a NULL
* value from the beginning.
*****************************************************/
Queue::Queue()
{
     head = NULL;
}

/*****************************************************
*This isEmpty function will be used in the program
*to determine if the queue is empty or not.
****************************************************/
bool Queue::isEmpty()
{
     if (head == NULL)
     {
          return true;
     }

     else
     {
          return false;
     }
}

/***************************************************
* This addBack function will add a positive integer
* inputted by the user to the queue.
***************************************************/
void Queue::addBack(int val)
{
     if (isEmpty())
     {
          head = new QueueNode;
          head->val = val;
          head->next = head;
          head->prev = head;
     }

     else
     {
          QueueNode *last = head->prev;

          QueueNode *node = new QueueNode;

          node->val = val;
          node->prev = last;
          node->next = head;

          last->next = node;
          head->prev = node;
     }
}
/**************************************************
* This getFront function will be used to return the
* head of the node to the menu.
**************************************************/
int Queue::getFront()
{
     if (isEmpty())
     {
          return -1;
     }

     else
     {
          return head->val;
     }
}

/**************************************************
* This removeFront function will be used to remove
* the head of the node.
**************************************************/
void Queue::removeFront()
{
     if (isEmpty())
     {
          cout << "The queue is empty!" << endl;
          return;
     }

     if (head == head->next)
     {
          head = NULL;

          cout << "The single node was deleted." << endl;
     }

     else
     {
          QueueNode *temp = head;
          head = head->next;
          head->prev = temp->prev;
          head->prev->next = head;
          delete temp;

          cout << "The front node was deleted." << endl;
     }
}

/********************************************************
* The printQueue function will be used to print each of
* the integers in the queue.
*******************************************************/
void Queue::printQueue()
{
     if (head == NULL)
     {
          cout << "The queue is empty!" << endl;
          return;
     }

     else
     {
          QueueNode *temp = head;

          while (temp->next != head)
          {
               cout << temp->val << " ";
               temp = temp->next;
          }

          cout << temp->val << endl;
     }

     cout << endl;
}

/********************************************************
* This is the destructor that will free all the memories
* of nodes in the queue.
*******************************************************/
Queue::~Queue()
{
     QueueNode *NodePtr = head;

     while (NodePtr != nullptr)
     {
          QueueNode *garbage = NodePtr;

          NodePtr = NodePtr->next;

          delete garbage;
     }
}