DEFAULT_FOLDER = orthrus_ble/master

NRF_DEBUG = no

NRF_MASTER_LOWMEM = no # use ble_master_lowmem.c instead of ble_master.c
NRF_DISABLE_TWI = yes # disables Two-Wire-Interface and TWI slave for i2c

MOUSEKEY_ENABLE = no	# Mouse keys
EXTRAKEY_ENABLE = no	# Audio control and System control
CONSOLE_ENABLE = no    # Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
NKRO_ENABLE = no	    # USB Nkey Rollover
CUSTOM_MATRIX = yes # This flag should be on for nrf52

BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration
UNICODE_ENABLE   = no
SLEEP_LED_ENABLE = no
API_SYSEX_ENABLE = no
RGBLIGHT_ENABLE = no
RGBLIGHT_ANIMATION = no

MCU_FAMILY = NRF51
MCU  = cortex-m0
ARMV = 6
