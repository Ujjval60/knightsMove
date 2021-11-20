#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Board {
	int n;
	vector<vector<int> > board;
public:
	Board(int size) {
		n = size;
		vector<int> temp(n, 0);
		for (int i = 0; i < n; i++) {
			board.push_back(temp);
		}
	}

	int minSteps(int sourceX, int sourceY, int destX, int destY) {
		if (sourceX == destX && sourceY == destY) {
			return 0;
		}

		int step = 0;

		int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
		int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

		queue<pair<int, int>> q;
		q.push({sourceX, sourceY});
		q.push({ -1, -1});
		board[sourceX][sourceY] = 1;

		while (!q.empty()) {
			pair<int, int> pr = q.front();
			q.pop();
			if (pr.first == -1 && pr.second == -1) {
				step++;
				if (q.empty()) {
					break;
				}
				q.push({ -1, -1});
				continue;
			}

			int x = pr.first;
			int y = pr.second;

			if (x == destX && y == destY) {
				return step;
			}

			for (int i = 0; i < 8; i++) {
				if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n && board[x + dx[i]][y + dy[i]] == 0) {
					q.push({x + dx[i], y + dy[i]});
					board[x + dx[i]][y + dy[i]] = 1;
				}
			}

		}

		return -1;


	}

};

int main() {
	Board chess(8);
	cout << chess.minSteps(7, 0, 7, 5);
	return 0;
}
