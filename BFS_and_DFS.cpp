//DFS-Duyệt theo chiều sâu ( dùng stack)
//BFS-Duyệt theo chiều rộng ( dùng queue)
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct node *start, *p, *q;
struct link* l, * k;
void create();  //tao do thi 
void bfs();    //Duyet theo chieu rong
void dfs();           //Duyet theo chieu sau
struct node{
	int data, status;
	node* next;
	link* adj;
};

struct link {       //Khai bao danh sach
	node* next;
	link* adj;
};

void create() {   //Một bất cập là một đỉnh có thể nhập hai lần. Tôi sẽ sửa sau
	int dat, flag = 0;
		start = nullptr;
	cout << "Nhap cac nut trong do thi (bam 0 de ket thuc) : \n";
	while (true) {
		cin >> dat;
		if (dat == 0)break;

		//tạo một đỉnh
		p = new node;
		p->data = dat;
		p->status = 0;
		p->next = nullptr;
		p->adj = nullptr;
		if ( flag == 0) {
			start = p;
			q = p;
			flag++;
		}
		else {
			q->next = p;
			q = p;
		}
	}

	/////////////////////////////
	// Gắn các cạnh cho từng đỉnh
	p = start;
	while (p != nullptr) {
		cout << "Cac nut ke voi nut " << p->data << " ( nhap 0 de ket thuc) : \n";
		flag = 0;
		while (true) {
			cin >> dat;
			if (dat == 0) break;

			// Tạo một link mới chưa nối tới đâu
			k = new link;
			k->adj = nullptr;

			// Nếu là cạnh đầu tiên thì nối vào node
			if (flag == 0) {
				p->adj = k;
				l = k;
				flag++;
			}
			//Nếu là cạnh tiếp theo thì tiếp vào 
			else {
				l->adj = k;
				l = k;
			}

			//Tìm node trong danh sách đỉnh
			q = start;
			while (q != nullptr) {
				if (q->data == dat)k->next = q;
				q = q->next;
			}
		}
		p = p->next;
	}
	cout << "\n--------------------------------------------\n";
	return;
}

//Cài BFS bằng queue
void bfs() {
	int qu[20], i = 1, j = 0;


	//0 là chưa thăm, 1 là đã thăm
	p = start;
	while (p != nullptr) {
		p->status = 0;
		p = p->next;
	}

	//đưa dữ liệu đầu tiên vào queue
	p = start;
	qu[0] = p->data;
	p->status = 1;


	while(true) {
		if (qu[j] == 0)break; //queue trống thì dừng

		// tìm node trong danh sách ứng với giá trị qu[j];
		p = start;
		while (p != nullptr) {
			if( p-> data == qu[j])break;
				p=p-> next;
		} 

		//Duyệt tất cả các đỉnh kề của p;
		k = p->adj;
		while (k != nullptr) {
			q = k->next;
			if (q->status == 0) {
				qu[i] = q->data;
				q->status = 1;
				qu[i + 1] = 0;
				i++;
			}
			k = k->adj;
		}
		j++; // dịc con trỏ đọc trong queue
	}
	j = 0;
	cout << "Ket qua duyet do thi theo BFS: ";
	while (qu[j] != 0) {
		cout << qu[j] << " ";
		j++;
	}
	_getch();
	return;
}

//Cài đặt DFS bằng Stack
void dfs() {
	int stack[25], top = 1;
	cout << "Ket qua duyet do thi theo DFS: ";

	// 0 là chưa thăm, 1 là đã thăm
	p = start; 
	while (p != nullptr) {
		p->status = 0;
		p = p->next;
	}

	p = start;
	stack[0] = 0;      // cờ báo kết thúc stack
	stack[top] = p->data;
	p->status = 1;
	while (true) {
		if (stack[top] == 0) break;         // stack rỗng thì dừng

		//Lấy đỉnh trên cùng của stack ra
		p = start;
		while (p != nullptr) {
			if (p->data == stack[top])break;
			p = p->next;
		}
		cout << stack[top] << " ";
		top--;

		//Duyệt tất cả đỉnh kề
		k = p->adj;
		while (k != nullptr) {
			q = k->next;
			if (q->status == 0) {
				top++;
				stack[top] = q->data;
				q-> status = 1;
			}
			k = k->adj;
		}
	 }
	_getch();
	return;
}

int main() {
	system("CLS");
	int chon;
	create();
	while (true) {
		cout << "\n MENU: \n";
		cout << "1. BFS\n";
		cout << "2. DFS\n";
		cout << "3. Exit\n";
		cout << "Nhap lua chon cua ban: \n"; cin >> chon;
		switch (chon) {
		case 1:bfs(); break;
		case 2: dfs(); break;
		case 3:  exit(0); break;
		default: cout << "Chon khong dung!\nNhap lai lua chon. \n";
			_getch();
		}
	}
	return 0;
}
