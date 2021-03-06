#compiler
CC=g++

CFLAGS= -c -Wall
COPENCV= `pkg-config --cflags opencv`
CLIBRAW= `pkg-config --cflags libraw_r`

LIBOPENCV= `pkg-config --libs opencv`
LIBLIBRAW= `pkg-config --libs libraw_r`

developSOURCE=rawdevelop.cpp
developTARGET=rawdevelop.o

wbSOURCE=whiteBalanceTiffs.cpp
wbTARGET=whiteBalanceTiffs.o

stackSOURCE=exposureStack.cpp
stackTARGET=exposureStack.o

eqSOURCE=eqHisto.cpp
eqTARGET=eqHisto.o

denoiseSOURCE=noiseReduction.cpp
denoiseTARGET=noiseReduction.o

devTestSOURCE=developMethodTesting.cpp
devTestTARGET=developMethodTesting.o

blurSOURCE=blurDetection.cpp
blurTARGET=blurDetection.o

all: develop balance stack eq denoise devtest blur

develop:
	$(CC) $(CLIBRAW) $(developSOURCE) $(LIBLIBRAW) -o $(developTARGET)

balance:
	$(CC) $(COPENCV) $(wbSOURCE) $(LIBOPENCV) -o $(wbTARGET)

stack:
	$(CC) $(COPENCV) $(stackSOURCE) $(LIBOPENCV) -o $(stackTARGET) 

eq:
	$(CC) $(COPENCV) $(eqSOURCE) $(LIBOPENCV) -o $(eqTARGET)

denoise:
	$(CC) $(COPENCV) $(denoiseSOURCE) $(LIBOPENCV) -o $(denoiseTARGET)

devtest:
	$(CC) $(CLIBRAW) $(devTestSOURCE) $(LIBLIBRAW) -o $(devTestTARGET)

blur:
	$(CC) $(COPENCV) $(blurSOURCE) $(LIBOPENCV) -o $(blurTARGET)
