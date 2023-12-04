#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList();

    // Destructor to free memory
    ~LinkedList();

    // Insert a new element at the beginning of the list
    void insertFront(T value);

    // Display the elements in the list
    void display();

    // Check if the list is empty
    bool isEmpty();

    // Remove the element at the front of the list
    void removeFront();

    // Remove the element specified by the name
    void remove(string name);

    // Return the element specified by the name
    T get(string name);
};
