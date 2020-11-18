# Lika vikt

Betygskriterium: *förklara principerna, utföra enklare reduktioner mellan givna problem*.

I problemet *lika vikt* gäller det att avgöra om det går att dela upp en uppsättning med *n* prylar i två grupper så att grupperna väger exakt lika mycket.

Indata till problemet är prylarnas vikter *v1, ..., vn* uttryckta i gram (positiva heltal). 

Exempel: Om indata är (10, 30, 45, 10, 15) så är svaret *ja* eftersom man kan dela upp vikterna i grupperna (10, 30, 15) och (45, 10) som båda har totalvikten 55 gram.

Om indata är (10, 30, 45, 10) så är svaret *nej* eftersom det inte finns någon uppdelning av vikterna i två grupper som väger exakt lika mycket.

Din uppgift är att visa att detta beslutsproblem är NP-fullständigt. När du ska visa att problemet är NP-svårt ska du reducera *delmängdssumma* (givet en lista med positiva heltal P och ett mål K, finns det någon delmängd av P som har summan K?). Delmängdssumma är ett av dom nio NP-fullständiga problem som presenterades på föreläsning 25 och som i kursen anses vara känt NP-fullständiga (och därmed kan användas i NP-reduktioner).