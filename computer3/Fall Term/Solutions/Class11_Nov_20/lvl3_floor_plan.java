import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), rows = readInt(), cols = readInt();  char g[][] = new char[rows][cols];
		for(int i=0; i<rows; i++)
			g[i] = readLine().toCharArray();
		int rooms = 0; List<Integer> size = new ArrayList();
		boolean vis[][] = new boolean[rows][cols]; Queue<Integer> qr = new LinkedList(), qc = new LinkedList();
		int dir[][] = {{-1,0},{1,0},{0,-1},{0,1}};
		for(int r=0; r<rows; r++) {
			for(int c=0; c<cols; c++) {
				if(!vis[r][c] && g[r][c] == '.') {//find a new room
					rooms++; int sz = 0;
					qr.add(r); qc.add(c); vis[r][c]=true;
					while(!qr.isEmpty()) {
						int r0 = qr.poll(), c0 = qc.poll(); sz++;
						for(int k=0; k<4; k++) {
							int nr = r0+dir[k][0], nc = c0+dir[k][1];
							if(nr>=0 && nr<rows && nc>=0 && nc<cols && !vis[nr][nc] && g[nr][nc]=='.') {
								qr.add(nr); qc.add(nc); vis[nr][nc]=true;
							}
						}
					}
					size.add(sz);
				}
			}
		}
		Collections.sort(size, Collections.reverseOrder());
		int ans = 0;
		for(int i=0; i<size.size(); i++) {
			if(n >= size.get(i)) {
				ans++; n-=size.get(i);
			}else break;
		}
		if(ans == 1) System.out.println(ans +" room, " + n +" square metre(s) left over");
		else System.out.println(ans +" rooms, " + n +" square metre(s) left over");
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