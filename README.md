# Antroji-programa 0.2
Yra menu, kuris paaiškina kaip programą naudot. Viskas nuo sio tasko bus ištraukos iš meniu.
Pradžia:
(Jei norite) "Pradeti naujo mokinio info ivedima- 1".
"Rodyti visu mokiniu vidurkius- 2"
"Rodyti visu mokiniu medianas- 3"
"Skaityti mokiniu info is failo- 4"
"Rodyti mokiniu info- 5"
"Rodyti komandas- 0"

Įvedus 1 išvedama:
  "Iveskite n'ojo mokinio varda ir pavarde"
  Po divejų žodžių įvedimo, išvedama:
  "Jei norit patys ivesti pazymius- iveskit 0. Ivedus kita skaiciu pazymiu skaicius ir reiksmes bus atsitiktines"
  Įvedus 0 išvedama:
    "Iveskite Nd pažymius. Ivedus maziau nei 1 baigsis ivestis: "
    įvedus mažiau nei 1, baigiasi Nd ivestis ir išvedama:
    "Egzamino pazymys: "
    Įvedus dar vieną skaičių, vartotojas grąžinamas į meniu.
    
  Įvedus ne nulį (pasirinkus atsitiktinius namų darbų ir egzamino pažymius), jie generuojami ir išvedami intervale [1;10].
  Generuojant pažymius kurie nėra pirmi, yra 2/13 tikimybė užbaigti generaciją, todėl jų skaičius yra atsitiktinis
  (generuoja intervale [-1:10], sugeneravus mažesnį nei 0, generavimas baigiasi). Gražinamas į meniu.

Įvedus 2 (kol esate meniu), išrykiuoja naujus mokinius nuo praeito rykiavimo, išveda išrykiuotų(bubble sort) mokinių vardus, pavardes,
galutinius įvertinimus naudojant vidurkius. Viskas lygiuota. Grąžinama į meniu.
Įvedus 3, tas pats kaip ir 2, tik galutiniams pažymiams naudojamos medianos.
Įvedus 4, nuskaitomi naujo mokiniai iš failo "kursiokai". Grąžinama į meniu
Įvedus 5, rodo mokinių vardus, pavardes, Nd ir egzaminio pažymius.
Įvedus 0, vel rodo komandų sąrašą, kurį matome pradžioje šio "readme".

# Antroji-programa 0.3
Funcijos.h ir struct.h priklauso 0.3 failui.

0.3 yra patobulinta 0.2'o versija ir dabar naudoja header failus funkcijoms ir mokiniu strukturai.

Exception'ai panaudoti tik vieną kartą 0.3 (main) faile. Jo paskirtis peršokti swtich'ą jei switch'ui naudojama įvestis nera skaičius.
Įvedus seką simboliu turinčių bent vieną ne skaičių, ši netinkama reikšmė nebus galutinai paversta į switch'o naudojamą int'a (kas nutinka jei string'as sudarytas tik iš skaičių) ir į consolę bus išvesta vartotojo įvesta netinkama reikšmė ir žodžiai " nera tinkama ivestis".
