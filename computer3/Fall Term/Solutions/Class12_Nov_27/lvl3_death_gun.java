import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int m = readInt(), maxV = 2000, in[] = new int[maxV]; List<Integer> adj[] = new ArrayList[maxV];
		Map<String, Integer> map = new HashMap<>();
		List<String> list = new ArrayList<>();
		for(int i=1; i<=m; i++) {
			String a = next(), b = next();
			if(!map.containsKey(a)) { 
				map.put(a, list.size()); 
				adj[list.size()] = new ArrayList<>(); 
				list.add(a); 
			}
			if(!map.containsKey(b)) { 
				map.put(b, list.size()); 
				adj[list.size()] = new ArrayList<>();
				list.add(b); 
			}
			adj[map.get(b)].add(map.get(a));  in[map.get(a)]++;
		}
		PriorityQueue<Integer> q = new PriorityQueue<>();
		for(int i=0; i<list.size(); i++) {
			if(in[i] == 0) q.add(i);
		}
		while(!q.isEmpty()) {
			int u = q.poll();
			System.out.println(list.get(u));
			for(int v : adj[u]) {
				in[v]--;
				if(in[v] == 0) q.add(v);
			}
		}
		
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