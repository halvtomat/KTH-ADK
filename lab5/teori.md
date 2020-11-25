# Teoriuppgifter

1. Vad skiljer en heuristik från en approximationsalgoritm?
2. Rollbesättningsproblemet i labb 5 är ett minimeringsproblem. Vad är målfunktionen för problemet?
3. I labb 5 har så kallade superskådisar införts i rollbesättningsproblemet. Varför behövde superskådisar införas i labb 5?
4. Om lokalsökning ska användas som heuristik för rollbesättningsproblemet behövs en metod för lokal modifiering av en lösning. Föreslå en lokal modifiering för rollbesättningsproblemet!
5. Vid lokalsökning gör man lokala modifieringar som inte försämrar målfunktionens värde upprepade gånger. Bevisa att detta tillvägagångssätt (med din lokala modifiering från uppgift 4) inte alltid leder till att den optimala lösningen hittas.
6. Varför fungerar inte ditt bevis i uppgift 5 om Simulated annealing används istället för upprepad lokal förbättring.
7. När bör man sluta göra upprepade lokala modifieringar vid lokalsökning? Det vill säga, hur länge ska man hålla på?
8. Vad finns det för fördelar med att införa slump i en heuristik?

## Svar

### 1
En approximationsalgoritm är en *effektiv* algoritm som kan hitta approximativa lösningar av ett problem med en garanterad marginal till den optimala lösningen.
En heuristik är något som snabbt kan hitta en lösning på ett problem men som inte är garanterat optimal eller rimlig.

### 2
Antalet skådespelare som behövs för att fylla alla roller i en film.

### 3
Superskådisarna gör problemet enkelt lösbart (lika många superskådisar som roller löser problemet) och gör så att vi kan fokusera på att göra lösningen så bra som möjligt istället för att hitta en optimal lösning direkt (finns ingen känd algoritm som kan lösa problemet optimalt).

### 4
En lokal modifiering hade kunnat vara att byta ut en superskådis mot en vanlig skådis (som enligt reglerna kan fylla den rollen) i en roll.

### 5
Det kan till leda till att exempelvis en vanlig skådis blockerar en annan vanlig skådis ifrån en roll där den andra skådisen hade varit en bättre kandidat för rollen.

### 6
Simulated annealing skulle kunna vara att man i början tillåter vanliga skådisar att byta med varandra och då undviks mitt resonemang i fråga 5.

### 7
Man bör sluta göra lokala modifieringar när antingen lösningen anses vara optimal *eller* när en maxtid är uppnådd (för att undvika att algoritmen aldrig avslutas).

### 8
Om slump införs i en heuristik så finns möjlighet att hitta varianter av lösningar som annars inte hade upptäckts, detta kan vara en bra startpunkt för en bättre lösning.