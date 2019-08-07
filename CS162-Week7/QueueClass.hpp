/**************************************************************************
** Program name: Lab 7  - QueueClass.hpp
** Author:       Jacob Hendry
** Date:         5/19/2019
** Description:  This file will hold the prototypes for the functions that
**               will be implemented in the cpp file for the queueNode struct
**               and queue class. 
****************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

struct QueueNode
{
public:
     int val;
     QueueNode* next;
     QueueNode* prev;
};

class Queue
{
private:
     QueueNode *head;
public:
     Queue();
     bool isEmpty();
     void addBack(int val);
     int getFront();
     void removeFront();
     void printQueue();
     ~Queue();
};

#endif