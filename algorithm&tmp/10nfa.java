class Graph{
    private final int V;           
    private int E;                 
    private LinkedList<Integer>[] adj;    
    public Graph(int V) {
        this.V = V;
        this.E = 0;
        adj = (LinkedList<Integer>[]) new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<Integer>();
        }
    }
    public int V() {
        return V;
    }
    public int E() {
        return E;
    }
    public void addEdge(int v, int w) {
        adj[v].add(w);
        E++;
    }
    public Iterable<Integer> adj(int v) {
        return adj[v];
    }
}

class DFS{
    private boolean[] marked;  
    private int count;         
    public DFS(Graph G, int s) {
        marked = new boolean[G.V()];
        dfs(G, s);
    }
    public DFS(Graph G, Iterable<Integer> sources) {
        marked = new boolean[G.V()];
        for (int v : sources) {
            if (!marked[v]) dfs(G, v);
        }
    }
    private void dfs(Graph G, int v) { 
        count++;
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) dfs(G, w);
        }
    }
    public boolean marked(int v) {
        return marked[v];
    }
}

class Solution {
    int m;
    Graph graph;    
    public boolean isMatch(String s, String p) {
        if(p.length() == 0 && s.length() == 0)return true;
        if(p.length() == 0)return false;
        m=p.length();
        graph = new Graph(m+1);
        for(int i=0;i<m;i++) {
            if(p.charAt(i) == '*') {
                graph.addEdge(i, i-1);
                graph.addEdge(i-1, i);
                graph.addEdge(i, i+1);
            }
        }

        LinkedList<Integer> pc = new LinkedList<Integer>();
        DFS dfs = new DFS(graph, 0);
        for(int i=0;i<graph.V();i++) {
            if(dfs.marked(i)) pc.add(i);
        }

        if(s.length() == 0){
            for(int v:pc)if(v == m) return true;
        }

        for(int i=0;i<s.length();i++){
            LinkedList<Integer> match = new LinkedList<Integer>();
            for(int v : pc){
                if (v == m) continue;
                if(p.charAt(v) == s.charAt(i) || p.charAt(v) == '.'){
                    match.add(v+1);
                }
            }
            pc.clear();
            dfs = new DFS(graph, match);
            for(int v=0;v<graph.V();v++) {
                if(dfs.marked(v)) pc.add(v);
            }
        }

        for(int v:pc)if(v == m) return true;
        return false;
    }
}

