# Antroji-programa v0.1
Programa naudoja meniu kuris priima įvestį (tik skaičius), kol kas yra šios komandos
"Pradeti naujo mokinio info ivedima- 1
Rodyti visu mokiniu vidurkius- 2
Rodyti visu mokiniu medianas- 3
Rodyti komandas- 0"
Šios komandos išvedamos į konsolę programos pradžioje arba įvedus '0'.
Programos pradžioje ir po kiekvienos komandos įvygdymo (įskaitant tolesnes įvestis, kurių reikalaus)
paprašoma įvesti vieną iš minėtų skaitinių komandų, išvedant į konsolę "iveskite komanda:"

Įvedus '1', kitas išvedama reikalavimas "Iveskite 1'ojo mokinio varda ir pavarde'
Įvedus dvi simbolių eiles atskirtas tarpu (pvz: a b, asdasdawda qeqweqweqwe, 1 *), kitas reikalavimas yra:
"Jei norit patys ivesti pazymius- iveskit 0. Ivedus kita skaiciu pazymiu skaicius ir reiksmes bus atsitiktines"
  Įvedus '0', pareikaluos namų darbų pažymių įvesties
  "Iveskite Nd pazymius. Ivedus maziau nei 1 baigsis ivestis:"
  Toliau bus priimama sveikų skaičių įvestis, neiškeliant kitų reikalavimų kol neįvesit sveiką skaičių, mažesnį už 0.
  Jei pirmas simbolis bus mažesnis už nulį (taip įvedant 0 namų darbų pažymių), bus laukiama Nd įvesties kaip ir seniau,
  todėl įvedus "0,10,0" arba "0,0,...,0,10,0", mokinio Nd pažymių skaičius bus 1, jo reikšmė-'10'.
  Programa priima skaičius didesnius nei 10 nors tokie pažymiai tiek Nd., tiek egzaminio turėtų būt neįmanomi.
  Po šios įvesties (užsibaigusios, bet neprasidėjusios skaičiu mažesniu už 0), naujas reikalavimas bus:
  "Iveskite egzamino pazymi:"
  Jį įvedus, grįžtama į meniu. Savarankiškas pažymių įvedimo trafaretas yra:
  '1'(komanda vieno mokinio įvesčiai pradėti), 1-n simbolių du kartus,
  1-n sveikų skaičių intervale [1;10] atitinkančių namų darbus, '0', vienas egzamino pažymys.
  
  Įvedus "1,vardas,pavarde" ir tada pasirinkus atsitiktinių pažymių generaciją įvedus nenulinį skaičių,
  į konsolę bus išvestos atsitiktinių pažymių reikšmės bei egzamino rezultatas, tada grįžtama į meniu.
  "Sugeneruotos reiksmes: "1-n skaičių atskirtų tarpais iš intervalo [1;10]"
  Egzamino pazymys: "iš intervalo [1;10] egzamino reikšmė" "
  
 Įvedus (iš meniu) '2', lygiuotai išvedami mokinių vardai bei galutiniai rezultatai naudojant Nd. vidurkius
 Įvedus '3', bus tas pats, bet prie "Galutinis" skliaustuose bus "Med.", o ne "Vid.", kas būna įvedus '2'.
 Tai atrodo taip:
 Pavarde Vardas Galutinis(Vid.)
-----------------------------------
a       b      2.2
a       b      5.8
Kaskart paleidus išvestį (įvedus '2' arba '3'), mokiniai surykiuoti pagal vardus.
Kol kas yra viena rimta klaida generavime, todėl kartais sugeneruos 0 pažymių ir siekiant gaut galutinį,
programa palūš. Vėlesnėse versijose tai ištaisyta.
