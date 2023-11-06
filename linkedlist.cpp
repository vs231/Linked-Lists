#include <iostream>
#include <vector>

class Node {
public:
    int row;
    int col;
    int value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int row, int col, int value) {
        Node* newNode = new Node(row, col, value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "No non-zero elements to display." << std::endl;
            return;
        }

        Node* current = head;

        std::cout << "row ";
        while (current) {
            std::cout << current->row << " ";
            current = current->next;
        }
        std::cout << std::endl;

        current = head;
        std::cout << "column ";
        while (current) {
            std::cout << current->col << " ";
            current = current->next;
        }
        std::cout << std::endl;

        current = head;
        std::cout << "value ";
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    std::cout << "Enter the matrix elements row by row:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    LinkedList linkedList;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = matrix[i][j];
            if (value != 0) {
                linkedList.insert(i, j, value);
            }
        }
    }

    std::cout << "Non-Zero Elements Table:" << std::endl;
    linkedList.display();

    return 0;
}