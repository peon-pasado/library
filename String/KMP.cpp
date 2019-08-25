class KMP
{
	private:
		vector<int> border;
		char* pattern;	
		int n;

		void clear() {border.clear();}
		void init(int n): n(n) {
			clear();
			border.resize(n+1);			
		}
		
	public:
		void build(char pattern[]): pattern(pattern) {
			init(strlen(pattern));
			border[0] = -1;
			int match = 0;
			for (int i = 1; i <= n; ++i) {
				if (match != -1 and pattern[i-1] != pattern[match])
					match = border[match];
				border[i] = match + 1;
			}
		}
		void solve(char text[]) {		
			int cnt = 0;
			int match = 0;
			for (int i = 0; text[i]; ++i) {
				while (match != -1 and pattern[match] != text[i]) 
					match = border[match];
				match += 1;
				if (match == n) {
					cnt += 1;
					match = border[match];
				}
			}
			return cnt;
		}
};





