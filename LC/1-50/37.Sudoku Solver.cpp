class Solution {
private:
	bool rows[9][9] = { 0 };
	// record the numbers placed in rows
	bool cols[9][9] = { 0 };
	// record the numbers placed in columns
	bool boxes[3][3][9] = { 0 };
	// record the numbers placed in 3x3 boxed
public:
	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			// switch char to integer
			for (int j = 0; j < 9; ++j) {
				auto c = board[i][j];
				if (c != '.') {
					int val = c - '1';
					cols[j][val] = rows[i][val] = boxes[i / 3][j / 3][val] = true;
					// record the number already in given rows/cols/boxes
				}
			}
		}
		dfs(board, 0, 0);
		// compute the answer
	}
	bool dfs(vector <vector<char>> &board, int row, int col) {
		if (col == 9) {
			// if got border of columns, switch to the next row and the row's first number
			row++;
			col = 0;
		}
		if (row == 9) {
			// if got final row and column means it is a valid solution
			return true;
		}
		if (board[row][col] != '.') {
			// if the current number is not a blank,find the next position
			return dfs(board, row, col + 1);
		}
		for (int i = 0; i < 9; ++i) {
			// the '.' condition, find the valid solution
			if (!rows[row][i] && !cols[col][i] && !boxes[row / 3][col / 3][i]) {
				// if the number not have been used
				board[row][col] = i + '1';
				// print to the board
				rows[row][i] = cols[col][i] = boxes[row / 3][col / 3][i] = true;
				// record the number used
				if (dfs(board, row, col + 1)) return true;
				// if got end, return all
				rows[row][i] = cols[col][i] = boxes[row / 3][col / 3][i] = false;
				// if got conflict, restore the origin condifion
				board[row][col] = '.';
			}

		}
		return false;
	}
};
