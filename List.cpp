#include "List.h"
#include "Business.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

// Destructor to free memory
template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

// Insert a new element at the beginning of the list
template <typename T>
void LinkedList<T>::insertFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

// Display the elements in the list
template <typename T>
void LinkedList<T>::display() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << "Business Name: " << current->data->getName() << "\n\tHours of operation: ";
        for (int i = 0; i < 7; i++) {
			cout << current->data->getHoursOfOperation()[i] << " ";
		}
        cout << "\n\tAddress: " << current->data->getAddress() << "\n\tPhone Number: " << current->data->getPhoneNumber() << "\n\tBusiness Type: " << current->data->getTypeOfBusiness() << "\n\tAverage Rating: " << current->data->getAverageRating() << endl << endl;
        current = current->next;
    }
    cout << endl;
}

// Check if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

// Remove the element 
template <typename T>
void LinkedList<T>::removeFront() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Return the element specified by the name
template <typename T>
T LinkedList<T>::get(string name) {
    if (!isEmpty()) {
		Node<T>* current = head;
        while (current != nullptr) {
            if (current->data->getName() == name) {
				return current->data;
			}
			current = current->next;
		}
	}
	return nullptr;
}

// Remove the element specified by the name
template <typename T>
void LinkedList<T>::remove(string name) {
    if (!isEmpty()) {
		Node<T>* current = head;
		Node<T>* previous = nullptr;
        while (current != nullptr) {
            if (current->data->getName() == name) {
                if (previous == nullptr) {
					head = current->next;
				}
                else {
					previous->next = current->next;
				}
				delete current;
				return;
			}
			previous = current;
			current = current->next;
		}
	}
}

template class LinkedList<Business*>;