import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m, bit[], ans[];
	public static void main(String[] args) throws IOException{
		n = readInt(); Tree t[] = new Tree[n]; bit = new int[n+2];
		for(int i=0; i<n; i++) t[i] = new Tree(readInt(), i);
		m = readInt(); Query q[] = new Query[m]; ans = new int[m]; 
		for(int i=0; i<m; i++) q[i] = new Query(readInt(), readInt(), readInt(), i);
		Arrays.sort(t); Arrays.sort(q);
		for(int i=0, j=0; i<m; i++){
			while(j <n && t[j].m >= q[i].v){
				update(t[j].id, t[j].m); j++;
			}
			ans[q[i].id] = query(q[i].r) - query(q[i].l-1);
		}
		for(int i=0; i<m; i++) System.out.println(ans[i]);
	}
	public static void update(int pos, int val){
		for(pos++; pos<=n; pos+=pos&-pos) bit[pos]+=val;
	}
	public static int query(int pos){
		int sol = 0;
		for(pos++; pos>0; pos-=pos&-pos) sol += bit[pos];
		return sol;
	}
	public static class Tree implements Comparable<Tree>{ 
		int m, id;
		Tree(int m0, int i0){ m=m0; id = i0;}
		public int compareTo(Tree a){ return -Integer.compare(m, a.m); }
	}
	public static class Query implements Comparable<Query>{
		int l, r, v, id;
		Query(int l0, int r0, int v0, int i0){ l=l0; r=r0; v=v0; id = i0;}
		public int compareTo(Query a){ return -Integer.compare(v, a.v); }
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