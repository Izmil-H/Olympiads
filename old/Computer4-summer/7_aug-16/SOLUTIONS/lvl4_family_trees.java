import java.util.*;
public class aplusb{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		for(int t=1; t<=10; t++){
			int n = in.nextInt(); Node root = new Node();
			for(int i=1; i<=n; i++){
				String [] val = in.next().split("\\."); Node cur = root;
				for(int j=1; j<val.length; j++){
					int num = Integer.parseInt(val[j]);
					cur.mx = Math.max(num, cur.mx);
					if(! cur.child.containsKey(num)) cur.child.put(num, new Node());
					cur = cur.child.get(num);
				}
			}
			System.out.println(1 + count(root));
		}
	}
	public static long count(Node root){
		if(root == null) return 0;
		long sum = root.mx, mod = 1000000007;
		for(int ch: root.child.keySet()) { sum += count(root.child.get(ch)); sum %= mod; }
		return sum;
	}
	static class Node {
		public int mx = 0;
		public Map<Integer, Node> child;
		Node(){ mx = 0; child = new HashMap(); }
	}
}