# Antroji-programa v0.1
Programa naudoja meniu kuris priima įvestį (tik skaičius), dabartinės komandos:
"Pradeti naujo mokinio info ivedima- 1
Rodyti visu mokiniu vidurkius- 2
Rodyti visu mokiniu medianas- 3
Rodyti komandas- 0"
Šios komandos išvedamos į konsolę įjungus programą arba įvedus '0'.
Programa duoda nurodymus per konsolę, kas reiškia jog ją galima naudot ir neskaičius README, lūžta įvedus simbolius arba nesveikus skaičius kuomet reikalavo sveikų.

  Įvedus "1,vardas, pavardė " ir tada pasirinkus atsitiktinių pažymių generaciją įvedus nenulinį skaičių,
  į konsolę bus išvestos atsitiktinių pažymių (jų skaičius irgi atsitiktinis) reikšmės bei egzamino rezultatas, tada grįžtama į meniu.
       Trumpiau, norint įvesti mokinį su atsitiktiniais pažymiais, įveskit "1 (vardas) (pavardė) (skaičius)"
       
  Įvedus "1,vardas, pavardė", bet šįsyk įvedus nulį, kiti įvesti skaičiai bus priskiriami prie ND rezultatų iki tol kol bus įvestas '0'.
  Kitas įvestas skaičius bus egzaminio rezultatas (1-10 intervale) ir tada grįžtama į meniu.
      Trumpiau, norint įvesti mokinį su norimais pažymiais, įveskit "1 (vardas) (pavardė) 0 (1-n skaičių didesnių nei 0) 0 (egzamino pažymys)"
      
 Įvedus '2'(kol esama pradžioje arba jei paskutinė matoma žinutė konsolėje yra "Iveskite komanda"), lygiuotai išvedami mokinių vardai bei galutiniai rezultatai naudojant Nd. vidurkius. 
 Įvedus '3', bus tas pats kaip įvedus '2', bet apskaičiuos galutinį naudojant medianą bei prie "Galutinis" skliaustuose bus "Med.", o ne "Vid."(kas būna įvedus '2').
Kaskart paleidus išvestį (įvedus '2' arba '3'), mokiniai surykiuoti pagal vardus.

# v0.2
Visa, kas buvo praeitoje versijoje, plius dar dvi komandos:
"Skaityti mokiniu info is failo- 4
Rodyti mokiniu info- 5"
Komanda #4: įvedus '4', bus nuskaitomas failas "kursiokai.txt", mokiniai įvesti į vektorių prie kitų.
Įvygdžius #4 komandą kelis kartus, tie patys mokiniai bus pakartotinai nuskaityti.
Komanda #5 nėra būtina, bet man jos prireikė debuginant. Ji išveda į konsolę mokinių pilnus vardus, Nd. ir egzamino pažymius.
