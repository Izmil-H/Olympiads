import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = 7, in[] = new int[n+1];
		List<Integer> adj[] = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList();
		adj[1].add(7); adj[1].add(4); adj[2].add(1); adj[3].add(4); adj[3].add(5);
		in[1]=1; in[4]=2; in[5]=1; in[7]=1;
		while(true) {
			int x = readInt(), y = readInt();
			if(x == 0) break;
			adj[x].add(y); in[y]++;
		}
		PriorityQueue<Integer> q = new PriorityQueue();
		for(int i=1; i<=n; i++) 
			if(in[i] == 0) q.add(i);
		List<Integer> ans = new ArrayList();
		while(!q.isEmpty()) {
			int u = q.poll(); ans.add(u);
			for(int v: adj[u]) {
				in[v] --;
				if(in[v] == 0) q.add(v); 
			}
		}
		if(ans.size() != n) System.out.println("Cannot complete these tasks. Going to bed.");
		else for (int x: ans) System.out.print(x + " ");
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}