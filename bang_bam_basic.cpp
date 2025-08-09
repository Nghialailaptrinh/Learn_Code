
//
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip>
//
#define true 1
#define false 0
#define M 10
//
using namespace std;

struct node {
	int key;
	node* next;
};

node* H[M];

//Hash funtion
int h(int x) {
	return(x % M);    //Bảng băm phân bố đều
}

//Xóa hash table(giải phóng tất cả các nút)
void clear(node*& phead) {
	node* p, * p1;
	p = phead;
	while (p != nullptr) {
		p1 = p;
		p = p->next;
		delete p1;
	}
	phead = nullptr;
}

//Khỏi tạo danh sách
void init(node* &phead) {
	clear(phead);
	phead = nullptr;
}

// tìm khóa x
node* search(node* &phead, int x) {
	node* p = phead;
	while (p != nullptr) {
		if (p->key == x)return p;
		p = p->next;
		}
	return nullptr;
}

//Chèn x vào hash table do phead trỏ đến
void insert(node* &phead, int x) {
	node*pp, *p, * p1;
	p = search(phead, x);
	if (p != nullptr) {
		cout << "\nKhoa " << x << " da co trong danh sach"; return;
	}
	pp = new node;
	pp->key = x; pp->next = nullptr;
	if (phead == nullptr) { phead = pp; return; }
	p1 = nullptr;
	p = phead;
	while (p != nullptr) {
		p1 = p;
		p = p->next;
	}
	p1->next = pp;
}

//Kiểm tra xem hash table có rỗng không
bool empty(node* phead) {
	return (phead == nullptr);
}

//xoá x tròn hash table
void dele(node*& phead, int x) {
	node* p, * p1, * q;
	if (phead == nullptr) return; 
	if (phead->key == x) {
		p = phead; phead = phead->next; delete p; return;
	}
	p1 = nullptr;
	p = phead;
	while (p != nullptr) {
		if (p->key == x) {
			q = p; p1->next = p->next; delete q; return;
		}
		p1 = p;
		p = p->next;
	}
	cout << "\nKhoa " << x << " khong co trong hash table, khong xoa duoc";
}

//Duyệt hash table do phead chỉ đến

void traverse(node* phead) {
	node* p = phead;
	while (p != nullptr) {
		cout << p->key <<" ";
		p = p->next;
	}
}

///////         /////////////          ///////////////            ///////////
//Khỏi tạo mảng băm
void init() {
	for (int i = 0; i < M; i++) {
		init(H[i]);
	}
}

//Chèn x vào mảng băm
void insert(int x) {
	int k = h(x);
	insert(H[k], x);
}

//Tìm khóa x trong mảng băm
node* search(int x) {
	int k = h(x); node* p;
	p = search(H[k], x);
	return p;
}

//Kiểm tra mảng băm co rỗng không
bool empty() {
	for (int i = 0; i < M; i++) {
		if (!empty(H[i]))return false;
		return true;
	}
}
//Xóa khóa x
void dele(int x) {
	int k = h(x);
	dele(H[k], x);
}

//Xóa mảng băm
void clear() {
	for (int i = 0; i < M; i++) {
		clear(H[i]);
	}
}

//Duyệt mảng băm
void traverse() {
	int i;
	cout << "\n\n   DIA CHI           CAC KHOA";
	for (i = 0; i < M; i++) {
		cout << "\n" << setw(8) << i << "\t"; traverse(H[i]);
	}
}


void data_input() {
	system("CLS");
	int m, i, x; init();
	cout << "\n Nhap du lieu vao mbang bam: ";
	cout << "\n 1. Nhap truc tiep bang tay.";
	cout << "\n 2.Nhap ngau nhien.";

	cout << "\n Bam 1 hoac 2 de lua chon: ";
	char ch = _getch();

	cout << "\n Cho biet so phan tu can nhap vao mang bam: ";
	cin >> m;
	if (ch == '1') {
		cout << "\n Hay nhap so " << m;
		for (i = 0; i < m; i++) { cin >> x; insert(x); }
	}
	else {
		srand( time(0));
		for (i = 0; i < m; i++) {
			x = rand() % (10 * m);
			insert(x);
		}

	}
}

int main() {
	system("CLS");
	int x=0, k=0; node* p=nullptr;
	while (true) {
		cout << "\n 1. Chen khoa x vao bang bam";
		cout << "\n 2. Tim mot khoa tren mang bam";
		cout << "\n 3. Xoa mot khoa tren mang bam";
		cout << "\n 4. Duyet bang bam";
		cout << "\n 5. Xoa toan bo mang bam";
		cout << "\n 0. Ket thuc";
		cout << "\n Chon phim bat ky tu 1->0 de chon viec!";
		char chon = _getch();
		if (chon == '0') return 0;
		switch (chon) {
		case '1': data_input(); break;
		case '2': cout << "\n Phan tu can tim la: "; int x;  cin >> x; k = h(x); p = search(x); if (p != nullptr)cout << "\n Phan tu tim thay o vi tri: " << p->key;
				else cout << "\n Khong tim thay";
			break;
		case '3': cout << "\n Phan tu can xoa la: "; cin >> x;
			dele(x);
			cout << "\nDa xoa " << x; break;
		case '4': if (empty())cout << "\n Bang bam rong";
				else traverse(); break;
		case '5': clear(); cout << "\n";
			cout << "Da xoa ton bo bang bam. Go 4 de xem!"; break;
		default: break;
		}
		cout << "\n Nhan phim bat ky de tiep tuc";
		_getch();
	}
	return 0;
}