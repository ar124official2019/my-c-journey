CC=gcc
S_OPTIONS=-fPIC
SRC_DIR="${PWD}/src"
BUILD_DIR="${PWD}/build"
OUT_DIR="${PWD}/lib"
INCLUDE="${PWD}/include" 

static: prepare comp_static
	if [ ! -d ${OUT_DIR} ]; then mkdir -p ${OUT_DIR}; fi
	cd ${OUT_DIR} && ar cr libmylib.a ${BUILD_DIR}/*.o

shared: prepare comp_shared
	cd ${OUT_DIR} && ar cr libmylib.so ${BUILD_DIR}/*.o

comp_static:
	cd ${BUILD_DIR} && $(CC) -c ${SRC_DIR}/* -I ${INCLUDE}

comp_shared:
	cd ${BUILD_DIR} && $(CC) -c ${S_OPTIONS} ${SRC_DIR}/* -I ${INCLUDE}

prepare: mkdir clean

mkdir:
	if [ ! -d ${BUILD_DIR} ]; then mkdir -p ${BUILD_DIR}; fi
	if [ ! -d ${OUT_DIR} ]; then mkdir -p ${OUT_DIR}; fi

clean:
	cd ${BUILD_DIR} && rm -rf *.o