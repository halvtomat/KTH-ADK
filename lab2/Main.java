import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

public class Main {
    public static List<String> readWordList(BufferedReader input) throws IOException {
        LinkedList<String> list = new LinkedList<String>();
        while (true) {
            String s = input.readLine();
            if (s.equals("#"))
                break;
            list.add(s);
        }
        return list;
    }

    public static void main(String args[]) throws IOException {
        // double start = System.currentTimeMillis();
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, "UTF-8"));
        List<String> wordList = readWordList(stdin);
        String word;
        while ((word = stdin.readLine()) != null) {
            ClosestWordsOptimized closestWords = new ClosestWordsOptimized(word, wordList);
            System.out.print(word + " (" + closestWords.getMinDistance() + ")");
            for (String w : closestWords.getClosestWords())
                System.out.print(" " + w);
            System.out.println();
        }
        // double totalTime = System.currentTimeMillis() - start;
        // System.out.println("totaltime = " + totalTime);
    }
}

class ClosestWordsOptimized {
    LinkedList<String> closestWords = null;

    int closestDistance = -1;

    int min(int a, int b, int c){
        return Math.min(a, Math.min(b,c));
    }

    int partDist(String w1, String w2, int w1len, int w2len) {
        int a[][] = new int[w1len+1][w2len+1];
        for(int i = 0; i <= w1len; i++)
            a[i][0] = i;
        for(int i = 1; i <= w2len; i++)
            a[0][i] = i;
        for(int i = 1; i <= w1len; i++){
            for(int j = 1; j <= w2len; j++){
                int sub = (w1.charAt(i-1) == w2.charAt(j-1) ? 0 : 1);
                a[i][j] = min(
                    a[i-1][j-1] + sub,
                    a[i][j-1] + 1,
                    a[i-1][j] + 1
                    );
            }
        }
        return a[w1len][w2len];
    }

    int distance(String w1, String w2) {
        return partDist(w1, w2, w1.length(), w2.length());
    }

    public ClosestWordsOptimized(String w, List<String> wordList) {
        for (String s : wordList) {
            if(Math.abs(w.length() - s.length()) > closestDistance && closestDistance != -1) continue;
            int dist = distance(w, s);
            if (dist < closestDistance || closestDistance == -1) {
                closestDistance = dist;
                closestWords = new LinkedList<String>();
                closestWords.add(s);
            }
            else if (dist == closestDistance)
                closestWords.add(s);
        }
    }

    int getMinDistance() {
        return closestDistance;
    }

    List<String> getClosestWords() {
        return closestWords;
    }
}