#pragma once

#include "../../board/custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define MATRIX_ROW_PINS {  }
#define MATRIX_COL_PINS { PIN29, PIN0,  PIN4, PIN9,  PIN13, PIN17, \
                          PIN28, PIN1,  PIN5, PIN10, PIN14, PIN18, \
                          PIN25, PIN2,  PIN6, PIN11, PIN15, PIN19, \
                          PIN24, PIN3,  PIN7, PIN12, PIN16, PIN20, \
                   PIN22, PIN23, PIN30, PIN8 \
                        }

#define IS_LEFT_HAND  false
