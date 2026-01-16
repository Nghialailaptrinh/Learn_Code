/**
 * Codeforce 2172E
 * Author: Nghialailaptrinh
 * Date: 16 - 01 - 2026
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * hàm sinh giai thừa.
 */
long long fact(int n)
{
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

/**
 * hàm tách các chữ số của n thành vector.
 */
vector<int> getDigits(int n)
{
    vector<int> digits;
    while (n > 0)
    {
        digits.insert(digits.begin(), n % 10);
        n /= 10;
    }
    return digits;
}

/**
 * hàm tìm hoán vị thứ m của n.
 * n: số nguyên dương có các chữ số phân biệt.
 * m: vị trí hoán vị cần tìm (1-index).
 * return: hoán vị thứ m của n.
 */
vector<int> permutation(int n, int m)
{
    vector<int> digits = getDigits(n);
    int len = digits.size();

    vector<int> result;

    m--; // chuyển sang 0-index

    for (int i = len; i >= 1; i--)
    {
        long long f = fact(i - 1);
        int index = m / f;
        m = m % f;

        result.push_back(digits[index]);
        digits.erase(digits.begin() + index);
    }

    return result;
}

void compare_Permutation(int n, int m1, int m2, int &a, int &b)
{
    vector<int> p1 = permutation(n, m1);
    vector<int> p2 = permutation(n, m2);

    a = 0, b = 0;
    int size = p1.size();
    for (int i = 0; i < size; i++)
    {
        if (p1[i] == p2[i])
        {
            a++;
        }
        else
        {
            b++;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        int a = 0, b = 0;
        compare_Permutation(n, m1, m2, a, b);
        cout << a << "A" << b << "B" << endl;
    }
}
