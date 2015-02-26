# /**************************************************
# * This Makefile write by GaoLei                   *
# * if you have any problems, you can chat with me! *
# * MY QQ:763727697                                 *
# * MY E-MAIL : gloxec@gmail.com                    *
# **************************************************/

####################################################
#just a test vesion
#History:
#2014/09/22 gloxec test release



CC = gcc
CFLAGS =  -g
CPPFLAGS = -I/usr/include/GS/ -lgsv

all: GS_Draw GS_DrawInit GS_Screeninfo

GS_Draw: ./GS_Draw.c 
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)
GS_DrawInit: ./GS_DrawInit.c 
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)
GS_Screeninfo: ./GS_Screeninfo.c 
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)
GS_image: ./GS_image.c
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS) -lgsv_image
GS_Line: ./GS_Line.c
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)
GS_rect: ./GS_rect.c
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)
GS_text: ./GS_text.c
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)
GS_Window: ./GS_Window.c
	$(CC) $(CFLAGS)  $^ -o $@ $(CPPFLAGS)

clean:
	@echo "[GSv MAKE] : cleaning project!"
	-rm ./GS*
	@echo "[GSv MAKE] : clean completed!"

.PHONY: clean
