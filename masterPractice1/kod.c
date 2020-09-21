#include <stdio.h>

int antalRader(int n, int len, int w[]){
    int rader = 1;
    int pos = 0;

    for(int i = 0; i < n; i++){
        pos+=w[i];
        if(pos > len) {
            rader++;
            pos = w[i];
        }
        else pos++;
    }
    return rader;
}

int main(int argc, char const *argv[]){
    int n = 10;
    int len = 25;
    int w[] = {17,4,7,3,13,2,9,2,7,6};

    int rader = antalRader(n,len,w);
    printf("%s%d%s","Den optimala lösningen är ", rader, " rader.\n");
    return 0;
}