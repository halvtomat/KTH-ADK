# Mästarprov 1

## Uppgift 1 Dator med extra bitoperationer
Betygskriterium: *utveckla algoritmer med datastrukturer för enkla problem givet en konstruktionsmetod.*

Du ska skriva en algoritm för en lite ovanlig dator. Utöver de vanliga operationerna som finns på alla datorer så har den här datorn också en funktion IsZero(*v*, *i*, *j*) som returnerar true om bitvektorn *v* endast innehåller nollor på positionerna från *i* till och med *j*. IsZero tar konstant tid att exekvera (vilket kanske inte är helt realistiskt).

Skriv en funktion NumberOfOnes(*v*) som returnerar antalet ettor i bitvektorn *v*. Funktionen ska ha tidskomplexitet O(1+ *k* log *n*), där *k* är resultatet av anropet (dvs antalet ettor i *v*) och *n* är längden på *v*. Ettan i ordouttrycket finns för att klara av fallet att *k* är noll.

Din algoritm ska vara en dekompositionsalgoritm och uttryckt i pseudokod. Analysera algoritmens tidskomplexitet med **enhetskostnad**; storleken på indata är antalet bitar i vektorn *v*. Något korrekthetsbevis för din pseudokod behövs inte i denna uppgift, men du ska redogöra för vad som skulle behöva visas i ett korrekthetsbevis.

## Uppgift 2 Trött robot
Betygskriterium: *utveckla algoritmer med datastrukturer för icketriviala problem.*

En robot befinner sig i övre hörnet på ett sluttande plan i form av ett kvadratiskt rutnät av storlek *n* gånger *n*. Hela planet är täckt av tjock snö och roboten har inte så mycket laddning kvar, så den behöver utnyttja planets lutning för att orka genomföra sitt uppdrag innan batteriet tar slut. Uppdraget är att samla ihop så mycket osmium som möjligt och transportera det till det nedersta hörnet på det sluttande planet. I varje steg kan roboten röra sig antingen en ruta snett ned till vänster eller en ruta snett ned till höger, vilket innebär att den från ruta (*i*,*j*) kan röra sig antingen till (*i*+1,*j*) eller (*i*,*j*+1), se bilden. Men vid ett (och endast ett) tillfälle under vandringen orkar roboten backa till rutan som den just kom ifrån (vilket innebär att den åker i uppförsbacke - att det ens är möjligt beror på att snön är nedtrampad av roboten i alla rutor som den passerat). Roboten kan aldrig röra sig utanför planet (rutnätet).

Som tur är känner vi till exakt hur mycket osmium som finns att hämta i varje ruta i rutnätet. I ruta (x,y) finns Os[x,y] gram osmium (ett ickenegativt heltal). Första gången roboten når en ruta samlar den in allt osmium som finns i den rutan, så om roboten återkommer till samma ruta en andra gång så finns det inget osmium kvar i rutan att samla in. Det kan ändå vara givande för roboten att backa tillbaka till rutan som den just kom ifrån eftersom den då har möjlighet att välja en annan väg än den tog förra gången. Som sagt orkar den bara backa vid ett tillfälle så det gäller att välja det tillfället väl.

Konstruera en algoritm som, givet n och matrisen Os[1..*n*, 1..*n*] beräknar den maximala mängd osmium som roboten kan samla in på sin väg från startrutan (1,1) till slutrutan (*n*,*n*) genom att välja vägen och tillfället för backningen på det optimala sättet.

Beskriv algoritmen med pseudokod och analysera dess tidskomplexitet. Den måste vara polynomisk i *n*. Använd enhetskostnad. Vi räknar alltså med att det tar konstant tid att addera två tal. Motivera också att algoritmen är korrekt.

## Uppgift 3 Lite mindre trött robot
Betygskriterium: *utveckla algoritmer med datastrukturer för svårare problem med den metod som passar bäst.*

Roboten i uppgift 2 ovan ersätts av en lite mindre trött robot som ska utföra samma uppdrag. Enda skillnaden är att den mindre trötta roboten under sin vandring orkar backa två gånger (antingen två steg i rad eller ett steg vid två olika tillfällen).

Konstruera en algoritm som, givet n och matrisen Os[1..n, 1..n] beräknar den maximala mängd osmium som den mindre trötta roboten kan samla in på sin väg från startrutan (1,1) till slutrutan (n,n) och skriver ut både den maximala mängden och en instruktion (som du själv väljer lämplig syntax för) för hur roboten kan vandra för att samla in denna maximala mängd.

Algoritmen ska vara så effektiv som möjligt. Analysera tidskomplexiteten för en så effektiv algoritm som möjligt som löser problemet. Visa också med en undre gräns att din algoritm är optimal.
Du ska också tydligt tala om vad som krävs (allmänt sett) för att bevisa korrektheten för den typ av algoritm som du skrivit och sedan bevisa korrektheten för din algoritm.



