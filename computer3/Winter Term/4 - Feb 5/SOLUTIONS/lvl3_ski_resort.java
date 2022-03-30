import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int N, K, ans[], head[], nxt[], cnt=0, s[]; static long edge[], MV=(long)1e6;
	public static void main(String[] args) throws IOException {
		N = readInt(); K = readInt(); ans = new int[N+1]; head = new int[N+1];
		Arrays.fill(head, -1);
		nxt = new int[2*N]; edge = new long[2*N];
		for(int i=1; i<N; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			nxt[cnt]=head[u]; edge[cnt]=w*MV + v; head[u] = cnt++;
			nxt[cnt]=head[v]; edge[cnt]=w*MV + u; head[v] = cnt++;
		}
		s = new int[K];
		for(int i=0; i<K; i++) s[i] = readInt();
		Arrays.sort(s);
		dfs(1, 0, 0, K-1);
		for(int i=1; i<N; i++) System.out.print(ans[i] + " ");
		System.out.println(ans[N]);
	}
	static void dfs(int u, long pa, int L, int R) {
		ans[u] = R - L + 1; List<Long> lst = new ArrayList<>();
		for(int i=head[u]; i!=-1; i=nxt[i]) {
			if(edge[i] != pa) lst.add(edge[i]);
		}
		if(lst.isEmpty()) return;
		Collections.sort(lst);
		int last = L;
		for(int i=0; i+1 < lst.size(); i++) {
			int lft = last, rit = R;
			int lw = (int)(lst.get(i)/MV), lv = (int)(lst.get(i)%MV);
			int rw =  (int)(lst.get(i+1)/MV), rv = (int)(lst.get(i+1)%MV);
			int mw = (lw + rw)/2, pos = 0;
			if(Math.abs(s[lft]-lw) > Math.abs(s[lft] - rw)) continue;
			while(lft <= rit) {
				int mid = (lft + rit)/2;
				if(s[mid] <= mw) {
					pos = mid; lft = mid + 1;
				}else rit = mid - 1;
			}
			dfs(lv, lw*MV + u, last, pos);
			last = pos + 1;
			if(pos == R) break;
		}
		if(last <= R) {
			int w = (int)(lst.get(lst.size()-1)/MV), v = (int)(lst.get(lst.size()-1)%MV);
			dfs(v, w*MV+u, last, R);
		}
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}