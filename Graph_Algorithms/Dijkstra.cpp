template<typename T>
class Dijkstra 
{
	private:
		vector<vii> adj;
		vector<T> dis;	
		int n;
		void clear() {
			adj.clear();
			dis.clear();
		}
	public:
		void init(int n): n(n) {
			clear();
			adj.resize(n+1);
			dis.resize(n+1, 0);
		}
		void add_edge(int a, int b, int w) {
			adj[a].EMP(b, w);
			adj[b].EMP(a, w);
		}
		void solve(int src) {
			REP(i,1,n) dis[i] = oo;
			priority_queue<ii, vii, greater<ii>> Q;
			Q.EMP(dis[src] = 0, src);
			while (not Q.E()) {
				tie(w, q) = Q.top(); Q.pop();
				if (w != dis[q])
					for (auto node : adj[q]) {
						T path = dis[q] + node.SND;
						if (path < dis[node.FST])
							Q.EMP(dis[node.FST] = path, node.FST);
					}
			}
		}
		T dist(int v) {return dis[v];}
};
