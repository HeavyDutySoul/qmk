
# it should exist either in <this_dir>/ld/
MCU_LDSCRIPT = nrf51822_slave
MCU_SERIES = NRF51822
NRFSDK_ROOT := ./NRF5_SDK

# project specific files
#SRC =	matrix.c
NRF_SEPARATE = slave

#NRFCFLAGS += -DNRF_LOG_BACKEND_SERIAL_UART_TX_PIN=21
