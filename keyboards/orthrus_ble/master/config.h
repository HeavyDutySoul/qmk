#pragma once

#include "custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS {  }
#define MATRIX_COL_PINS { PIN17, PIN13, PIN9, PIN4, PIN0, PIN29, \
                          PIN18, PIN14, PIN10,PIN5, PIN1, PIN28, \
                          PIN19, PIN15, PIN11,PIN6, PIN2, PIN25, \
                          PIN20, PIN16, PIN12,PIN7, PIN3, PIN24, \
                                              PIN8, PIN30,PIN23, PIN22 \
                        }

#define IS_LEFT_HAND  true
