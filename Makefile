CC=g++
CFLAGS=-g -c -w
PKGCONFIGFLAG=`pkg-config --cflags --libs opencv`

default: camera chroma convert_to_images convert_to_video

camera: camera.o
	$(CC) camera.o -o camera $(PKGCONFIGFLAG)

camera.o: camera.cpp
	$(CC) $(CFLAGS) camera.cpp

chroma: chroma.o
	$(CC) chroma.o -o chroma $(PKGCONFIGFLAG)

chroma.o: chroma.cpp
	$(CC) $(CFLAGS) chroma.cpp

convert_to_images: convert_to_images.o
	$(CC) convert_to_images.o -o convert_to_images $(PKGCONFIGFLAG)

convert_to_images.o: convert_to_images.cpp
	$(CC) $(CFLAGS) convert_to_images.cpp

convert_to_video: convert_to_video.o
	$(CC) convert_to_video.o -o convert_to_video $(PKGCONFIGFLAG)

convert_to_video.o: convert_to_video.cpp
	$(CC) $(CFLAGS) convert_to_video.cpp

clean:
	rm *.o camera

clean:
	rm *.o chroma

clean :
	rm *.o convert_to_images

clean :
	rm *.o convert_to_video


