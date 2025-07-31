//Trộn hai run dùng file
//#define _CRT_SECURE_NO_WARNINGS     
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#define true 1
#define false 0
#define sz (sizeof(float))

using namespace std;
//Hàm kiểm tra kết thúc file
int EoF(FILE* f) {
	float x;
	if (fread(&x, sz, 1, f) <= 0) return true;
	fseek(f, -(long)sz, SEEK_CUR); // vì fread đã đẩy con trỏ đi 1 đơn vị float nên ta phải cho nó lùi về
	return false;

}
//check run
int EoR(FILE* f) {
	float x, y;
	if (ftell(f) == 0) return false;     // Nếu conn trỏ vẫn ở đầu file, dĩ diên file chưa kết thúc
	if (fread(&y, sz, 1, f) <= 0)return true; //Hết file
	fseek(f,(long)( - 2.0 * sz ), 1);
	fread(&x, sz, 1, f);
	if (x <= y) { return false; }
	else return true;         // số lớn hơn y lại đứng trước y chứng tỏ rằng run đã kế thúc trươc y
}

int FileNodes(const char* ten_tep) {
	int k=0; 
	//FILE* f = fopen(ten_tep, "rb");
	FILE* f; fopen_s(&f, ten_tep, "rb");
	fseek(f, 0, 2); //Đặt con trỏ về cuối tệp
	k = ftell(f) / sz; // Trả về số phần tử float
	fclose(f);
	return (k);
}
//Taoj file có n phàn tử
void create_file(const char* ten_tep) {
	int n=0; float x=0;
	//FILE* f = fopen(ten_tep, "wb");
	FILE* f; fopen_s(&f, ten_tep, "wb");
	rewind(f); //Đưa con trỏ lên đầu file
	char ch;
	do {
		system("CLS");
		cout << "\n Nhap du lieu len tep: ";
		cout << "\n 1.Nhap truc tiep bang tay ";
		cout << "\n 2.Nhap tu dong ngau nhien ";
		cout << "\n\n Hay chonj 1 hoac 2: ";
		//ch = getch();
		cin >> ch;

	} while (ch != '1' && ch != '2');
	cout << "\n Cho biet so phan tu can nhap vao tep: ";
	cin >> n;
	cout << "Day vua nhap len tep Vao: " << endl;
	if (ch == '1') {
		cout << "\n Nhap bang tay lan luot " << n << " so";
		for (int i = 0; i < n; i++) {
			cin >> x; fwrite(&x, sz, 1, f);
		}
	}
	else {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < n; i++) {
			x = (float)(rand() % (10 * n));
			fwrite(&x, sz, 1, f);
		}
	}
	fclose(f);
}
//Xem file
void view_file(const char* ten_tep) {
	float x;
	//FILE* f = fopen(ten_tep, "rb");
	FILE* f; fopen_s(&f, ten_tep, "rb");
	rewind(f);
	cout << "\n Cac phan tu tren tep ra (Ket qua xep tron) : ";
	while (fread(&x, sz, 1, f)>0) {
		cout << setw(4) << x;
	}
	fclose(f);
}

//Phân phối từng Run trên file a cho file b và c đến khi hết file a
void split_file(const char* tep_a,const char* tep_b,const char* tep_c) {
	FILE* a, * b, * c;
	float x;
	/*a = fopen(tep_a, "rb");
	b = fopen(tep_b, "wb");
	c = fopen(tep_c, "wb");*/
	fopen_s(&a, tep_a, "rb");
	fopen_s(&b, tep_b, "wb");
	fopen_s(&c, tep_c, "wb");
	rewind(a); rewind(b); rewind(c);
	while (!EoF(a)) {
		//Phân phối run trên a cho b
		fread(&x, sz, 1, a);
		fwrite(&x, sz, 1, b);
		while (!EoR(a)) {
			fread(&x, sz, 1, a);
			fwrite(&x, sz, 1, b);
		}
		if (EoF(a)) break;
		//Phân phối Run trên a cho c
		fread(&x, sz, 1, a);
		fwrite(&x, sz, 1, c);
		while (!EoR(a)) {
			fread(&x, sz, 1, a);
			fwrite(&x, sz, 1, c);
		}
	}
	fclose(a); fclose(b); fclose(c);
}

//Trộn run của b và c thành run kết quả lưu lại vào a
void merge_file(const char* tep_b,const char* tep_c,const char* tep_a) {
	float x=0, y=0;
	int con_x=false, con_y=false;
	//con_x = true có nghĩa là còn phần tử trong run trên file b;
	//con_y tương tự
	/*FILE*b = fopen(tep_b, "rb");
	FILE*c = fopen(tep_c, "rb");
	FILE*a = fopen(tep_a, "wb");*/
	FILE* a, * b, * c;
	fopen_s(&a, tep_a, "wb");
	fopen_s(&b, tep_b, "rb");
	fopen_s(&c, tep_c, "rb");
	rewind(b); rewind(c); rewind(a);
	while (!EoF(b) && !EoF(c)) {
		fread(&x, sz, 1, b); con_x = true;
		fread(&y, sz, 1, c); con_y = true;
		while (con_x && con_y) {
			if (x < y) {
				fwrite(&x, sz, 1, a);
				if (EoF(b)) { con_x = false; }
				else fread(&x, sz, 1, b);
			}
			else{
				fwrite(&y,sz,1,a);
				if (EoF(c)) { con_y = false; }
				else fread(&y, sz, 1, c);

			}
		}

	}
	if (con_x) fwrite(&x, sz, 1, a);
	if (con_y)fwrite(&y, sz, 1, a);
	while (!EoF(b)) {
		fread(&x, sz, 1, b);
		fwrite(&x, sz, 1, a);
	}
	while (!EoF(c)) {
		fread(&y, sz, 1, c);
		fwrite(&y, sz, 1, a);
	}
	fclose(b); fclose(c); fclose(a);
}

//Kiểm tra nếu tệp đã được sắp xếp thì trả về true
int sorted_file(const char* ten_tep) {
	/*FILE* f = fopen(ten_tep, "rb");*/
	FILE* f; fopen_s(&f, ten_tep, "rb");
	float x, y;
	rewind(f);
	fread(&x, sz, 1, f);
	while (fread(&y, sz, 1, f) > 0) {
		if (x > y) { fclose(f); return false; }
		x = y;
	}
	fclose(f);
	return true;
}

//Sắp xếp tệp có tên lưu bằng phương pháp trộn;
void sort_file(const char* ten_tep) {
	const char* tep_b = "tepb.dat", * tep_c = "tepc.dat";
	while (!sorted_file(ten_tep)) {
		split_file(ten_tep, tep_b, tep_c);
		merge_file(tep_b, tep_c, ten_tep);
	}
	if(remove("tepb.dat")==0)cout<<"\nDa xoa tep b";
	if(remove("tepc.dat")==0)cout<<"\nDa xoa tep c";
}

int main() {
	system("CLS");
	const char * ten_tep="RA.DAT";
	create_file(ten_tep);
	view_file(ten_tep);
	cout << "\nDAng sap xep tep";
	sort_file(ten_tep);
	view_file(ten_tep);
	//getch();
}