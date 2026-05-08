// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* create(const T& data) {
        return new Node{data, nullptr};
    }

public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(const T& data) {
        Node* item = create(data);
        if (!head || data.prior > head->data.prior) {
            item->next = head;
            head = item;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->data.prior >= data.prior) {
            cur = cur->next;
        }
        item->next = cur->next;
        cur->next = item;
    }
    T pop() {
        if (!head) {
            throw "PQueue empty!";
        }
        Node* temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        return data;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
