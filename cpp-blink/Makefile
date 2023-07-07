PROJECT_NAME = stm32f070_nucleo64_test_1

BUILD_DIR = ./.build
SRC_DIR = ./src
INCLUDE_DIR = ./include
OUT_NAME = ${PROJECT_NAME}
DEBUG_FILE = debug.gdb
SOURCES = ${SRC_DIR}/main.cpp ${SRC_DIR}/startup_stm32f070rbtx.s
LD_SCRIPT = ${SRC_DIR}/STM32F070RBTX_FLASH.ld

C_COMPILER = arm-none-eabi-gcc
CPP_COMPILER = arm-none-eabi-g++
OBJCOPY_TOOL = arm-none-eabi-objcopy
GDB_TOOL = arm-none-eabi-gdb


all: prepare compile objcopy


build_burn: prepare compile objcopy burn


prepare:
	@mkdir ${BUILD_DIR} | true


compile: ${SOURCES} ${LD_SCRIPT}
	@${CPP_COMPILER} ${SOURCES} -T ${LD_SCRIPT} -I ${INCLUDE_DIR} -g -O2 -Wall -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m0 -fsingle-precision-constant -Wdouble-promotion --specs=nosys.specs -o ${BUILD_DIR}/${OUT_NAME}.elf


objcopy: ${BUILD_DIR}/${OUT_NAME}.elf
	@${OBJCOPY_TOOL} -O binary ${BUILD_DIR}/${OUT_NAME}.elf ${BUILD_DIR}/${OUT_NAME}.bin
	@echo "Well done..."
	@echo "Out file:" \"${BUILD_DIR}/${OUT_NAME}.bin\"


burn: ${BUILD_DIR}/${OUT_NAME}.bin
	@st-flash write ${BUILD_DIR}/${OUT_NAME}.bin 0x8000000


openocd_start:
	@openocd -f board/st_nucleo_f0.cfg


debug:
	@echo "target extended-remote :3333" > ${BUILD_DIR}/${DEBUG_FILE}
	@echo "file "${BUILD_DIR}/${OUT_NAME}.elf >> ${BUILD_DIR}/${DEBUG_FILE}
	@echo "break main" >> ${BUILD_DIR}/${DEBUG_FILE}
	@${GDB_TOOL} --command=${BUILD_DIR}/${DEBUG_FILE}


clean:
	@rm -rf ${BUILD_DIR}
