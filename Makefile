TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
TESTS=./tests
TBIN=./tests/bin
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/LZespolona.o: ${SRC}/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o ${SRC}/LZespolona.cpp

${OBJ}/BazaTestu.o: ${SRC}/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o ${SRC}/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: ${SRC}/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o ${SRC}/WyrazenieZesp.cpp

${OBJ}/Statystyka.o: ${SRC}/Statystyka.cpp inc/Statystyka.hh
	g++ -c ${FLAGS} -o ${OBJ}/Statystyka.o ${SRC}/Statystyka.cpp


${TBIN}/test1_porownanie: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test1_porownanie ${FLAGS} -I${TESTS}/doctest ${TESTS}/test1_porownanie.cpp ${OBJ}/LZespolona.o

${TBIN}/test2_dodawanie: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test2_dodawanie ${FLAGS} -I${TESTS}/doctest ${TESTS}/test2_dodawanie.cpp ${OBJ}/LZespolona.o

${TBIN}/test3_odejmowanie: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test3_odejmowanie ${FLAGS} -I${TESTS}/doctest ${TESTS}/test3_odejmowanie.cpp ${OBJ}/LZespolona.o

${TBIN}/test4_iloczyn: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test4_iloczyn ${FLAGS} -I${TESTS}/doctest ${TESTS}/test4_iloczyn.cpp ${OBJ}/LZespolona.o

${TBIN}/test5_iloraz: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test5_iloraz ${FLAGS} -I${TESTS}/doctest ${TESTS}/test5_iloraz.cpp ${OBJ}/LZespolona.o

${TBIN}/test6_wyswietlanie: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o
	g++ -o ${TESTS}/bin/test6_wyswietlanie ${FLAGS} -I${TESTS}/doctest ${TESTS}/test6_wyswietlanie.cpp ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test7_wczytywanie: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o
	g++ -o ${TESTS}/bin/test7_wczytywanie ${FLAGS} -I${TESTS}/doctest ${TESTS}/test7_wczytywanie.cpp ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test8_sprzezenie: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test8_sprzezenie ${FLAGS} -I${TESTS}/doctest ${TESTS}/test8_sprzezenie.cpp ${OBJ}/LZespolona.o

${TBIN}/test9_modul: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test9_modul ${FLAGS} -I${TESTS}/doctest ${TESTS}/test9_modul.cpp ${OBJ}/LZespolona.o

${TBIN}/test10_WyrZsp: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o
	g++ -o ${TESTS}/bin/test10_WyrZsp ${FLAGS} -I${TESTS}/doctest ${TESTS}/test10_WyrZsp.cpp ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test11_statystyka: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/Statystyka.o ${OBJ}/BazaTestu.o ${OBJ}/WyrazenieZesp.o
	g++ -o ${TESTS}/bin/test11_statystyka ${FLAGS} -I${TESTS}/doctest ${TESTS}/test11_statystyka.cpp ${OBJ}/Statystyka.o ${OBJ}/BazaTestu.o ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o

${TBIN}/test12_wczytywanie_z_pliku: ${TBIN} ${OBJ}/LZespolona.o ${OBJ}/BazaTestu.o ${OBJ}/WyrazenieZesp.o
	g++ -o ${TESTS}/bin/test12_wczytywanie_z_pliku ${FLAGS} -I${TESTS}/doctest ${TESTS}/test12_wczytywanie_z_pliku.cpp ${OBJ}/BazaTestu.o ${OBJ}/LZespolona.o ${OBJ}/WyrazenieZesp.o


${TBIN}:
	mkdir ${TBIN}

test: ${TBIN}/test1_porownanie ${TBIN}/test2_dodawanie ${TBIN}/test3_odejmowanie ${TBIN}/test4_iloczyn ${TBIN}/test5_iloraz ${TBIN}/test6_wyswietlanie ${TBIN}/test7_wczytywanie ${TBIN}/test8_sprzezenie ${TBIN}/test9_modul ${TBIN}/test10_WyrZsp ${TBIN}/test11_statystyka ${TBIN}/test12_wczytywanie_z_pliku
	${TBIN}/test1_porownanie
	${TBIN}/test2_dodawanie
	${TBIN}/test3_odejmowanie
	${TBIN}/test4_iloczyn 
	${TBIN}/test5_iloraz
	${TBIN}/test6_wyswietlanie
	${TBIN}/test7_wczytywanie 
	${TBIN}/test8_sprzezenie
	${TBIN}/test9_modul
	${TBIN}/test10_WyrZsp
	${TBIN}/test11_statystyka
	${TBIN}/test12_wczytywanie_z_pliku
run:
	${TRGDIR}/test_arytm_zesp latwy

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/* ${TBIN}/* 
