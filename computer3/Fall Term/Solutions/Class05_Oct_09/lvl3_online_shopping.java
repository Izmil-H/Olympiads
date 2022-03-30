import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for(int t=readInt(); t>0; t--) {
			int n = readInt(); Map<String, List<pair>> map = new HashMap();
			for(int i=1; i<=n; i++) {
				int items = readInt();
				for(int j=1; j<=items; j++) {
					String name = next(); int p = readInt(), q = readInt();
					if(!map.containsKey(name)) map.put(name, new ArrayList());
					map.get(name).add(new pair(p, q));
				}
			}
			int k = readInt(), cost = 0;
			for(int i=1; i<=k; i++) {
				String name = next(); int amount = readInt();
				Collections.sort(map.get(name));
				for(pair e: map.get(name)) {
					if(amount >= e.quantity) { cost += e.price * e.quantity;  amount -= e.quantity; }
					else { cost += e.price * amount; break; }
				}
			}
			System.out.println(cost);
		}
	}
	static class pair implements Comparable<pair>{
		int price, quantity;
		pair(int p, int q) { price = p; quantity = q; }
		public int compareTo(pair x) { 
			return Integer.compare(price, x.price);
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