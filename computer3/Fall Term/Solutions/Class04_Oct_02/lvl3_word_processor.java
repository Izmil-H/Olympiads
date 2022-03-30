import java.util.*;
public class homework {
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt(); in.nextLine();
		String s[] = in.nextLine().split(" ");
		int cnt = 0; boolean need_newline = true;
		for(int i=0; i<s.length; i++) {
			if(s[i].length() + cnt > k) {
        System.out.println(); 
        cnt=0; i--; need_newline = false;
			} else {
				if(cnt != 0) System.out.print(" ");
				System.out.print(s[i]);
				cnt += s[i].length();
        need_newline = true;
			}
		}
        if(need_newline) System.out.println();
	}
}