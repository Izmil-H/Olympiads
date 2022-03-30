import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int T, G, rem, way = 0, pts[] = new int[5]; static boolean game[][]=new boolean[5][5];
    public static void main(String [] args) throws IOException{
    	T = readInt(); G = readInt(); rem = 6 - G;
    	for(int i=0; i<G; i++){
    		int x = readInt(), y = readInt(), px = readInt(), py = readInt(); game[x][y]=game[y][x]=true;
    		if(px > py) pts[x] += 3;
    		else if(px < py) pts[y] += 3;
    		else { pts[x]++; pts[y]++; }
    	}
    	solve();  System.out.println(way);
    }
    static void solve(){
    	if(rem == 0){ //base case
    		for(int i=1; i<=4; i++)
    			if(i != T && pts[i] >= pts[T]) return;
    		way++; return;
    	}
    	boolean [][] backup = new boolean[5][5];
    	for(int i=0; i< backup.length; i++) backup[i] = game[i].clone();
    	for(int x=1; x<=4; x++){
    		for(int y=x+1; y<=4; y++){
    			if(!game[x][y]){
    				game[x][y] = true; rem --;
    				for(int k=0; k<3; k++){
    					if(k==0){ pts[x] += 3; solve(); pts[x]-=3; } //assume x win
    					if(k==1){ pts[y] += 3; solve(); pts[y]-=3; } //assume y win
    					if(k==2){ pts[x]++; pts[y]++; solve(); pts[x]--; pts[y]--; }
    				}
    				rem++;
    			}
    		}
    	}
    	for(int i=0; i< backup.length; i++) game[i] = backup[i].clone();
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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}