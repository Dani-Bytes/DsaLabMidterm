#pragma once
#include<iostream>
class Node {
public:
    int runs;
    int matchNumber;
    Node* next;
    Node* prev;

    Node(int r, int m) : runs(r), matchNumber(m), next(nullptr), prev(nullptr) {}
};
