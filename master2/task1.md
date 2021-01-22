<div style="text-align: right"> Daniel Gustafsson </div>
<div style="text-align: right"> danielg8@kth.se </div>

# Uppgift 1

## NP-Komplett
För att ett problem ska vara *NP-Komplett* så måste det först visas att problemet **tillhör NP** genom att visa att en lösning av problemet kan **verifieras på polynomisk** tid och sedan måste det visas att problemet är **NP-svårt** genom att **reducera ett annat NP-svårt** problem till problemet med hjälp av en Karpreduktion.

## NP-Tillhörighet
För att verifera lösningen behöver vi testa följande kriterier:
- Är varje ruta granne med föregående ruta?
- Ligger varje ruta innanför arenan?
- Går roboten tillbaka till en tidigare ruta endast en gång?
- Är den sista rutan (*n*,*n*)?
- Är den totala mängden osmium som samlats lika med *m*

Dessa kriterier är oberoend av varandra och bör därför kunna testas på **en** iteration av lösningsvägen vilket medför att verifikationen går att utföra på **linjär** (polynomisk) tid, O(*n*).

## NP-Svårt
*Delmängdssummaproblemet* kan reduceras till *Tröttrobotproblemet* med en Karpreduktion.

Nedan följer exempel på instanser för de båda problemen.

I *Delmängdssummaproblemet* är den första raden en int *n* som anger hur stor listan *v* är följt av elementen i listan. Andra raden består av en int *k* som anger *målet*.

I *Tröttrobotproblemet* är den första raden en int *n* som anger storleken på matrisen *Os*, det räcker med en siffra eftersom att matrisen är kvadratisk. De följande *n*-2 raderna består av elementen i matrisen där varje indata rad anger en rad i matrisen. Sista raden består av en int *m* som anger målmängden Osmium.

ja-instans av *Delmängdssummaproblemet*:
    
    3 1 2 1
    3

ja-instans av *Tröttrobotproblemet*:

    5
    0 0 0 0 0
    0 1 0 0 0
    0 0 2 0 0
    0 0 0 1 0
    0 0 0 0 0
    3

nej-instans av *Delmängdssummaproblemet*:
    
    3 2 2 2
    3

nej-instans av *Tröttrobotproblemet*:

    5
    0 0 0 0 0
    0 2 0 0 0
    0 0 2 0 0
    0 0 0 2 0
    0 0 0 0 0
    3

En Karpreduktion av *Delmängdssummaproblemet* till *Tröttrobotproblemet* skulle kunna vara följande:

- Skapa en kvadratisk matris med storlek *n* + 2.
- Fyll rad 0 och rad *n* med nollor.
- Fyll resterande rader med radnummer *i* med nollor förutom (*i*, *i*) som får värdet v[*i*]. 

- Målmängden Osmium = *k*

Tidskomplexiteten för reduktionen blir O(*n*<sup>2</sup>).

Reduktionen är korrekt eftersom att roboten kan köra igenom alla olika permutationer av elementen i *v* och nå sista rutan. Detta är möjligt eftersom att matrisen är fylld med nollor som roboten kan köra på utan att samla osmium.

### Pseudokod
    int n;
    stdin >> n
    n = n+2
    stdout << n << "\n"

    int a
    for i in n {
        stdin >> a
        for j in n {
            if (i == j && (i != 0 && i != n-1))
                stdout << a << " "
            else
                stdout << "0 "
        }
    stdout << "\n"
    }

    stdin >> a
    stdout << a << "\n"

    return

