all: gtk-color-export

clean:
	rm -f gtk-color-export

gtk-color-export: gtk-color-export.c
	gcc `pkg-config --cflags gtk+-3.0` -o gtk-color-export gtk-color-export.c `pkg-config --libs gtk+-3.0`
