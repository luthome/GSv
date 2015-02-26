# /**************************************************
# * This Makefile write by GaoLei               									    *
# * if you have any problems, you can chat with me!		  		    *
# * MY QQ:763727697                             											    *
# * MY E-MAIL : gloxec@gmail.com                 								    *
# **************************************************/

####################################################
#just a test vesion
#History:
#2014/12/27 gloxec second release



CC = gcc
CFLAGS =  -g -fPIC -shared
CPPFLAGS = -I./include/
prefix = /usr

all:libgsv.so libgsv_image.so


libgsv.so: gsfb.o gsfbdraw.o gstools.o gsfont.o gswindow.o font_8x8.o font_8x16.o
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $^
libgsv_image.so: gsimage.o png.o image_mixer.o
	$(CC) $(CFLAGS) -lgsv -lpng $(OUTPUT_OPTION) $^


gsfb.o: ./src/kernel/gsfb.c 
	$(CC) -c -g $< $(CPPFLAGS)
gsfbdraw.o: ./src/kernel/gsfbdraw.c 
	$(CC) -c -g $< $(CPPFLAGS)
gstools.o: ./src/tools/gstools.c
	$(CC) -c -g $< $(CPPFLAGS)
gsimage.o: ./src/image/gsimage.c ./src/image/png.c 
#gsimage.o: ./src/image/gsimage.c 
	$(CC) -c -g $< $(CPPFLAGS)
png.o: ./src/image/png.c 
	$(CC) -c -g $< $(CPPFLAGS)
image_mixer.o: ./src/image/image_mixer.c
	$(CC) -c -g $< $(CPPFLAGS)
gsfont.o: ./src/font/gsfont.c 
	$(CC) -c -g $< $(CPPFLAGS)
font_8x8.o: ./src/font/font_8x8.c
	$(CC) -c -g $< $(CPPFLAGS)
font_8x16.o: ./src/font/font_8x16.c
	$(CC) -c -g $< $(CPPFLAGS)
gswindow.o: ./src/application/gswindow.c
	$(CC) -c -g $< $(CPPFLAGS)


install:
	@echo "GSv installing ..."
	-mkdir /usr/include/GS
	-cp -fr ./include/* $(prefix)/include/GS/
	-cp ./libgsv.so ./libgsv_image.so $(prefix)/lib/
	@echo "[GS install] finished!"

uninstall:
	@echo "GSv unistall ..."
	-rm $(prefix)/lib/libgsv.so
	-rm -rf $(prefix)/include/GS
	@echo "[GSv unistall] finished!"


clean:
	@echo "[GSv MAKE] : cleaning project!"
	-rm libgsv.so 
	-rm *.o
	@echo "[GSv MAKE] : clean completed!"

.PHONY: clean
