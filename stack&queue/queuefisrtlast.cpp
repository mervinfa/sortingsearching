#include <iostream>
using namespace std;

// Struktur Node untuk queue
int count = 0;
const int MAX = 3;
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
List queue = {nullptr, nullptr, nullptr}; //head, front, rear

// Fungsi untuk mengecek apakah queue kosong
bool IsEmpty() {
    return queue.head == nullptr;
}

// Fungsi untuk mengecek apakah queue penuh (tidak relevan untuk linked list, jadi selalu false)
bool IsFull() {
    return count >= MAX;
}

// Fungsi untuk enqueue (menambahkan elemen di awal queue)
void Enqueue(string data) {
    Qnode* newNode = new Qnode;
    newNode->data = data;
    newNode->next = queue.head;
    if (IsFull()){
        cout << "queue penuh, tidak bisa menambah " << data<< endl;
        return;
    }
    if (IsEmpty()) {
        queue.head = newNode;
        queue.front = newNode;
        queue.rear = newNode;
    } else {
        queue.head = newNode;
        queue.rear = newNode;
    }
    count++;
    cout << "Enqueued: " << data << endl;

}

// Fungsi untuk dequeue (menghapus elemen dari akhir queue)
void Dequeue() {

    if (IsEmpty()) {
        cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
        return;
    }


    if (queue.head->next == nullptr) { // Jika hanya ada satu elemen di queue
        cout << "Dequeued 1: " << queue.rear->data << endl;
        Qnode* temp = queue.head;
        queue.head = nullptr;
        queue.rear = nullptr;
        queue.front = nullptr;
    }
    else {
        Qnode* current = queue.head;
        while (current->next != nullptr) {
            queue.front = current;
            current = current->next;
        }
        Qnode* temp = current;
        cout << "Dequeued 2: " << current->data << endl;
        queue.front->next = nullptr;
        delete temp;
        count--;
    }
}

 void insertBefore(string target, string dataBaru) {
    if (IsEmpty()) {
        cout << "Queue kosong, tidak bisa insert before" << endl;
        return;
    }

    if (IsFull()) {
        cout << "Queue penuh, tidak bisa insert sebelum " << target << endl;
        return;
    }

    Qnode* newNode = new Qnode;
    newNode->data = dataBaru;
    newNode->next = nullptr;

    // cout << queue.head->data;
    // Cek apakah target ada di head (paling depan)
    if (queue.head->data == target) {
        newNode->next = queue.head;
        queue.head = newNode;
        count++;
        cout << "Berhasil menyisipkan '" << dataBaru << "' sebelum '" << target << "' (di depan head)" << endl;
        return;
    }

    // Sisip di tengah (cari node sebelum target)
    Qnode* prev = queue.head;
    // Qnode* curr = queue.front->next;

    while (prev != nullptr) {
        if (prev->data == target) {
            prev->next = newNode;
            if(prev == queue.front)
            {
                queue.front = newNode;
            }
            cout << "Berhasil menyisipkan '" << dataBaru << "' sebelum '" << target << "'" << endl;
            return;
        }
        prev = prev->next;
        count++;
    }

    // Jika target tidak ditemukan
    cout << "Data '" << target << "' tidak ditemukan dalam queue" << endl;
    delete newNode;
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
        cout << "SISA: " << MAX-count << endl;
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
    Dequeue();
    displayQueue();

    insertBefore("2", "1");
    displayQueue();
    


    
    
    
    // // Dequeue beberapa elemen dari queue
    
   
    // Coba dequeue dari queue kosong
   

    return 0;
}
