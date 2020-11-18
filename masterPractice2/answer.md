# Np fullständighet

Vi kan visa att ett problem är *Np-fullständigt* om vi kan både visa att problemet ligger i Np och visa att problemet är Np-svårt. 

## Np-tillhörighet

För att visa att problemet ligger i Np så räcker det med att kunna verifera en lösning på polynomisk tid.

En lösning för *lika vikt*-problemet ges av 2 delmängder *a* och *b* där summan av vikterna i *a* och *b* är samma. 
Krav är också att *a* och *b* är delmängder av indatan samt att varje element i indatan förekommer en och endast en gång i någon av delmängderna *a* och *b*.

Det vill säga om indata är (1, 2, 3, 4) så är svaret *ja* eftersom man kan dela upp vikterna i grupperna (1, 4) och (2, 3) som båda har totalvikten 5 och varje element i indatan förekommer en och endast en gång i någon av delmängderna.

Denna verifikation bör gå att genomföra på O(*n<sup>2</sup>*) med följande algoritm.

1. Gå igenom delmängderna och beräkna summan av dem enskilt och för varje element, ta bort motsvarande element infrån indatan. O(*n<sup>2</sup>*)

2. Kolla så att det inte finns några element kvar i indatan. O(1)

3. Kolla så att summan av första delmängden är lika med summan av andra delmängden. O(1)

## Np-Svårt

För att visa att *lika vikt*-problemet är *Np-svårt* måste vi reduceera ett redan känt *Np-svårt* problem till Lika vikt problemet.

Följande algoritm reducerar en instans av *delmängdssumma*-problemet till en instans av *lika vikt*-problemet.

Givet en instans av *delmängdssumma*-problemet,

P = [x<sub>1</sub>, x<sub>2</sub>, x<sub>3</sub>, .. , x<sub>n</sub>]

K = y

Så får vi följande instans av *lika vikt*-problemet,

Indata = [x<sub>1</sub>, x<sub>2</sub>, x<sub>3</sub>, .. , x<sub>n</sub>, x<sub>n+1</sub>]

där x<sub>n+1</sub> = |2*y* - SUM(*P*)|

Algoritmen utnyttjar att *lika vikt*-problemet och *delmängdssumma*-problemet är ekvivalenta när 

*K* = SUM(*P*)/2 och *indata* = *P*

Eftersom att om det då finns en delmängd av P som har summa K, så finnsdet också ett komplement till den delmängden som har summa K.

Om *K* != SUM(*P*)/2 så används algoritmen för att lägga till ett kompleterande element i indata-listan som gör så att *K* = SUM(*indata*)/2 och därmed blir instanserna lika.
Absolutbeloppet används för fall där *K* < SUM(*P*)/2, utan absolutbelopp hade det då blivit ett negativt tal som hade varit ogiltigt.

Tidskomplexiteten för reduktionen är O(*n*) där *n* är antalet element i *P*.

Beräkna summan av *P*, O(*n*), Resterande operationer ,O(1)

Reduktionen är korrekt eftersom att om det finns en lösning till *delmängdssumma*-problemet så finns det en delmängd i indata för *lika vikt*-problemet som är lika med hälften av summan av hela indatan, vilket medför att resterande av indatan har samma summa och är då en lösning.