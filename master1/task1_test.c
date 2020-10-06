#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isZero(bool v[], int lower, int upper){
    for(int i = lower; i < upper+1; i++)
        if(v[i] == true) return false;
    return true;
}

int NumberOfOnes(bool v[], int lower, int upper){
    printf("%s%d%s%d%c", "Lower: ", lower, " Upper: ", upper, '\n');
    if(lower == upper) return v[lower];
    if(isZero(v, lower, upper)) return 0;
    return NumberOfOnes(v, lower, (upper+lower)/2) +
        NumberOfOnes(v, ((upper+lower)/2)+1, upper);
}

int main(){
    bool v1[4];
    bool v2[4];
    bool v3[8] = {0,1,0,0,1,1,1,1};
    bool v4[8] = {0,0,0,0,0,0,0,1};

    memset(v1, 0, sizeof(v1));
    memset(v2, 1, sizeof(v2));

    int res1 = NumberOfOnes(v1 , 0, sizeof(v1)-1);
    int res2 = NumberOfOnes(v2 , 0, sizeof(v2)-1);
    int res3 = NumberOfOnes(v3 , 0, sizeof(v3)-1);
    int res4 = NumberOfOnes(v4 , 0, sizeof(v4)-1);
    printf("%d%c", res1, '\n');
    printf("%d%c", res2, '\n');
    printf("%d%c", res3, '\n');
    printf("%d%c", res4, '\n');
}