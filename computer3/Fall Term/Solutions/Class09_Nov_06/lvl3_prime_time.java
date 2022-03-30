import java.io.*;
import java.util.*;

public class homework {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        for(int k=0;k<5;k++){
            int x=in.nextInt(), cnt[]=new int[x+2];
            for(int p=2;p<=x;p++){
                int n=p;
                for(int i=2; i<=Math.sqrt(n); i++){
                    while(n%i==0){
                        cnt[i]++; n=n/i;
                    }
                }
                if(n!=1)cnt[n]++;
            }
            boolean first=true;
            for(int i=2; i<=x;i++){
                if(cnt[i]!=0){
                    if(first){System.out.print(i+"^"+cnt[i]+" "); first=false;}
                    else System.out.print("* "+i+"^"+cnt[i]+" ");
                }
            }
            System.out.println();
        }
    }
}