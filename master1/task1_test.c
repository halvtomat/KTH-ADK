#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isZero(bool v[], int lower, int upper){
    for(int i = lower; i < upper; i++)
        if(v[i] == true) return false;
    return true;
}

int NumberOfOnes(bool v[], int lower, int upper){
    printf("%s%d%s%d%c", "Lower: ", lower, " Upper: ", upper, '\n');
    if(lower >= upper) return 1;
    if(isZero(v, lower, upper)) return 0;
    return NumberOfOnes(v, lower, ((upper+lower)/2)) +
        NumberOfOnes(v, ((upper+lower)/2)+1, upper);
}
int main(){
    bool v1[4];
    bool v2[4];
    bool v3[8] = {0,1,0,0,1,1,1,1};

    memset(v1, 0, sizeof(v1));
    memset(v2, 1, sizeof(v2));

    int res1 = NumberOfOnes(v1,0,sizeof(v1));
    int res2 = NumberOfOnes(v2,0,sizeof(v2));
    int res3 = NumberOfOnes(v3,0,sizeof(v3));
    printf("%d%c", res1, '\n');
    printf("%d%c", res2, '\n');
    printf("%d%c", res3, '\n');
}