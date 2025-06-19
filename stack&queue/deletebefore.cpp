
#include <iostream>
#include <cstdlib>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}


// Fungsi untuk menampilkan informasi tentang setiap node dalam linked list
void displayList(Node* head) {
    Node* current = head;
    cout << "Informasi tentang setiap node:" << endl;
    while (current != nullptr) {
        cout << "Alamat: " << current << endl;
        cout << "Nilai: " << current->data << endl;
        cout << "Alamat prev: " << current->prev << endl;
        cout << "Alamat next: " << current->next << endl << endl;
        current = current->next;
    }
    cout << "---------------------------------------" <<endl;
}

// Fungsi untuk menghapus node setelah node dengan nilai tertentu dari linked list
void deleteBefore(Node*& head, int valueToDeleteBefore) {
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada yang dihapus" << endl;
        return;
    }

    Node* current = head;

    // Mencari node dengan nilai tertentu
    while (current != nullptr && current->data != valueToDeleteBefore) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node dengan nilai " << valueToDeleteBefore << " tidak ditemukan" << endl;
        return;
    }

    if (current->prev == nullptr) {
        cout << "Tidak ada node sebelum node dengan nilai " << valueToDeleteBefore << endl;
        return;
    }

    // Hapus node sebelum current
    Node* temp = current->prev;

    if (temp->prev != nullptr) {
        temp->prev->next = current;
        current->prev = temp->prev;
    } else {
        // Node yang dihapus adalah head
        head = current;
        current->prev = nullptr;
    }

    delete temp;
    cout << "Node sebelum " << valueToDeleteBefore << " telah dihapus" << endl;
}




// Fungsi untuk menyisipkan node sebagai elemen pertama dalam linked list
void insertFirst(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode; // Jika linked list kosong, node baru menjadi head
    } else {
        newNode->next = head;
        head->prev = newNode; // Mengatur prev dari head menjadi node baru
        head = newNode; // Mengatur node baru sebagai head
    }
}

int main() {
    // Menggunakan sistem untuk membersihkan layar konsol
    system("clear");  // Untuk sistem Unix/Linux
    // system("cls"); // Untuk sistem Window

    // Inisialisasi pointer simpul
    Node* head = nullptr;

    head =  createNode(5);
    displayList(head);

    insertFirst(head, 7);
    displayList(head);

    insertFirst(head, 8);
    displayList(head);

    deleteBefore(head , 7);
    displayList(head);
    return 0;
}
