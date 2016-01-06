import java.math.*;
public class Main {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        while(input.hasNext()){
            int m=input.nextInt();
            int a[]=new int[10005];
            int c[]=new int[10005],k=0;
            for(int i=0;i<m;i++){
                a[i]=input.nextInt();
                int tt=0;
                Arrays.sort(c, 0, k);
                for(int n=0;n<k;n++){
                    if(a[i]<=c[n]){
                        c[n]=a[i];
                        tt=1;break;}
                }
                if(tt==0)
                {c[k]=a[i];
                k++;}               
            }
            System.out.println(k);
        }
             
    }
}