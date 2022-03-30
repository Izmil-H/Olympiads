import java.util.*;
import java.io.*;
import java.math.*;
public class homework {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
    	boolean adj[][] = new boolean[50][50];
    	int [] u = {1, 2, 6, 3, 4, 5, 3, 4, 7, 3, 3, 8, 9, 9, 15, 12, 12, 11, 13, 16, 16, 18};
    	int [] v = {6, 6, 7, 6, 6, 6, 4, 5, 8, 5, 15, 9, 10, 12, 13, 13, 11, 10, 14, 18, 17, 17};
    	for(int i=0; i<u.length; i++)
    		adj[u[i]][v[i]] = adj[v[i]][u[i]] = true;
    	while(true) {
    		String op = readLine();
    		if(op.equals("q")) break;
    		if(op.equals("i")) {
    			int x = readInt(), y = readInt();  adj[x][y] = adj[y][x] = true;
    		}else if(op.equals("d")) {
    			int x = readInt(), y = readInt();  adj[x][y] = adj[y][x] = false;
    		}else if(op.equals("n")) {
    			int deg = 0, x = readInt();
    			for(int i=1; i<50; i++)
    				if(adj[x][i]) deg++;
    			System.out.println(deg);
    		}else if(op.equals("f")) {
    			int x = readInt(); List<Integer> friend = new ArrayList();
    			for(int i=1; i<50; i++)
    				if(adj[x][i]) friend.add(i);
    			Set<Integer> ff = new HashSet();
    			for(int i: friend) 
    				for(int j=1; j<50; j++)
    					if(adj[i][j] && !adj[x][j] && x != j) ff.add(j);
    			System.out.println(ff.size());
    		}else if(op.equals("s")) {
    			int x = readInt(), y = readInt(), dis[] = new int[50]; boolean vis[] = new boolean[50];
    			Queue<Integer> q = new LinkedList();
    			q.add(x); vis[x]=true; dis[x]=0;
    			while(!q.isEmpty()) {
    				int cur = q.poll();
    				for(int nxt=1; nxt<50; nxt++) {
    					if(adj[cur][nxt] && !vis[nxt]) { q.add(nxt); vis[nxt]=true; dis[nxt]=dis[cur]+1; }
    				}
    			}
    			System.out.println(vis[y]? dis[y] : "Not connected");
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