import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int dis[]; static boolean vis[];
	public static void main(String[] args) throws IOException{	
	    int st = readInt(), ed = readInt(), maxV = (int)3e5;
	    dis = new int[maxV+1]; vis = new boolean[maxV+1];
	    Queue<Integer> q = new LinkedList<>();
	    q.add(st); vis[st]=true;
	    while(!q.isEmpty()){
	        int cur = q.poll();
	        if(cur -1 >= 0 && !vis[cur-1]) push(q, cur, cur-1);
	        if(cur -3 >= 0 && !vis[cur-3]) push(q, cur, cur-3);
	        if(3*cur < vis.length && !vis[3*cur]) push(q, cur, 3*cur);
	        if(cur % 2 ==0 && !vis[cur/2]) push(q, cur, cur/2);
	        if(vis[ed]) { System.out.println(dis[ed]); break;}
	    }
	}
	static void push(Queue<Integer> q, int cur, int next) {
		q.add(next); vis[next]=true; dis[next]=dis[cur]+1;
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