/*--------------------1st--------------------*/
// dp solution(bottom-up)
bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();
	int dp[s.size()+1][p.size()+1];
	memset(dp,0,sizeof(dp));
	for(int i = 0; i <=m; ++i){
		for(int j = 1; j <=n; ++j){
			if(p[j-1] == '*'){
				dp[i][j] = dp[i][j-2]||(i && s[i-1]==p[j-2]||p[j-2] == '.');
			}
			else {
				dp[i][j] = i && dp[i-1][j-1]||(s[i-1] == p[j-1] ||p[j-1] =='.');
			}
		}
	}return dp[m][n];
}

/*--------------------2nd--------------------*/
dp solution
/*--------------------1st--------------------*/
Non-Deterministic Finite Automata solution

typedef opt (*addedge)(struct Graph g, int i);
struct Graph{
	int E;
	int V;
	int **adj;
	int *marked;
	opt opt;
}

void (*dfs)(struct Graph p, int start){
	Graph.marked[start] = true;
	for(int i = 0; i < Graph.V; ++i){
		if(!Graph.marked[i])
			dfs(p,i);
	}
}