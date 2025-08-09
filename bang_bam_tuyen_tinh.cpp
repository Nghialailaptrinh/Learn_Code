//Đây là code C++ lưu dữ liệu con người(tên, tuổi) bằng bảng băm


#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

//Khỏi tạo
int table_size = 0;  //Kích thước mảng băm
int num_ele = 0;     // Các phần tử trong mảng băm
struct node* hash_table = nullptr;

//Khai báo cấu trúc node
struct node {
	int age, key;
	char name[50];
	int marker;
};


//Chèn khóa mới
void insert(int key, char* name, int age) {
	int hash_index = key % table_size;
	if (table_size == num_ele) {   //Nếu mảng băm đầy
		cout << "\nBang bam da day, khong the them phan tu moi duoc!!";
		return;
	}
	while (hash_table[hash_index].marker == 1) {
		hash_index = (hash_index + 1) % table_size;
	}

	hash_table[hash_index].key = key;
	hash_table[hash_index].age = age;
	strcpy_s(hash_table[hash_index].name, name);
	hash_table[hash_index].marker = 1;
	num_ele++;
	return;
	
}

 
//Xóa một khóa
void dele(int key) {
	int hash_index = key % table_size, count = 0, flag = 0;
	if (num_ele == 0) {
		cout << "\n Bang bam rong, khong the xoa"; return;
	}
	while (hash_table[hash_index].marker != 0 && count<=table_size) {
		if (hash_table[hash_index].key == key) {
			hash_table[hash_index].key = 0;
			hash_table[hash_index].marker = -1;
			hash_table[hash_index].age = 0;
			strcpy_s(hash_table[hash_index].name, "\0");
			num_ele --;
			flag = 1;
			break;
		}
		hash_index = (hash_index + 1) % table_size;
		count++;
	}
	if (flag)//Xóa thành công
		cout << "\n Khoa vua nhap da bi xoa";
	else
		cout << "\n Khoa nay khong ton tai trong bang bam";
	return;

}
 
//Tìm một khóa
void search(int key) {
	int hash_index = key % table_size;
	int flag = 0, count = 0;
	if (num_ele == 0) {
		cout << "\n Bang bam rong, nen khong co gi de tim";
		return;
	}
	while (hash_table[hash_index].marker != 0 && count <= table_size) {
		if (hash_table[hash_index].key == key) {
			flag = 1;
			break;
		}
		hash_index = (hash_index + 1) % table_size;
		count++;
	}

	if (flag) {
		cout << "\n Da tim thay khoa" << hash_table[hash_index].key;
		cout << " o dia chi " << hash_index;
	}
	else cout << "\n Khoa vua nhap khong co trong bang bam";
	cout << "\n\n";
	return;
}
 
//Xem toàn bộ mảng băm
void display() {
	int i = 0;
	if (num_ele == 0) {
		cout << "\n Bang bam rong \n";
		return;
	}
	cout << " \n Khoa\t\tTen\tTuoi\tDia chi\n";
	cout << "________________________________________________________________________\n";
	for (i = 0; i < table_size; i++) {
		if (hash_table[i].marker == 1) {
			cout << setw(1) << hash_table[i].key;
			cout << setw(13) << hash_table[i].name;
			cout <<setw(10) <<hash_table[i].age;
			cout << "\n";
		}
	}

	return;
}
 
//Thiết kế bảng chọn

int main() {
	int key, age, ch;
	char name[30]; 
	system("CLS");
	cout << "\n\n";
	cout << "\t\t\t\t BANG CHON: \n\n";
	cout << "Cho biet kich co cua bang bam:";
	cin >> table_size;
	hash_table = (struct node*)calloc(table_size, sizeof(struct node));

	while (true) {
		cout << "1. chen them\t2. Xoa khoa\t3. Tim khoa\t4. Xem bang bam\n";
		cout << "\n5. Thoat\n Go[1...5] de chon viec:"; cin >> ch;
		switch (ch) {
		case 1 :cout << "Nhap gia tri khoa"; cin >> key;
				getchar();
				cout << "Nhap ten:";
				cin.getline(name, 30);
				cout << "Nhap tuoi:"; cin >> age;
				insert(key, name, age);
				break;
		case 2:cout << "Cho biet gia tri cua khoa can xoa: ";
			cin >> key;
			dele(key);
			break;
		case 3: cout << "Nhap gia tri khoa can tim:";
			cin >> key;
			search(key);
			break;
		case 4: display();
			break;
		case 5: exit(0);
		default: cout << "Ban da nhap sai muc chon!\n";
			break;
		}
	}
	return 0;
}