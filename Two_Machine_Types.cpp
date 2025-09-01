//Phương pháp làm ịn để giải bài toán

//IOI_1996, Hungary: Nhà máy Z dùng một dây chuyền sản xuất. 
// Với mỗi công việc có hai hoạt động : A và B
//Máy loại A nhận nguyên liệu ở thùng chứa trên bằng chuyền đầu vào, vận hành, rồi chuyển vật phẩm làm được vào thùng chứa ở băng chuyền trung gian
//Máy loại B nhận vật phẩm ở thùng chứa băng chuyền trung gian, vận hành, rồi chuyển sản phẩm vào bằng chuyền đầu ra.
//Tất cả họt động song song và độc lập với nhau
//Kích thước của các thùng chứa là vô tận
//Các máy hoạt động với hiệu suất khác nhau. Một máy cho trước thì haaotj động với thời gian biểu cho trước.

//Yêu cầu:
//1. Xác định thời gian sớm nhát mà hoạt động A có thể hoành tất N công việc, biết rằng các nguyên liệu đã có sẵn tại thời điểm 0
//2. Tình thời lượng thối thiểu để cả hai hoạt động hoàn tất N công việc.

//Đầu vào:
//Dòng đầu ghi số sản phẩm N
//dong hai ghi số máy loại A: M1
//dòng ba ghi M1 số nguyên là thời gian xử lý của từng máy loại A
//
//dòng bốn ghi số máy loại B: M2
//dòng năm ghi M2 số nguyên là thời gian xử lý cảu từng máy loại B
//
//kết quả : Một dòng ghi đáp số câu 1, một dòng ghi đáp số câu 2


// Bài này không hay vì nó trái thực tế. Các máy A tắt mới bắt đầu máy B. thực tế thì chỉ cần có sản phẩm của máy A thì máy B sẽ bắt tay vào làm luôn

#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;


int main() {
	int n, a, b;
	int a_time[50], b_time[50];
	int tam, i;
	int time_a, time_b;
	int sum2, sum, works;
	system("CLS");
	cin >> n;
	cin >> a;
	for (int i = 0; i < a; i++)cin >> a_time[i];
	cin >> b;
	for (int i = 0; i < b; i++)cin >> b_time[i];

	for (time_a = 0; ; time_a++) {
		sum = 0;
		for (int i = 0; i < a; i++)
			sum += time_a / a_time[i];
		if (sum >= n) break;
	}


	for (time_b = time_a; ; time_b++) {
		works = 1;
		for (tam = 1; tam <= time_a; tam++) {
			sum = sum2 = 0;
			for (int i = 0; i < b; i++) {
				sum += (time_b - tam) / b_time[i];
			}

			for (int i = 0; i < a; i++) 
				sum2 += (tam - 1) / a_time[i];
			if (sum + sum2 < n) //get out
			{
				works = 0;
				break;
			}
		}
		if (works) break;


	}

	cout << time_a << "\n";
	cout << time_b << "\n";
	return 0;
}