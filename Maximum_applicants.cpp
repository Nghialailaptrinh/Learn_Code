//Có M nhân viên ứng cử vào N công việc. Mỗi nhân viên có một tập con các công việc mà họ cóa tể làm.
//Mỗi lần phân công chỉ có thể tương ứng một nhân viên với một côn việc. ( một công việc ngược lại có thể ứng với nhiều nhân viên)
//Tìm chiến thuật giao việc cho các nhân viên sao cho càng nhiều nhân viên càng tốt


#include<iostream>
#include<algorithm>   //fill
#include<conio.h>
using namespace std;

#define M 6 
#define N 6

bool bpm(bool bp_graph[M][N], int u, bool seen[], int match_R[]) {
	for (int v = 0; v < N; v++) {
		if (bp_graph[u][v] && !seen[v])   //Nếu nhân viên u thích ứng với công việc v và chưa thăm
		{
			seen[v] = true;  //Đánh dấu là v đã thăm

			// Nếu job v chưa được gán cho ai (match_R[v] < 0)
			// OR nếu người đang giữ job v có thể tìm job khác (đệ quy)
			if (match_R[v] < 0 || bpm(bp_graph, match_R[v], seen, match_R)) {
				match_R[v] = u;
				return true;
			}
		}
	}
	return false;
}

int max_bpm(bool bp_graph[M][N], int match_R[N]) {
	int result=0;

	//Đếm số việc ứng với nhân viên
	//Đánh dấu tất cả các vệc chưa xet cho các nhân viên tiếp theo
	for( int u=0; u<M; u++)
	{
		bool seen[N];
		fill(seen, seen + N, 0);
		if (bpm(bp_graph, u, seen, match_R))  //Nếu nhan viên u được giao việc thì cập nhạt kêt quả
		result++;
	}
	return result;
}

int main() {
	bool bp_graph[M][N] = {
		{0,1,1,0,0,0},
		{1,0,0,1,0,0},
		{0,0,1,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,1}
	};

	int   match_R[N];
	fill(match_R, match_R + N, -1);

	cout << "Maximum number of applicants that can get job is "<<max_bpm(bp_graph, match_R);

	cout << "Chi tiet phan cong (Job <- Worker):\n";
	for (int v = 0; v < N; v++) {
		if (match_R[v] != -1) {
			cout << "Job " << v +1 << " <- Worker " << match_R[v] +1 << "\n";
		}
	}

	_getch();
	return 0;

}