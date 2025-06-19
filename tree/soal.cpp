#include <iostream>
#include <queue> // Termasuk <queue> meskipun tidak digunakan langsung untuk BST traversal, sesuai format kode Anda sebelumnya.
using namespace std;

// Struktur untuk Node Binary Search Tree
// Menggunakan nama yang sama dengan 'TreeNode' agar konsisten dengan kode Anda.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menyisipkan node baru ke dalam Binary Search Tree (BST)
TreeNode* insert(TreeNode* root, int val) {
    // Jika tree kosong, buat node baru sebagai root
    if (root == nullptr) {
        return new TreeNode(val);
    }

    // Jika nilai lebih kecil, sisipkan di subtree kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Jika nilai lebih besar atau sama, sisipkan di subtree kanan
    else {
        root->right = insert(root->right, val);
    }
    return root; // Kembalikan root yang telah diperbarui
}

// Fungsi untuk mencetak binary tree dalam format Inorder (Left -> Root -> Right)
void inorder(TreeNode* root) {
    if (!root) return; // Basis rekursi: jika node null, berhenti
    inorder(root->left);   // Kunjungi subtree kiri
    cout << root->data << " "; // Cetak data node saat ini
    inorder(root->right);  // Kunjungi subtree kanan
}

// Fungsi untuk mencetak binary tree dalam format Preorder (Root -> Left -> Right)
void preorder(TreeNode* root) {
    if (!root) return; // Basis rekursi: jika node null, berhenti
    cout << root->data << " "; // Cetak data node saat ini
    preorder(root->left);   // Kunjungi subtree kiri
    preorder(root->right);  // Kunjungi subtree kanan
}

// Fungsi untuk mencetak binary tree dalam format Postorder (Left -> Right -> Root)
void postorder(TreeNode* root) {
    if (!root) return; // Basis rekursi: jika node null, berhenti
    postorder(root->left);   // Kunjungi subtree kiri
    postorder(root->right);  // Kunjungi subtree kanan
    cout << root->data << " "; // Cetak data node saat ini
}

// Fungsi utama
int main() {
    // Data untuk membangun Binary Search Tree
    int data[] = {7, 5, 12, 3, 6, 1, 4, 9};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array

    // Inisialisasi root tree sebagai nullptr (kosong)
    TreeNode* root = nullptr;

    // Membangun Binary Search Tree dengan menyisipkan setiap elemen data
    cout << "Membangun Binary Search Tree dengan data: ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
        root = insert(root, data[i]);
    }
    cout << endl << endl;

    // Melakukan Traversal Inorder
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Melakukan Traversal Preorder
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Melakukan Traversal Postorder
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    // CATATAN: Dalam aplikasi nyata, Anda harus menambahkan fungsi untuk
    // membersihkan memori yang dialokasikan untuk node-node tree (dealokasi)
    // untuk mencegah kebocoran memori (memory leak).
    // Untuk kesederhanaan contoh ini, kode dealokasi tidak disertakan.

    return 0;
}