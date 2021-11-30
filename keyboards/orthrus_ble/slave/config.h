#pragma once

#include "custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define MATRIX_ROW_PINS { NO_PIN }
#define MATRIX_COL_PINS { PIN13, PIN9, PIN5, PIN0,  PIN29, PIN23, \
                          PIN14, PIN8, PIN4, PIN30, PIN28, PIN22, \
                          PIN15, PIN7, PIN3, PIN11, PIN25, PIN21, \
                          PIN16, PIN6, PIN2, PIN12, PIN24, PIN20, \
                   PIN18, PIN17, PIN10,PIN1 \
                        }

#define IS_LEFT_HAND  false

