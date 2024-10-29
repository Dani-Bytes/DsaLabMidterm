#pragma once
#include"Node.h"
using namespace std;
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addRunsAtStart(int runs, int matchNumber) {
        Node* newNode = new Node(runs, matchNumber);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Added Match " << matchNumber << " with " << runs << " runs at the start.\n";
    }

    void addRunsAtEnd(int runs, int matchNumber) {
        Node* newNode = new Node(runs, matchNumber);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added Match " << matchNumber << " with " << runs << " runs at the end.\n";
    }

    void deleteAllOccurrences(int score) {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        Node* current = head;
        bool found = false;

        while (current) {
            if (current->runs == score) {
                found = true;
                Node* toDelete = current;

                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }

                current = current->next;
                delete toDelete;
            }
            else {
                current = current->next;
            }
        }

        if (found) {
            cout << "Deleted all occurrences of " << score << ".\n";
        }
        else {
            cout << "Score not found in any match.\n";
        }
    }

    void displayScoresForward() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        Node* current = head;
        cout << "Scores in forward order: ";
        while (current) {
            cout << "Match " << current->matchNumber << ": " << current->runs << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayScoresReverse() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        Node* current = tail;
        cout << "Scores in reverse order: ";
        while (current) {
            cout << "Match " << current->matchNumber << ": " << current->runs << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void findHighestAndLowestScores() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        int highest = head->runs;
        int lowest = head->runs;
        Node* current = head->next;

        while (current) {
            if (current->runs > highest) {
                highest = current->runs;
            }
            if (current->runs < lowest) {
                lowest = current->runs;
            }
            current = current->next;
        }

        cout << "Highest score: " << highest << ", Lowest score: " << lowest << endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
