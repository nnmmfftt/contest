/*--------------------1st--------------------*/
class Solution {
public:
	vector<vector<string>> solveNQueens(int n){
		/*
		 * Check the every position always is a repetitive process.
		 * Then use recursion to solve the problem.
		 *
		 * The recursion steps is check every position, if a chess is put down, use dfs and
		 * check the remain positon.
		 */
		vector<vector<string>> ret;
		vector<string> graph(n, string(n, '.'));
		nQueens_dfs(0, n, graph, ret);
		return ret;
	}

private:
	void nQueens_dfs(int row, int n, vector<string> &graph, vector<vector<string>> &ret){
		if(row == n ){
			ret.push_back(graph);
			return;
		}
		for(int i = 0; i < n; ++i){
			if(is_placed(graph, n, row, i)){
				graph[row][i] = 'Q';
				nQueens_dfs(row + 1, n, graph, ret);
				graph[row][i] = '.';
			}
		}
	}

	bool is_placed(vector<string> &graph, int n, int row, int col){
		for(int i = 0; i < row; ++i){
			if(graph[i][col] == 'Q') return false;
			if(col + row - i < n && graph[i][col + row - i] == 'Q') return false;
			if(col + row + i >= 0 && graph[i][col - row + i] == 'Q') return false; 
		}
		return true;
	}
};

/*--------------------2nd--------------------*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    	/*
    	 * If not use recursion, the find operation need to reset the postion flags if cannot 
    	 * put down the all given chess pieces.
    	 */
        vector<vector<string>> ret;
        int is_placed[n];
        memset(is_placed, -1, sizeof(is_placed));

        int row = 0;
        while(row >= 0){
        	is_placed[row]++;
        	while( is_placed[row] < n && !check_position(is_placed, row))
        		++ is_placed[row];
        	if(is_placed[row] < n){
        		if(row == n-1){
        			int rc = draw_graph(ret, is_placed, n);
        			if(rc != 0) break;
        			else --row; 
        		}
        		else{
        			is_placed[++row] = -1;
        		}
        	}
        	else {
        		--row;
        	}
        }return ret;
    }
    int check_position(int *is_placed, int row){
    	for(int i = 0; i < row; ++i){
    		if(is_placed[i] == is_placed[row] || abs(is_placed[i] - is_placed[row]) == row-i ){
    			return false;
    		}
    	}return true;
    }
    int draw_graph(vector<vector<string>> &ret, int *is_placed, int n){
    	vector<string> graph(n, string(n, '.'));
    	for(int i = 0; i < n; ++i){
    		graph[i][is_placed[i]] = 'Q';
    	}
    	ret.push_back(graph);
    	return 0;
    }
};