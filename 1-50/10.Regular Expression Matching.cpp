/*--------------------1st--------------------*/
// dp solution(bottom-up)
bool isMatch(string s, string p) {
	/*
	 * We can find a optimal substructure, 
	 * 
	 * Set dp[][] is the dp state array.
	 * dp[i][j] is p[j-1] matching s[i-1] -> p : 1-j  matching s : 1-i
	 * 
	 * The original state:
	 * 1. pattern is 0, there is no way to match:
	 *		dp[0~i][0] = 0
	 *
	 * 2. if p[j-i](current character) is '*', we need to find p[j-2].
	 *	  we need to set j > 1, because a alphabet need to come before *.
	 *		dp[0][j] = j > 1 && p[j-1] == '*' && dp[0][j-2];
	 *
	 * Then dp[i][j] will comes to 2 conditions:
	 *	1. the current p character is '*' .
	 *	2. the current p character is a alphabet .
	 *
	 *  Condition 1:
	 *			if dp[i][j] is true, 
	 *							1. dp[i][j-2] is true(means s(1~i-1) matching p(1~j-2) ).
	 *				 		or: 2. dp[i-1][j-1] and s(i) equals p(j) or p(j-1) equals '.'
	 *											( s[i-1] == p[j-2] || p[j-2] == '.' )
	 *	Condition 2:
	 *			if dp[i][j] is true, and p(j) is not '*',
	 *							dp[i-1][j-1] is true and :	               ->	( p(1~j-1) matching s(1~i-1))
	 *									1. s(i) == p(j) ( s[i-1] == p[j-1])
	 *								or  2. p(j) == '.'. ( p[j-1] == '.')
	 *								 
	 */
    int m = s.size();
    int n = p.size();
    int dp[s.size()+1][p.size()+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i <=m; ++i){
        for(int j = 1; j <=n; ++j){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1]==p[j-2]||p[j-2] == '.'));
            }
            else {
                dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] ||p[j-1] =='.');
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