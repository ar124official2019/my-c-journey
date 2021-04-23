CC=gcc
SRC_DIR="${PWD}/src"
BUILD_DIR="${PWD}/build"
OUT_DIR="${PWD}/dist"
INCLUDE=${PWD}/../my-lib/include
LIB=${PWD}/../my-lib/lib
STATIC_OPTS=-static
OPTS=-L${LIB} -lmylib


static: prepare comp
	cd ${OUT_DIR} && gcc -o temp-files ${BUILD_DIR}/*.o ${STATIC_OPTS} ${OPTS}

shared: prepare comp
	cd ${OUT_DIR} && gcc -o temp-files ${BUILD_DIR}/*.o ${OPTS}

comp:
	cd ${BUILD_DIR} && $(CC) -c ${SRC_DIR}/* -I ${INCLUDE}

prepare: mkdir clean

mkdir: 
	if [ ! -d ${OUT_DIR} ]; then mkdir -p ${OUT_DIR}; fi
	if [ ! -d ${BUILD_DIR} ]; then mkdir -p ${BUILD_DIR}; fi

clean:
	cd ${BUILD_DIR} && rm -rf *.o