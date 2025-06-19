#include <iostream>
using namespace std;

// Struktur Node untuk queue
struct Qnode {
    string data;
    Qnode* next;

};

// Struktur List untuk menyimpan head dan front dari queue
struct List {
    Qnode* head;//buat manggil
    Qnode* front;
    Qnode* rear;
};

// Inisialisasi queue
List queue = {nullptr, nullptr,nullptr};

// Fungsi untuk mengecek apakah queue kosong
bool IsEmpty() {
    return queue.head == nullptr;
}

// Fungsi untuk mengecek apakah queue penuh (tidak relevan untuk linked list, jadi selalu false)
bool IsFull() {
    return false;
}

// Fungsi untuk enqueue (menambahkan elemen di akhir queue)
void Enqueue(string data) {
    Qnode* newNode = new Qnode;
    newNode->data = data;
    newNode->next = nullptr;

    if (IsEmpty()) {
        queue.head = newNode;
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        Qnode* current = queue.head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        queue.rear = newNode;
    }
    cout << "Enqueued: " << data << endl;
}

// Fungsi untuk dequeue (menghapus elemen dari awal queue)
void Dequeue() {
    if (IsEmpty()) {
        cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
        return;
    }
    Qnode* temp = queue.head;
    queue.head = queue.head->next;
    if (queue.head == nullptr) { // Jika queue menjadi kosong setelah dequeue
        queue.rear = nullptr;
        queue.front = nullptr;
    }else{
        queue.front = queue.head;
    }
    cout << "Dequeued: " << temp->data << endl;
    delete temp;
}

void insertAfter(string searchValue, string newData) {
    if (IsEmpty()) {
        cout << "Queue kosong, tidak bisa menyisipkan " << newData << " setelah " << searchValue << endl;
        return;
    }

    Qnode* current = queue.head;
    // Iterasi untuk mencari searchValue
    while (current != nullptr && current->data != searchValue) {
        current = current->next;
    }

    if (current == nullptr) {
        // Jika searchValue tidak ditemukan
        cout << "Nilai " << searchValue << " tidak ditemukan dalam queue. Tidak bisa menyisipkan " << newData << endl;
        return;
    }

    // searchValue ditemukan, sisipkan newNode setelah current
    Qnode* newNode = new Qnode;
    newNode->data = newData;
    newNode->next = current->next; // newNode menunjuk ke node setelah current

    current->next = newNode; // current menunjuk ke newNode

    // Jika current adalah rear, maka newNode adalah rear yang baru
    if (current == queue.rear) {
        queue.rear = newNode;
    }

    cout << "Disisipkan: " << newData << " setelah " << searchValue << endl;
}


// Fungsi untuk menampilkan isi queue
void displayQueue() {
    if (IsEmpty()) {
        cout << "Queue kosong" << endl;
        return;
    }
    Qnode* current = queue.head;
    cout << "Isi queue:" << endl;
    while (current != nullptr) {
        cout << "Front: " << queue.front->data << endl;
        cout << "Rear: " << queue.rear->data << endl;
        cout << "Alamat: " << current << endl;
        cout << "Nilai: " << current->data << endl;
        cout << "Alamat next: " << current->next << endl << endl;
        current = current->next;
    }
    cout << endl << "---------------------------------------" <<endl;
}

int main() {
    // Memastikan queue kosong
    if (IsEmpty()) {
        cout << "Queue baru saja diinisialisasi dan kosong." << endl;
    }

    // Enqueue beberapa elemen ke dalam queue
    Enqueue("7");
    displayQueue();
    Enqueue("2");
    displayQueue();
    Enqueue("4");
    displayQueue();
    Enqueue("1");
    displayQueue();


    // // Dequeue beberapa elemen dari queue
    Dequeue();
    displayQueue();

    insertAfter("2", "1");
    // // Coba dequeue dari queue kosong
    // Dequeue();

    return 0;
}
