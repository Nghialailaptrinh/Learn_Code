
//Đây lòa một bài code làm quen với hàng đợi ưu tiên
#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int,vector<int>, less<int>> my_priority_queue;
	for (int i = 0; i < 5; i++)
	{
		my_priority_queue.push(i);
	}
	cout << "The size of priority queue is: " << my_priority_queue.size() << endl;
	cout << "Cac phan tu cua no la: ";
		while (!my_priority_queue.empty()) {
			cout << my_priority_queue.top()<<" ";
			my_priority_queue.pop();
		}
	return 0;
}