#include<bits/stdc++.h>

using namespace std;

	// 迷宫定义
	const int M = 9;
	const int N = 8;

	int maze[M][N] = {
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 1, 0, 1},
		{0, 1, 1, 1, 0, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 1},
		{0, 1, 1, 1, 1, 0, 0, 1},
		{1, 1, 0, 0, 0, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0}
	};
	// 定义方向
	int dir[4][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	}; 
	// 定义坐标
	struct Point {
		int x, y;
	};

	// 检查坐标的合法性
	bool checkHealth(int x, int y) {
		return x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 0;
	}
	
	// 提升（1） 递归求解
	bool findPath( int x, int y, vector<Point>& path) {
		// 到达出口
		if (x == M - 1 && y == N - 1) {
			path.push_back({x, y});
			return true;
		}
		
		maze[x][y] = -1;
		
		// 四个方向移动
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			
			if (checkHealth(nx, ny)) {
				if (findPath(nx, ny, path)) {
					path.push_back({x, y});
					return true;
				}
			}
		}
		return false;
	}
		
	// 非递归求解迷宫通路
	bool findPaths(vector<Point>& path) {
		stack<Point> s;
		Point start = {0, 0};
			
		s.push(start);
			
		while (!s.empty()) {
			Point cur = s.top();
			s.pop();
				
			int x = cur.x;
			int y = cur.y;
				
			// 到达出口
			if (x == M - 1 && y == N - 1) {
				path.push_back({x, y});
				return true;
			}
				
				maze[x][y] = -1;
				
			// 四个方向移动
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
					
				if (checkHealth(nx, ny)) {
					s.push({nx, ny});
				}
			}
		}
		return false;
	}
	

	// 打印迷宫通路
	void printPath(vector<Point>& path) {
		for (int i = path.size() - 1; i >= 0; i--) {
			cout << "(" << path[i].x << ", " << path[i].y << ", " << i + 1 << ")";
			if (i > 0) {
				cout << ", ";
			}
		}
		cout << endl;
	}

	// 提升（2）以方阵形式输出迷宫及其通路
	void printPaths(const vector<Point>& path) {
		cout << "迷宫：" << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
	
		cout << "通路：" << endl;
		vector<vector<int>> mazeWithPath = vector<vector<int>>(M, vector<int>(N, 0));
		for (const Point& p : path) {
			mazeWithPath[p.x][p.y] = 1;
		}
	
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << mazeWithPath[i][j] << " ";
			}
			cout << endl;
		}
	}

int main() {
	vector<Point> path;
	
	// 递归
	if (findPath(0, 0, path)) {
		cout << "递归求解迷宫通路：" << endl;
		printPath(path);
	} else {
		cout << "没有找到通路" << endl;
	}
	
	path.clear();
	
	// 非递归
	if (findPaths(path)) {
		cout << "非递归求解迷宫通路：" << endl;
		printPath(path);
	} else {
		cout << "没有找到通路" << endl;
	}
	
	return 0;
}
