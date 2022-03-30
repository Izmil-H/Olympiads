import java.util.*;
import java.io.*;
public class dmoj_worline_convergence {
	static BufferedReader br ;
	static PrintWriter pr;
	static StringTokenizer st;
	
	static int n;
	static long[] bit;
	static ArrayList<ArrayList<Integer>> adj;
	static int root;
	static int[] order;
	static long[] ans;
	static long mod = 1000000007;
	static int [] head;
	static int [] nxt;
	static int [] v;
	public static void main(String[] args) throws IOException{
		
		br = new BufferedReader(new InputStreamReader(System.in));
		pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 
		n = readInt();
		head = new int[n+1];
		v = new int[n+1];
		nxt = new int[n+1];
		Arrays.fill(head,  -1);
		int tot=0;
		
		for(int i = 1; i <= n; i++){
			int p = readInt();
			if(p == 0){
				root = i;
			}
			else{
				v[tot]=i; nxt[tot]=head[p]; head[p]=tot++;
			}
		}
		
		bit = new long[n + 1];
		order = new int[n + 1];
		ans = new long[n + 1];
		
		for(int i = 1; i <= n; i++)
			order[readInt()] = i;
		
		dfs(root);

		for(int i = 1 ; i <= n; i++)
			pr.print(ans[i] + " ");
		pr.close();
	}

	public static void dfs(int i){
		long old = query(order[i]);
		for(int u=head[i]; u!=-1; u=nxt[u])
				dfs(v[u]);
		ans[i] = (query(order[i]) + 1 - old + mod) % mod;
		update(order[i], ans[i]);
	}
	
	static long query(int index){
		long sum = 0;
		while(index > 0){
			sum = sum + bit[index];
			index -= (index & -index);
		}
		return sum;
	}
	
	static void update(int index, long val){
		while(index <= n){
			bit[index] = bit[index] + val;
			index += (index & -index);
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