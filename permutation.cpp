#include<iostream>
#include<algorithm>

using namespace std;

int number_of_digits(int n){
    int count = 0;
    while(n > 0){
        count++;
        n = n / 10;
    }
    return count;
}

int next_permutation(int n){

    // Lấy ra số chữ số của n
    int lenght =  number_of_digits(n);
    int arr[lenght];
    for(int i=lenght-1; i>=0; i--){
        arr[i] = n%10;
        n = n/10;
    }

    // Thực hiện thuật toán tìm hoán vị kế tiếp
    // 12347568 -> 12347586
    // Bước 1: Tìm vị trí i sao cho arr[i] < arr[i+1] từ phải sang trái
    int i = lenght - 2;
    while(i >= 0 && arr[i] >= arr[i+1]){
        i--;
    }
    if(i < 0){
        cout<<"Đây là hoán vị lớn nhất!\n"<<endl;
        return -1; // Không có hoán vị kế tiếp
    }
    // Bước 2: Tìm vị trí j sao cho arr[j] > arr[i] từ phải sang trái để swap sẽ sinh ra số lớn hơn 
    int j = lenght - 1;
    while(arr[j] <= arr[i]){
        j--;
    }
    // Swap arr[i] và arr[j]
    swap(arr[i], arr[j]);
    // Bước 3: Đảo ngược từ arr[i+1] đến hết mảng
    reverse(arr + i + 1, arr + lenght);
    // Chuyển mảng arr thành số nguyên
    int result = 0;
    for(int k = 0; k < lenght; k++){
        result = result * 10 + arr[k];
    }   
    return result;

}

/**
 * Hàm tính hoán vị thứ r của n chữ số
 * nhỏ nhất r =1; lớn nhất r = giai thừa(n)
 */
int permutation(int n, int r){
    int max_r = 1;
    int length = number_of_digits(n);
    for( int i =1; i<=length; i++){
        max_r = max_r * i;
    }
    if(r < 1 || r > max_r){
        cout<<"Giá trị r không hợp lệ!\n";
        return -1;
    }
    int result = n;
    for(int i=1; i<r; i++){
        cout << "Hoán vị thứ " << i<< " là: " <<(result) << endl;
        result = next_permutation(result);
    }
    return result;

}

void compare_with_permutation(int n, int r, int a, int b){
    // số số hạng giống nhau, giống vị trí = a;
    // số số hạng giống nhau, khác vị trí = b;


}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        int r; cin >>r;
        // cout<< "Hoán vị thứ " << r << " của " << n << " là: " << permutation(n, r) << endl;
        permutation(n, r);

    }

    return 0;
}