# Uppgift 1/ Task 1

## Pseudokod

    NumberOfOnes(v, lower, upper){
        if(isZero(v,lower, upper)) return 0
        if(lower >= upper) return 1
        return NumberofOnes(v, lower, upper/2) +
            NumberOfOnes(v, (upper/2)+1, upper)
    }

### Enhetskostnad
För varje *NumberOfOnes* kommer *isZero* köra 1 gång, om *isZero* är falsk kommer även en jämförelse mellan *lower* och *upper* göras.
Enhetskostnaden blir då *isZero* + en >= jämförelse.

## Algortimanalys

### Tidskomplexitet
I värsta fall, när alla bitar i *v* är 1, så kommer *NumberOfOnes* köras
*n* log *n* gånger. I bästa fall, när alla bitar i *v* är 0, så kommer
*NumberOfOnes* köras 1 gång.
Tidskomplexiteten är alltså O(1 + *k* log *n*) där *k* är antalet ettor i *v* och *n* är längden på *v*.

### Korrekthetsanalys
Genom att bevisa att de 2 basfallen stämmer samt med hjälp av induktionsbevis bevisa att algoritmen stämmer för *NumberOfOnes(n)* och *NumberOfOnes(n+1)* kan man bevisa att algoritmen är korrekt.