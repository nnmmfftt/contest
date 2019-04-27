class Solution {
public:
	int check_position(int *is_placed, int row);
	int draw_graph(vector<vector<string>> &ret, int *is_placed, int n);
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        int is_placed[n];
        memset(is_placed, -1, sizeof(is_placed));

        int row = 0;
        while(row >= 0){
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
    	for(int i = 0; i < ro; ++i){
    		if(is_placed[i] == is_placed[row] || abs(is_placed[i] = is_placed[row]) == row-i ){
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