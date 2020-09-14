public class partDist_test {
    static int count = 0;
    private static int partDist(String w1, String w2, int w1len, int w2len) {
        count++;
        if (w1len == 0)
          return w2len;
        if (w2len == 0)
          return w1len;
        int res = partDist(w1, w2, w1len - 1, w2len - 1) + 
        (w1.charAt(w1len - 1) == w2.charAt(w2len - 1) ? 0 : 1);
        int addLetter = partDist(w1, w2, w1len - 1, w2len) + 1;
        if (addLetter < res)
          res = addLetter;
        int deleteLetter = partDist(w1, w2, w1len, w2len - 1) + 1;
        if (deleteLetter < res)
          res = deleteLetter;
        return res;
    }
    public static void main(String[] args) {
        
        for(int i = Integer.parseInt(args[3]); i >= 0; i--){
            for(int j = 0; j <= Integer.parseInt(args[2]); j++){
                int res = partDist(args[0],args[1],j,i);
                System.out.print(res + ",");
            }
            System.out.print('\n');
        }
        //partDist(args[0], args[1], Integer.parseInt(args[2]), Integer.parseInt(args[2]));
        //System.out.println(count);

        
    }

}
