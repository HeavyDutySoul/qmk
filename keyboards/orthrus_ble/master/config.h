#include "custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS { NO_PIN }
#define MATRIX_COL_PINS { 17, 13, 9,  4, 0, 29, \
		          18, 14, 10, 5, 1, 28, \
		          19, 15, 11, 6, 2, 25, \
		          20, 16, 12, 7, 3, 24, \
				      8,30, 23, 22 \
			}

#define IS_LEFT_HAND  true
