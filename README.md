# Rotacja prostokąta 2D

## Budowanie programu

Program zawiera pliki cmake które generują odpowiednie foldery i pliki Makefile

Aby zbudować project należy wypisać w terminal:

    $ mkdir build && cd build
    
    $ cmake ..
    
Wygeneruje to nam 2 pliki Makefile:

* build/Makefile tworzący program Rotation2D_run
* build/test/Makefile tworzący program Rotation2D_tst

## Rotation2D_run

Po odpaleniu programu należy podać mu 4 wieszchołki figury a następnie pokaże się proste menu:

    Menu:
    R - set Rotation
    Z - set Rotation Around Zero
    T - set Translate
    S - set Scale
    L - set Number Of Loops
    P - print vertexes
    p - print size of sides
    r - run
    s - simulate
    E - exit
   
Na początku możemy określić jake chcemy przetworzenie figury (wybierając opcje R, Z, T, S), później wybieramy
jak wiele razy ma się to powtórzyć (wyberiając opcje L {domyślnie 1}), na koniec możemy odpalić graficznie (z GNUPlotem) 
wybierając opcje run lub możemy zasymulować (bez GNUPlota) wybierając opcje simulate.

Program może też wypisywać położenie wierzchołków oraz długości boków (P - print vertexes, p - print size of sides)

## Rotation2D_tst

Program zawiera 32 testy, sprawdzająca wszystkie aspekty klas Vector2D, Matrix22, Transform oraz Rectangle. Po którym 
odpaleniu ma pokazać poprawność 32 testów:

    [  PASSED  ] 32 tests.

## Uwagi

### Szablony klas

Klasy Vector2D, Matrix i Rectangle korzysta z szablonów klas dlatego ich deklaracja i definicja musi być w jedny pliku (.h)

### Diagram

Diagram zapisałem w jako przykładowy kod w c++, który jest zawarty w kodzie.

### Vector2D

Nie korzysta z stałej tablicy ponieważ tak nie pisze się wektorów dwu wymiarowych, tylko zawsze z 2 zmiennych.
Przykładem może być Vector2f z biblioteki SFML czy nawet Łącze do GNUPlot który w swojej dokumentacji ma Wektor2f zapisywanych w x i y.

### Transform

Klasa zawiera opcje rotacji, rotacji względem zera, translacji oraz scalowania klas Vectora2D oraz Rectangle.

### Rectangle

Zawiera metode getSizeOfSides który zwraca tablice 4 elementową zawierającą długości boków.
W porgramie nie występuje niedokładność przedstawiona w treści zadania związaną z wielkoma obrotami o 1 stopień.

### GNUPlot

Program potrafi animować ruch gdy odpali się opcje run z wieloma powtórzeniami.