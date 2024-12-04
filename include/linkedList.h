#ifndef H_linkedList
#define H_linkedList

#include <iostream>
#include <functional>

template <typename T>
class linkedList
{
protected:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &data) : data(data), next(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    linkedList() : head(nullptr), tail(nullptr) {}
    ~linkedList() { clear(); }

    void insert(const T &data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(const T &data)
    {
        Node *prev = nullptr, *current = head;

        while (current && current->data != data)
        {
            prev = current;
            current = current->next;
        }

        if (!current)
            return;

        if (!prev)
        {
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }

        if (current == tail)
        {
            tail = prev;
        }

        delete current;
    }

    void traverse(std::function<void(const T &)> func) const
    {
        Node *current = head;
        while (current)
        {
            func(current->data);
            current = current->next;
        }
    }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

#endif