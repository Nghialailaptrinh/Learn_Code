//Tạo bảng băm dùng phương pháp băm đôi
//
#include<iostream>
#include<conio.h>
#include<stdio.h>
#define MIN_TABLE_SIZE 10
//Taọ bảng băm dùng phương pháp dò bậc hai để khử đựng độ

using namespace std;

enum entry_type {
	Legitimate,
	Empty,
	Deletedu
};

struct hash_node {
	int element;
	enum entry_type info;
};

struct hash_table {
	int size;
	hash_node* table;
};

//Check so nguyen to
bool is_prime(int n) {
	if (n == 2 || n == 3)return true;
	if (n == 1 || n % 2 == 0)return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)return false;
	}
	return true;
}

//tim so nguyen to tiep theo
int next_prime(int n) {
	if (n <= 0) n = 3;
	if (n % 2 == 0)n++;
	for (; !is_prime(n); n += 2);
	return n;
}

int hash_func1(int key, int size) {
	return key % size;
}
int hash_func2(int key, int size) {
	return size/2 +1;
}

hash_table* init_table(int size) {
	hash_table* htable;
	if (size < MIN_TABLE_SIZE) {
		cout << "Kich thuoc mang bam qua nho!" << endl;
		return nullptr;
	}
	htable = new hash_table;
	if (htable == nullptr) {
		cout << "Ngoai phan vi\n";
		return nullptr;
	}
	htable->size = next_prime(size);
	htable->table = new hash_node[htable -> size];
	if (htable->table == nullptr) {
		cout << "Kich thuoc mang bawm qua nho\n";
		return nullptr;
	}

	for (int i = 0; i< htable-> size; i++) {
		htable->table[i].info = Empty;
		htable->table[i].element = 0;

	}

	return htable;
}

int find(int key, hash_table* htable) {
	int pos = hash_func1(key, htable->size);
	int step = hash_func2(key, htable->size);
	while (htable->table[pos].info != Empty && htable->table[pos].element != key) {
		pos = pos + step;
		if (pos >= htable->size)
			pos = pos - htable->size;
	}
	return pos;
}

void insert(int key, hash_table* htable) {
	int pos = find(key, htable);
	if (htable->table[pos].info != Legitimate) {
		htable->table[pos].info = Legitimate;
		htable->table[pos].element = key;
		
	}
}

void retrieve(hash_table* htable) {
	for (int i = 0; i < htable->size; i++) {
		int value = htable->table[i].element;
		if (!value)cout << "Dia chi: " << i + 1 << " khoa: 0" << endl;
		else cout << "Dia chi: " << i + 1 << " khoa: " << value << endl;

	}
}

hash_table* rehash(hash_table* htable) {
	int size = htable->size;
	hash_node* table = htable->table;
	htable = init_table(2 * size);
	for (int i = 0; i < size; i++) {
		if (table[i].info == Legitimate)
			insert(table[i].element, htable);
	}
	delete[] table;
	return htable;
}

int main() {
	int value, size, i = 1;
	int choice; 
	system("CLS");
	hash_table* htable=nullptr;
	while(true) {
		cout << "\n---------------------\n";
		cout << "Cac chuc nang tao bang bam nho phuong phap do bac hai\n";
		cout << "\n---------------------\n";
		cout << "1. Khoi tao bang bam\n";
		cout << "2. Chen khoa vao bang bam\n";
		cout << "3. Hien thi noi dung bang bam\n";
		// Bang bam day
		cout << "4. Bam lai bang bam vi bang bam da day\n";
		cout << "0. Thoat\n";
		cout << " Hay chon tu 0-> 4: ";
		cin >> choice;
		switch (choice) {
		case 1: cout << "Nhap kich thuoc mang bam: ";
			cin >> size;
			htable = init_table(size);
			cout << "Kich thuoc cua bang bam: " << next_prime(size);
			break;
		case 2: if (i > htable->size) {
			cout << "Bang bam da day, bam lai !\n";
			continue;
		}
			  cout << "Nhap phan tu can chen: "; cin >> value;
			  insert(value, htable);
			  i++;
			  break;
		case 3: retrieve(htable);
			break;
		case 4: htable = rehash(htable);
			break;
		case 0: exit(1);
		default:
			cout << "\n Nhap tuy chon phu hop\n";
		}
	}
	return 0;
}