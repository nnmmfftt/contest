/*--------------------1st--------------------*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hash to record every numbers appeared
        unordered_map<int, unordered_map<char, bool>> cols;
        unordered_map<int, unordered_map<char, bool>> rows;
        unordered_map<int, unordered_map<int, unordered_map<char,bool>>> boxes;
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board.size(); ++j) {
                auto tmp = board[i][j];
                if (tmp != '.') {
                    if (cols[j].count(tmp) + rows[i].count(tmp) + boxes[i/3][j/3].count(tmp) == 0) {
                        cols[j][tmp] = true;
                        rows[i][tmp] = true;
                        boxes[i/3][j/3][tmp] = true;
                    }
                    else return false;
                    // if number in  record, the soduko is invalid
                }
            }
        }
        return true;
    }
};

/*--------------------1st--------------------*/
struct Pos {
    int x, y;
};
class Solution {
public:
    bool judge(Pos& a, Pos& b) {
        // if a and b in a same row or column and box
        if(a.x == b.x || a.y == b.y || (a.x/3*3 == b.x/3*3 && a.y/3*3 == b.y/3*3))
            // 1. a same row
            // 2. a same column
            // 3. a same box, x/3*3 is box line, y/3*3 is 
            return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<Pos> > v(10);
        for(int x = 0; x < 9; ++x) {
            for(int y = 0; y < 9; ++y) {
                if(board[x][y] == '.') continue;
                int idx = board[x][y] - '0';
                Pos pos = {x, y};
                if(!v[idx].empty()) {
                    for(auto p : v[idx]) {
                        if(!judge(p, pos))
                            return false;
                    }
                }
                v[idx].push_back(pos);
            }
        }
        return true;
    }
};
