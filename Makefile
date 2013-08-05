# /**************************************************
# * This Makefile write by GaoLei                   *
# * if you have any problems, you can chat with me! *
# * MY QQ:763727697                                 *
# * MY E-MAIL : gloxec@gmail.com                    *
# **************************************************/




CC = gcc
CFLAGS =  -g -fPIC -shared
CPPFLAGS = -I./include/
prefix = /usr

all: libgsv.so

libgsf.so: gsfb.o gsfbdraw.o gsimage.o png.o
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $^


gsfb.o: ./src/output/gsfb.c 
	$(CC) -c -g $< $(CPPFLAGS)
gsfbdraw.o: ./src/output/gsfbdraw.c 
	$(CC) -c -g $< $(CPPFLAGS)
gsimage.o: ./src/gsimage.c ./src/image/png.c 
	$(CC) -c -g $< $(CPPFLAGS)
png.o: ./src/image/png.c 
	$(CC) -c -g $< $(CPPFLAGS)
#gsfont.o: ./src/font/gsfont.c ./src/font/gstext.c 
#	$(CC) -c $< $(CPPFLAGS)


install:
	@echo "GSv installing ..."
	-cp $(CPPFLAGS) $(prefix)/GS
	-cp ./libgsv.so $(prefix)/lib/
	@echo "[GS install] finished!"

uninstall:
	@echo "GSv unistall ..."
	-rm $(prefix)/lib/libgsf.so
	-rm -rf $(prefix)/GS
	@echo "[GSv unistall] finished!"


clean:
	@echo "[GSv MAKE] : cleaning project!"
	-rm libgsf.so 
	-rm *.o
	@echo "[GSv MAKE] : clean completed!"

.PHONY: clean
