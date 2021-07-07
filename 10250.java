// https://www.acmicpc.net/problem/10250

import java.util.Scanner;
public class Main {
    private static int getRoom(int h, int w, int n) {
        int y = n % h;
        int x = n / h + 1;
        if( y == 0 ) {
            x--;
            y = h;
        }
        return 100*y + x;
    }
    
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int c = sc.nextInt();
		for (int i=0; i<c; i++) {
		    int h = sc.nextInt();
		    int w = sc.nextInt();
		    int n = sc.nextInt();
		    System.out.println( getRoom(h,w,n) );
		}
	}
}