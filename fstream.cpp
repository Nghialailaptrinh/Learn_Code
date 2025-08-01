#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a[] = { 10, 20, 30, 40, 50 };
    int n = 5;

    // Ghi file nhị phân
    fstream file("numbers.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(a), sizeof(a));
    file.close();
    

    // Đọc lại từ cuối về đầu (giống dùng fseek)
    file.open("numbers.bin", ios::in | ios::binary);
    file.seekg(0, ios::end);  // tương đương fseek(f, 0, SEEK_END);
    int size = file.tellg();  // tương đương ftell(f);
    int count = size / sizeof(int);

    cout << "Đọc ngược lại:\n";
    for (int i = count - 1; i >= 0; i--) {
        file.seekg(i * sizeof(int), ios::beg);  // giống fseek(f, i*sizeof(int), SEEK_SET);
        int x;
        file.read(reinterpret_cast<char*>(&x), sizeof(int));
        cout << x << " ";
    }

    file.close();
    return 0;
}
