import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int game, team, ways=0, remain[][], pts[];
	public static void main(String[] args) throws IOException, InterruptedException {
		team = readInt(); game = readInt(); pts = new int[5];  
		boolean vis[][] = new boolean [5][5];
		for(int i=1; i<=game; i++) {
			int a = readInt(), b = readInt(), sa = readInt(), sb=readInt();
			vis[a][b] = true;  
			if(sa > sb) pts[a]+=3;
			else if(sa < sb) pts[b]+=3;
			else { pts[a]++;  pts[b]++;}
		}
		int rest = 6 - game, cnt = 0;  remain = new int[rest][2];
		for(int i=1; i<=4; i++)
			for(int j=i+1; j<=4; j++)
				if(!vis[i][j]) { remain[cnt][0]=i; remain[cnt][1]=j; cnt++;}
		fun(cnt-1);  
		System.out.println(ways);
	}
	static void fun(int idx) {
		if(idx < 0) { //base case
			for(int i=1; i<=4; i++)
				if(i != team && pts[i] >= pts[team]) return;
			ways++;  return;
		}
		int x = remain[idx][0],  y = remain[idx][1];
		pts[x] += 3;   //assume x win
		fun(idx-1);
		pts[x] -= 3;  pts[y]+=3 ;  //assume y win
		fun(idx-1);
		pts[y]-= 3;   pts[x]++;  pts[y]++;  //assume tie;
		fun(idx-1);
		pts[x]--; pts[y]--;
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