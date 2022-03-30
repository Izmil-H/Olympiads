import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(); String s = in.next();
		for(int k=1; k<=n; k++) {
			Set<String> set = new HashSet();
			boolean flag = true;
			for(int i=0; i+k<=n; i++) {
				String sub = s.substring(i, i+k);
				if(set.contains(sub)) {
					flag = false; break;
				}
				set.add(sub);
			}
			if(flag) { System.out.println(k); return; }
		}
	}
}