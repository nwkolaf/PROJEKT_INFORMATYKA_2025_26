Projekt Arkanoid - C++ / SFMl
=============================
OPIS GRY
  To gra typu arkanoid w której sterując poruszającą się w lewo oraz prawo paletką musimy odbijać piłkę w celu
  zniszczenia wszystkich znajdujących się na ekranie klocków.
  Klocki mają 3 punkty życia oraz jest szansa że wypadnie z nich BONUS.
  Istnieją nastepujące opcje BONUSU:
  -Dodatkowa piłka
  -Powiększony rozmiar paletki
  -Pomniejszony rozmiar paletki
=============================
STEROWANIE:  
  MENU - sterowanie strzałkami góra dół
  GRA - poruszanie paletką strzałkami prawo lewo
  ZAPIS GRY - klawisz F5 zapisuje aktualny stan gry który jest możliwy do wczytania z okna MENU
=============================
Instrukcja uruchomienia
  Projekt napisany w C++ z użyciem biblioteki SFML 3.0.2.
  1. Upewnij się, że masz bibliotekę SFML i kompilator MinGW.
  2. Skompiluj projekt używając dołączonego skryptu `run.bat` lub komendy:
     `g++ *.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system`
=============================
Olaf Nowak
s204019
