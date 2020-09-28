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
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, "UTF-8"));
        List<String> wordList = readWordList(stdin);
        String word;
        int a[][] = new int[40][40];
        for(int i = 0; i < 40; i++){
            a[i][0] = i;
            a[0][i] = i;
        }
        while ((word = stdin.readLine()) != null) {
            ClosestWordsOptimized closestWords = new ClosestWordsOptimized(word, wordList, a);
            System.out.print(word + " (" + closestWords.getMinDistance() + ")");
            for (String w : closestWords.getClosestWords())
                System.out.print(" " + w);
            System.out.println();
        }
    }
}

class ClosestWordsOptimized {
    LinkedList<String> closestWords = null;

    int closestDistance = -1;
    String lw = "";

    int min(int a, int b, int c){
        return Math.min(a, Math.min(b,c));
    }

    int partDist(String w1, String w2, int w1len, int w2len, int a[][]) {
        int match = matching(w2, lw);
        for(int j = match + 1; j <= w2len; j++){
            for(int i = 1; i <= w1len; i++){
                int sub = a[i-1][j-1] + (w1.charAt(i-1) == w2.charAt(j-1) ? 0 : 1);
                int del = a[i][j-1] + 1;
                int add = a[i-1][j] + 1;
                a[i][j] = min(sub, del, add);
            }
        }
        lw = w2;
        return a[w1len][w2len];
    }

    public ClosestWordsOptimized(String w, List<String> wordList, int a[][]) {
        for (String s : wordList) {
            if(Math.abs(w.length() - s.length()) > closestDistance && closestDistance != -1) continue;
            int dist = partDist(w, s, w.length(), s.length(), a);
            if (dist < closestDistance || closestDistance == -1) {
                closestDistance = dist;
                closestWords = new LinkedList<String>();
                closestWords.add(s);
            }
            else if (dist == closestDistance)
                closestWords.add(s);
        }
    }

    int matching(String s, String w){
        int len = Math.min(s.length(), w.length());
        for(int i = 0; i < len; i++)
            if(s.charAt(i) != w.charAt(i)) return i;
        return 0;
    }

    int getMinDistance() {
        return closestDistance;
    }

    List<String> getClosestWords() {
        return closestWords;
    }
}