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

class Graph{
private:
	const int V;           
    int E;                 
    vector<vector<int>> adj(V,vector<int>(0));    
public: 
	Graph(int V) {     
        this.V = V;
        this.E = 0;
    }
    int V() {
        return V;
    }
    int E() {
        return E;
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        E++;
    }
    int* adj(int v) {
        return adj[v];
    }
}

class DFS{
private: 
	int *marked;  
    int count;         
public:
	DFS(Graph G, int s) {
        marked = (int*)malloc(sizeof(int)*G.V());
        dfs(G, s);
    }
    DFS(Graph G, int* adj_v) {
        int marked[G.V()];
        for (int v : adj_v) {
            if (!marked[v]) dfs(G, v);
        }
    }
    void dfs(Graph G, int v) { 
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) dfs(G, w);
        }
    }
    int marked(int v) {
        return marked[v];
    }
    ~DFS(){
    	free(marked);
    }
}

class Solution {
    int m;
    Graph graph;    
public:
 int isMatch(String s, String p) {
    if(p.length() == 0 && s.length() == 0)return true;
    if(p.length() == 0)return false;
    m=p.length();
    graph =Graph(m+1);
    for(int i=0;i<m;i++) {
        if(p[i] == '*') {
            graph.addEdge(i, i-1);
            graph.addEdge(i-1, i);
            graph.addEdge(i, i+1);
        }
    }

    vector<int> pc;
    DFS dfs = DFS(graph, 0);
    for(int i=0;i<graph.V();i++) {
        if(dfs.marked(i)) pc.add(i);
    }

    if(s.length() == 0){
        for(int v:pc)if(v == m) return true;
    }

    for(int i=0;i<s.length();i++){
        vector<int> match;
        for(int v : pc){
            if (v == m) continue;
            if(p[v] == s[i] || p[v] == '.'){
                match.add(v+1);
            }
        }
        pc.clear();
        dfs = new DFS(graph, match);
        for(int v=0;v<graph.V();v++) {
            if(dfs.marked(v)) pc.push_back(v);
        }
    }

    for(int v:pc)if(v == m) return true;
    return false;
    }
}

int main(){
	int a = Solution.isMatch("aa","a*");
	cout <<a;
	return 0;
}
/*
 * Non-Deterministic Finite Automata solution
 * Use Thompson algorithm, Once NFA created, lookup will very fast,
 * especially for long string.
 *
 * Then first step is build NFA machine.
 */