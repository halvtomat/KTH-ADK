import java.sql.Time;

public class partDist_test {
    static int count = 0;

    private static int min(int a, int b, int c){
        int min = a;
        if(b < min) min = b;
        if(c < min) min = c;
        return min;
    }

    private static int partDist(String w1, String w2, int w1len, int w2len) {
        if(w1len == 0) return w2len;
        if(w2len == 0) return w1len;
        int a[][] = new int[w1len+1][w2len+1];
        for(int i = 0; i <= w1len; i++)
            a[i][0] = i;
        for(int i = 1; i <= w2len; i++)
            a[0][i] = i;
        for(int i = 1; i <= w1len; i++){
            for(int j = 1; j <= w2len; j++){
                a[i][j] = min(
                    a[i-1][j-1] + (w1.charAt(i-1) == w2.charAt(j-1) ? 0 : 1),
                    a[i][j-1] + 1,
                    a[i-1][j] + 1
                    );
            }
        }
        for(int i = w1len; i >= 0; i--){
            for(int j = 0; j <= w2len; j++){
                int res = a[i][j];
                System.out.print(res + ",");
            }
            System.out.print('\n');
        }
        return a[w1len-1][w2len-1];
    }
    public static void main(String[] args) {
        
        // for(int i = Integer.parseInt(args[3]); i >= 0; i--){
        //     for(int j = 0; j <= Integer.parseInt(args[2]); j++){
        //         int res = partDist(args[0],args[1],j,i);
        //         System.out.print(res + ",");
        //     }
        //     System.out.print('\n');
        // }
        double start = System.currentTimeMillis();
        partDist(args[0], args[1], Integer.parseInt(args[2]), Integer.parseInt(args[2]));
        double totalTime = System.currentTimeMillis() - start;
        System.out.println("Time spent: " + totalTime + "ms");
        //System.out.println(count);
    }
}
