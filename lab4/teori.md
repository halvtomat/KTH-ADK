# Teoriuppgifter
1. Skriv på valfritt sätt ned en lösning till ja-instansen av rollbesättningsproblemet som finns som indataexempel.
2. Visa att rollbesättningsproblemet ligger i NP.
3. Förändra nej-instansen i exemplet på indata till en ja-instans. Hur många skådespelare behöver du lägga till i just detta fall?
4. Vilken är den minsta möjliga produktion som uppfyller indatakraven för rollbesättningsproblemet och som går att sätta upp? Skriv upp indata för denna produktion!
5. Tänk dig en instans där rollerna är indelade i två grupper, ungefär som i matchningsproblemet, där rollerna aldrig förekommer i samma scener som roller ur  samma grupp. Hur många skådespelare behövs då?
6. Anta att film a innehåller en scen med rollerna 4, 7 och 12 medan film b har tre scener med rollerna 4 och 7, 7 och 12 samt 4 och 12. Om alla övriga villkor är identiska mellan filmerna - kommer svaren då att bli likadana? Varför/varför inte?


## Svar

### 1
```
skådespelare 1 spelar roll 1 och 3
skådespelare 2 spelar roll 4
skådespelare 3 spelar roll 2
skådespelare 4 spelar roll 6 och 5
```
### 2
Problemet ligger i NP om och endast om lösningen till problemet kan verifieras av en polynomisk algoritm
```
n = antal roller
s = antal scener
k = antal skådespelare

1. Kontrollera i varje scen så att samma skådespelare inte förekommer fler än 1 gång. O(s*n)
2. Kontrollera att inte både skådespelare 1 och skådespelare 2 förekommer i en och samma scen. O(s*n)
3. Kontrollera att skådespelare 1 och skådespelare 2 förekommer i minst 1 roll vardera. O(n)
4. Kontrollera i varje roll så att skådespelaren som blivit tilldelad den rollen kan spela den rollen. O(n*k)

```
Kontroll 1, 2 och 3 kan antagligen utföras under en och samma iteration av scenerna och kan därför reduceras till O(s*n) men kontroll 4 måste genomföras separat och därför blir den totala tidskomplexiteten O(s*n+n*k) eller O(n(s+k))

### 3
```
skådespelare 1 spelar roll 5
skådespelare 2 spelar roll 4
skådespelare 3 spelar roll 2
skådespelare 4 spelar roll 3
skådespelare 5 spelar roll 1
```
Man måste alltså lägga till 2 skådespelare


### 4
```
3
2
3
1 1
1 2
1 3
2 1 3
2 2 3
```

### 5
Samma som i uppgift 4, det behövs alltså minst 3 skådespelare


### 6
I båda filmerna behövs 3 skådespelare eftersom att ingen skådespelare kan ha 2 av rollerna 4, 7 och 12 men alla rollerna måste fyllas.