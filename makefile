FLTK_HEADERS = "C:\Program Files\fltk-1.3.5" #izmeniti putanju prema Vasoj lokaciji FLTK biblioteke
FLTK_LIBS = "C:\Program Files\fltk-1.3.5\lib" #izmeniti putanju prema Vasoj lokaciji FLTK biblioteke
LINK = -mwindows -lfltk -lole32 -luuid -lcomctl32
OUTPUT = program

all: build run
build:
	g++ *.cpp model/*.cpp gui/*.cpp kolekcije/*.cpp servisi/*.cpp -I$(FLTK_HEADERS) -L$(FLTK_LIBS) $(LINK) -o $(OUTPUT).exe
build-debug:
	g++ -g *.cpp model/*.cpp gui/*.cpp kolekcije/*.cpp servisi/*.cpp -I$(FLTK_HEADERS) -L$(FLTK_LIBS) $(LINK) -o $(OUTPUT).exe
run:
	$(OUTPUT).exe