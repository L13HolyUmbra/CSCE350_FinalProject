GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

RD = ReadData.o
K = KNearest.o
A = Main.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $(A) $(S) $(SL) $(U) $(K) $(RD)
	$(GPP) -o Aprog $(A) $(S) $(SL) $(U) $(K) $(RD)

Main.o: Main.h Main.cpp
	$(GPP) -c Main.cpp

ReadData.o: ReadData.h ReadData.cpp
	$(GPP) -c ReadData.cpp

KNearest.o: KNearest.h KNearest.cpp
	$(GPP) -c KNearest.cpp 

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -c $(UTILS)/Scanner.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -c $(UTILS)/ScanLine.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -c $(UTILS)/Utils.cpp

