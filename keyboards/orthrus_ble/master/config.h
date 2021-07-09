#include "custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS { NO_PIN }
#define MATRIX_COL_PINS { 23, 29, 0,  5, 9, 13, \
		          22, 28, 30, 4, 8, 14, \
		          21, 25, 11, 3, 7, 15, \
		          20, 24, 12, 2, 6, 16, \
				      1,10, 17, 18 \
			}

#define IS_LEFT_HAND  true

