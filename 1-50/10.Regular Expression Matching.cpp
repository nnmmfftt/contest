/*--------------------1st--------------------*/
dp solution(bottom-up)
/*--------------------2nd--------------------*/
dp solution
/*--------------------1st--------------------*/
Non-Deterministic Finite Automata solution

typedef opt (*addedge)(struct Graph g, int i);
struct Graph{
	int E;
	int V;
	int *adj;
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