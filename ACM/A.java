import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		while(input.hasNext()){
			int buttons=input.nextInt();
			int bulbs=input.nextInt();
			int []a=new int[bulbs];
			Arrays.fill(a, 0);
			int b,c;
			for(int i=1;i<=buttons;i++){
				b=input.nextInt();
				for(int j=1;j<=b;j++){
					c=input.nextInt();
					a[c-1]=1;
				}
			}
			int i;
			for(i=0;i<bulbs;i++){
				if(a[i]==0)break;
			}
			if(i>=bulbs)System.out.println("YES");
			else System.out.println("NO");
			
		}
	}

}
