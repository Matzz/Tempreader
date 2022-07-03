# Automatically generated file. Do not edit.

APP_NAME=app
COM_OPTS=--raw --encoding ascii --rts 0 --dtr 0
COM_PORT=/dev/ttyUSB0
COM_SPEED=115200
COM_SPEED_SERIAL=$(COM_SPEED)
DEBUG_PRINT_FILENAME_AND_LINE=0
DEBUG_VERBOSE_LEVEL=2
DISABLE_NETWORK=1
DISABLE_WIFI=1
ENABLE_CMD_EXECUTOR=1
ENABLE_GDB=
ENABLE_HOST_UARTID=
ENABLE_MALLOC_COUNT=1
ENABLE_SPI_DEBUG=0
ENABLE_TASK_COUNT=
FLASH_BIN=$(FW_BASE)/flash.bin
FSBUILD_OPTIONS=
FULL_COMPONENT_BUILD=
FWFS_DEBUG=0
GDB_CMDLINE=trap  INT; $(GDB) -x $(GDBSTUB_DIR)/gdbcmds --args $(TARGET_OUT_0) $(CLI_TARGET_OPTIONS) --pause -- $(HOST_PARAMETERS)
HOST_FLASH_OPTIONS=--flashfile=$(FLASH_BIN) --flashsize=$(SPI_SIZE)
HOST_PARAMETERS=
HOST_UART_OPTIONS=$(addprefix --uart=,$(ENABLE_HOST_UARTID))
HOST_UART_PORTBASE=10000
HWCONFIG=standard
HWCONFIG_OPTS=
KILL_TERM=pkill -9 -f "$(COM_PORT) $(COM_SPEED_SERIAL)" || exit 0
LOCALE=
PARTITION_TABLE_OFFSET=0x00002000
PIP_ARGS=
RBOOT_GPIO_ENABLED=0
RBOOT_GPIO_SKIP_ENABLED=0
RBOOT_LD_TEMPLATE=$(RBOOT_DIR)/rboot.rom0.ld
RBOOT_ROM_0=rom0
RBOOT_ROM_1=rom1
RBOOT_RTC_ENABLED=0
RBOOT_SILENT=0
SERVER_OTA_PORT=9999
SPIFFS_OBJ_META_LEN=16
SPIFF_BIN=spiff_rom
SPIFF_FILEDESC_COUNT=7
SPIFF_FILES=files
SPISOFT_DELAY_FIXED=0
SPISOFT_DELAY_VARIABLE=0
STRING_OBJECT_SIZE=12
TASK_QUEUE_LENGTH=10
TERMINAL=$(PYTHON) -m serial.tools.miniterm $(COM_OPTS) $(COM_PORT) $(COM_SPEED_SERIAL)
TRACE=
USER_CFLAGS=
USE_US_TIMER=1

CACHED_VAR_NAMES := APP_NAME COM_OPTS COM_PORT COM_SPEED COM_SPEED_SERIAL DEBUG_PRINT_FILENAME_AND_LINE DEBUG_VERBOSE_LEVEL DISABLE_NETWORK DISABLE_WIFI ENABLE_CMD_EXECUTOR ENABLE_GDB ENABLE_HOST_UARTID ENABLE_MALLOC_COUNT ENABLE_SPI_DEBUG ENABLE_TASK_COUNT FLASH_BIN FSBUILD_OPTIONS FULL_COMPONENT_BUILD FWFS_DEBUG GDB_CMDLINE HOST_FLASH_OPTIONS HOST_PARAMETERS HOST_UART_OPTIONS HOST_UART_PORTBASE HWCONFIG HWCONFIG_OPTS KILL_TERM LOCALE PARTITION_TABLE_OFFSET PIP_ARGS RBOOT_GPIO_ENABLED RBOOT_GPIO_SKIP_ENABLED RBOOT_LD_TEMPLATE RBOOT_ROM_0 RBOOT_ROM_1 RBOOT_RTC_ENABLED RBOOT_SILENT SERVER_OTA_PORT SPIFFS_OBJ_META_LEN SPIFF_BIN SPIFF_FILEDESC_COUNT SPIFF_FILES SPISOFT_DELAY_FIXED SPISOFT_DELAY_VARIABLE STRING_OBJECT_SIZE TASK_QUEUE_LENGTH TERMINAL TRACE USER_CFLAGS USE_US_TIMER