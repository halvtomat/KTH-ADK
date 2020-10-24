# Mästarprov 1

## Uppgift 1 Dator med extra bitoperationer
Betygskriterium: *utveckla algoritmer med datastrukturer för enkla problem givet en konstruktionsmetod.*

Du ska skriva en algoritm för en lite ovanlig dator. Utöver de vanliga operationerna som finns på alla datorer så har den här datorn också en funktion IsZero(*v*, *i*, *j*) som returnerar true om bitvektorn *v* endast innehåller nollor på positionerna från *i* till och med *j*. IsZero tar konstant tid att exekvera (vilket kanske inte är helt realistiskt).

Skriv en funktion NumberOfOnes(*v*) som returnerar antalet ettor i bitvektorn *v*. Funktionen ska ha tidskomplexitet O(1+ *k* log *n*), där *k* är resultatet av anropet (dvs antalet ettor i *v*) och *n* är längden på *v*. Ettan i ordouttrycket finns för att klara av fallet att *k* är noll.

Din algoritm ska vara en dekompositionsalgoritm och uttryckt i pseudokod. Analysera algoritmens tidskomplexitet med **enhetskostnad**; storleken på indata är antalet bitar i vektorn *v*. Något korrekthetsbevis för din pseudokod behövs inte i denna uppgift, men du ska redogöra för vad som skulle behöva visas i ett korrekthetsbevis.
