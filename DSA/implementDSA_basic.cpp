// #include<bits/stdc++.h>
// using namespace std;


#include <iostream>

// Node structure for LinkedList, Stack, and Queue
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList implementation
template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // Append a new node with the given value to the end of the list.
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the elements of the linked list.
    void display() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

private:
    Node<T>* head;
};

// Stack implementation
template<typename T>
class Stack {
public:
    Stack() : top(nullptr) {}

    // Push a new element onto the top of the stack.
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Remove the element at the top of the stack.
    void pop() {
        if (top) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Return the element at the top of the stack without removing it.
    T peek() const {
        if (top) {
            return top->data;
        }
        throw std::runtime_error("Stack is empty");
    }

    // Check if the stack is empty.
    bool isEmpty() const {
        return top == nullptr;
    }

private:
    Node<T>* top;
};

// Queue implementation
template<typename T>
class Queue {
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Add a new element to the rear of the queue.
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove the element at the front of the queue.
    void dequeue() {
        if (front) {
            Node<T>* temp = front;
            front = front->next;
            if (!front) {
                rear = nullptr;
            }
            delete temp;
        }
    }

    // Return the element at the front of the queue without removing it.
    T peek() const {
        if (front) {
            return front->data;
        }
        throw std::runtime_error("Queue is empty");
    }

    // Check if the queue is empty.
    bool isEmpty() const {
        return front == nullptr;
    }

private:
    Node<T>* front;
    Node<T>* rear;
};

int main() {
    // Example usage of LinkedList, Stack, and Queue
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.display();

    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Stack top: " << stack.peek() << "\n";
    stack.pop();
    std::cout << "Stack top after pop: " << stack.peek() << "\n";

    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue front: " << queue.peek() << "\n";
    queue.dequeue();
    std::cout << "Queue front after dequeue: " << queue.peek() << "\n";

    return 0;
}
