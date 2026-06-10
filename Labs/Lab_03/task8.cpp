#include <iostream>
using namespace std;

class Node {
public:
    int position;
    Node* next;
    
    Node(int pos) {
        position = pos;
        next = nullptr;
    }
};

class CircularList {
private:
    Node* head;
    int size;
    
public:
    CircularList(int n) {
        head = nullptr;
        size = n;
        
        for (int i = n - 1; i >= 0; i--) {
            Node* newNode = new Node(i);
            if (head == nullptr) {
                head = newNode;
                head->next = head;
            } else {
                newNode->next = head->next;
                head->next = newNode;
            }
        }
    }
    
    int eliminate(int m) {
        Node* current = head;
        Node* prev = nullptr;
        
        while (size > 1) {
            for (int i = 1; i < m; i++) {
                prev = current;
                current = current->next;
            }
            
            prev->next = current->next;
            Node* temp = current;
            current = current->next;
            delete temp;
            size--;
            
            if (size == 1) {
                head = current;
            }
        }
        
        return head->position;
    }
    
    ~CircularList() {
        if (head != nullptr) {
            Node* current = head->next;
            while (current != head) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
        }
    }
};

class JosephusSolver {
private:
    int n;
    int m;
    
public:
    JosephusSolver(int people, int step) {
        n = people;
        m = step;
    }
    
    int calc(int people) {
        if (people == 1) {
            return 0;
        }
        return (calc(people - 1) + m) % people;
    }
    
    int getSafePos() {
        return calc(n);
    }
    
    int solveUsingList() {
        CircularList circle(n);
        return circle.eliminate(m);
    }
};

int main() {
    cout << "Josephus Survival Game\n\n";
    
    cout << "Warm-up: n = 5, m = 2\n";
    JosephusSolver s1(5, 2);
    cout << "Safe position: " << s1.getSafePos() << "\n\n";
    
    cout << "Medium: n = 10, m = 4\n";
    JosephusSolver s2(10, 4);
    cout << "Safe position: " << s2.getSafePos() << "\n\n";
    
    cout << "Hard: n = 41, m = 3\n";
    JosephusSolver s3(41, 3);
    cout << "Safe position: " << s3.getSafePos() << "\n\n";
    
    cout << "Example: n = 7, m = 3\n";
    JosephusSolver s4(7, 3);
    cout << "Safe position: " << s4.getSafePos() << "\n\n";
    
    return 0;
}