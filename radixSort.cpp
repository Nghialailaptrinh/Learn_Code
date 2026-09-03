// Radix Sort Implementation
// This program is coded by Nguyen Trung Nghia
// This program implements the Radix Sort algorithm to sort a list of integers.
// The base 10 is used for Radix Sort, which means it sorts the numbers based on their individual digits from least significant to most significant.

// It is not work with negative numbers,
// Không hoạt động với số âm, vì Radix Sort được thiết kế để sắp xếp các số nguyên không âm.
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <chrono> // This helps to see the time taken by the sorting process, but it is not used in the current implementation. You can use it to measure the performance of the sorting algorithm if needed.

// This function opens the file and reads the input data into a vector
std::vector<int> readInput(const std::string &filename)
{
    std ::vector<int> arr;
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return arr;
    }

    int number;
    bool hasNegative = false;
    while (infile >> number)
    {
        if (number < 0)
        {
            if (!hasNegative)
                std::cout << "Warning: Negative number detected. Radix Sort does not support negative numbers. Sorting will be performed on the absolute values.\n";
            hasNegative = true;
            number = -number; // Convert to positive for sorting, but this will not be handled correctly in the current implementation
        }

        arr.push_back(number);
    }
    infile.close();
    return arr;
}

// Function to get the maximum value in the array
int getMax(const std::vector<int> &arr)
{
    if (arr.empty())
        throw std::runtime_error("Array is empty");

    int max = arr[0];

    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(std::vector<int> &arr, int exp)
{
    std::vector<int> output(arr.size());
    int count[10] = {0};

    // Count occurrences of each digit
    for (size_t i = 0; i < arr.size(); i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] to contain the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = (int)arr.size() - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array back to arr
    for (int i = 0; i < (int)arr.size(); i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int> &arr)
{
    // Get the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    // Loop to allow multiple runs of the program
    while (true)
    {
        std::vector<int> arr;

        // Ask user for input method
        while (true)
        {
            std::cout << "Use file, digits or test case? (f/d/t): ";

            char choice;
            std::cin >> choice;

            if (choice == 'f')
            {
                std::string filename;
                std::cout << "Enter file name: ";
                std::cin >> filename;

                arr = readInput(filename);
                if (arr.empty())
                {
                    std::cout << "File empty or cannot read data\n";
                    continue;
                }
                break;
            }
            else if (choice == 'd')
            {
                int n;

                std::cout << "Enter number of elements: ";
                std::cin >> n;

                arr.resize(n);

                std::cout << "Enter elements:\n";

                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];

                break;
            }
            else if (choice == 't')
            {
                arr = {170, 45, 75, 90, 802, 24, 2, 66};
                std::cout << "Test case: ";
                for (int i : arr)
                {
                    std::cout << i << " ";
                }
                std::cout << "\n";
                break;
            }
            else
            {
                std::cout << "Invalid input\n";
            }
        }

        radixSort(arr);

        for (int num : arr)
            std::cout << num << " ";

        std ::cout << std::endl;
        std ::cout << "Do you want retry? (y/n): ";
        char retry;
        std ::cin >> retry;
        if (retry == 'y' || retry == 'Y')
        {
            system("cls"); // Clear the console (works on Windows)
            // For Unix/Linux/MacOS, use system("clear");
        }
        else
        {
            std::cout << "Exiting program.\n";
            break;
        }
    }

    return 0;
}