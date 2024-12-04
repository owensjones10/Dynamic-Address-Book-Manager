#ifndef H_orderedLinkedList
#define H_orderedLinkedList

#include "linkedList.h"

template <typename T>
class orderedLinkedList : public linkedList<T>
{
public:
    void insert(const T &data)
    {
        typename linkedList<T>::Node *newNode = new typename linkedList<T>::Node(data);
        typename linkedList<T>::Node *prev = nullptr;
        typename linkedList<T>::Node *current = this->head;

        while (current && current->data < data)
        {
            prev = current;
            current = current->next;
        }

        if (!prev)
        {
            newNode->next = this->head;
            this->head = newNode;
            if (!this->tail)
                this->tail = newNode;
        }
        else
        {
            newNode->next = current;
            prev->next = newNode;
            if (!current)
                this->tail = newNode;
        }
    }
};

#endif