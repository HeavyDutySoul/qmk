#pragma once

#include "../../board/custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS {  }
#define MATRIX_COL_PINS { PIN23, PIN29, PIN0,  PIN5, PIN9, PIN13, \
                          PIN22, PIN28, PIN30, PIN4, PIN8, PIN14, \
                          PIN21, PIN25, PIN11, PIN3, PIN7, PIN15, \
                          PIN20, PIN24, PIN12, PIN2, PIN6, PIN16, \
                                               PIN1, PIN10,PIN17, PIN18 \
                        }

#define IS_LEFT_HAND  true

