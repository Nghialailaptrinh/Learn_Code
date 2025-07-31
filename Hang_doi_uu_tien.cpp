//Đây là code cài đặt prioritry queue bằng heap
#include<iostream>
#include<queue>
using namespace std;
int N;

//Chèn phần tử, phần tử vừa đẩy vào sẽ lên vị trí cao nhất nó có thể leo lên trong cây nhị phân; nếu nó lớn nhất chắc chắn sẽ lên đầu, nó chỉ không leo lên được nếu gặp cái lớn hơn
void insert_element(int A[], int val) {
	N++;
	int i = N;
	A[i] = val;
	while (i > 1 && A[i / 2] < A[i]) {
		swap(A[i], A[i / 2]);
		i = i / 2;
	}
}

void max_heap(int A[], int i) {
	int largest;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left <= N and A[left] > A[i])               //N là số phần tử trong mảng
	{
		largest = left;
	}
	else largest = i;
	if (right <= N && A[right] > A[largest]) {
		largest = right;
	}
	if (largest != i) {                  // đây là cách họ tìm ra người sẽ tranh vị trí á quân của giải đấu sau khi đã có nhà vô địch
		swap(A[i], A[largest]);
		max_heap(A, largest);
	}    
}

int max_element(int A[]) {
	return A[1];         // Node gốc trong max_heap có giá trị lớn nhất
}

int pop_max_element(int A[]) {
	if (N == 0) {
		cout << "\nKhong the xoa phan tu vi hang doi rong\n";
		return -1;
	}
	int max = A[1];
	A[1] = A[N]; //Đặt phần tử cuối lên vị trí node gốc làm cho heap vi phạm các đặc tính kiến cho hàm max_heap chạy=> node có giá trị lớn nhát lại được đẩy lên
	N = N - 1;
	max_heap(A, 1);
	return max;
}

void print_element(int A[]) {
	if (N <= 0)return;
	cout << "\t";
	for (int i = 1; i <= N; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
}
int main() {
	system("CLS");                  // Hàm này bạn phải chạy trên terminal của máy 
	N = 0;
	int A[20];
	int n; cout << "\nNhap so phan tu ban muon nhap: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int element; cin >> element;
		insert_element(A, element);
	}
	cout << endl;
	print_element(A);
	for (int i = 0; i < n; i++) {
		pop_max_element(A); print_element(A);

	}
	return 0;
}