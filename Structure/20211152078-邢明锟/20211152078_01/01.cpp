#include <bits/stdc++.h>
#include <ctime>

using  namespace std;

const int maxSize = 8;
const int horseMove = 8;

	// horse的所有可能
	int hx[horseMove] = {2, 1, -1, -2, -2, -1, 1, 2};
	int hy[horseMove] = {1, 2, 2, 1, -1, -2, -2, -1};
	
	// 检查horse移动的合法性并且未被访问过
	bool checkHealth(int x, int y,vector<vector<int>>& chess) {
		return x >= 0 && x < maxSize && y >= 0 && y < maxSize && chess[x][y] == -1;
	}
	
	// 提升（2）探讨每次选择位置的“最佳策略”，以减少回溯的次数
	// 统计接下来的路径
	int countPath (int x, int y, vector<vector<int>>& chess) {
		int count = 0;
		for (int i = 0; i < horseMove; i++) {
			int nx = x + hx[i];
			int ny = y + hy[i];
			if (checkHealth(nx, ny, chess)) {
				count++;
			}
		}
	return count;
	}
	// 对前后两条路径进行判断
	bool comparePath(const array<int, 3>& path1, const array<int, 3>& path2) {
		return path1[2] < path2[2];
	}
	
	// 打印棋盘结果
	void printChess(const vector<vector<int>>& chess) {
		for (int i = 0; i < maxSize; i++) {
			for (int j = 0; j < maxSize; j++) {
				cout << chess[i][j] << "\t";
			}
			cout << endl;
		}
	}
	// 提升（2）
	bool horseTouring(int x, int y, int moveCount, vector<vector<int>>& chess) {
		if (moveCount == maxSize * maxSize) return true;
		
		vector<array<int, 3>> nicePath;
		for (int i = 0; i < horseMove; i++) {
			int nx = x + hx[i];
			int ny = y + hy[i];
			if (checkHealth(nx, ny, chess)) {
				int count = countPath(nx, ny, chess);
				nicePath.push_back({nx, ny, count});
			}
		}
		
		if (nicePath.empty()) return false;
		sort(nicePath.begin(), nicePath.end(), comparePath);
		
		for (auto move : nicePath) {
			int nx = move[0];
			int ny = move[1];
			
			chess[nx][ny] = moveCount;
			if (horseTouring(nx, ny, moveCount + 1, chess)) {
				return true;
			}
			chess[nx][ny] = -1; // 回溯
		}
	return false;
	}

	// 递归遍历移动horse
	bool horseTour(int x, int y, int moveCount, vector<vector<int>>& chess) {
		if (moveCount == maxSize * maxSize) {
			// 提升（1）打印当前的行走路线
			cout << "Route: " << endl;
			printChess(chess);
			
			return true;
		}
		for (int i = 0; i < horseMove; i++) {
			int nx = x + hx[i];
			int ny = y + hy[i];
			
			if (checkHealth(nx, ny, chess)) {
				chess[nx][ny] = moveCount;
				if (horseTour(nx, ny, moveCount + 1, chess)) {
					return true;
				}
				chess[nx][ny] = -1; // 回溯
			}
		}
		return false;
	}

	// 非递归遍历移动horse
	bool horseMoving (int x, int y, vector<vector<int>>& chess) {
		stack<pair<int, int>> st;
		st.push(make_pair(x, y));
		
		int moveCout = 1;
		while (!st.empty()) {
			pair<int, int> cur = st.top();
			int nx = cur.first;
			int ny = cur.second;
			st.pop();
			
			chess[nx][ny] = moveCout;
		
			if (moveCout == maxSize * maxSize) return true;
			
			for (int i = 0; i < horseMove; i++) {
				int cx = x + hx[i];
				int cy = y + hy[i];
				
				if (checkHealth(cx, cy, chess)) {
					st.push(make_pair(cx, cy));
				}
			}
		moveCout++;
		}
	return false;
	}




int main() {
	// 初始化棋盘
	vector<vector<int>> chess(maxSize, vector<int>(maxSize, -1));
	
	// 随机选择起始位置
	srand(time(NULL));
	int sx = rand() % maxSize;
	int sy = rand() % maxSize;
	
	chess[sx][sy] = 1;
	
	if (horseTour(sx, sy, 2, chess)) {
		printChess(chess);
	} else {
		cout << "None" << endl;
	}
	
	
	horseMoving(sx, sy, chess);
	printChess(chess);
	
	return 0;
}
