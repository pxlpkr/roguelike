INCLUDE_FILES = -I lib/SDL/include
SOURCE_FILES = bin/src/main.o bin/src/buffer.o bin/src/renderer.o bin/src/state.o bin/src/window.o

LIB_LINKS = -lm
LIB_LINKS += $(shell bin/sdl/sdl2-config --prefix=bin --static-libs)

default: all

all: build clean

clean:
	-rm -rf bin/src

mkbin:
	mkdir -p bin/src

bin/src/%.o: src/%.c mkbin
	cc -o $@ -c $(INCLUDE_FILES) -O2 $<

build: $(SOURCE_FILES)
	cc -o bin/app $(SOURCE_FILES) $(LIB_LINKS) -O2

run: build
	bin/app

sdl:
	mkdir -p bin/sdl
	cmake -S lib/SDL -B bin/sdl
	cd bin/sdl && make -j 10
	chmod +x bin/sdl/sdl2-config
	mkdir -p bin/lib
	cp bin/sdl/libSDL2.a bin/lib