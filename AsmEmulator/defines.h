#ifndef PROGRAM_SPESIFICS

#define PROGRAM_SIZE (1 << 16)
#define MEMORY_SIZE  (1 << 16)

//Instructions
#define ALU     1
#define LOAD    (1 << 1)
#define STORE   (1 << 2)
#define JUMP    (1 << 3)
#define CALL    (1 << 4)
#define BRANCH  (1 << 5)
#define RET     (1 << 6)

#define HI_BIT  (1 << 7)

//Branch types
#define BLT     1
#define BLE     (1 << 1)
#define BEQ     (1 << 2)
#define BNE     (1 << 3)
#define BGT     (1 << 4)
#define BGE     (1 << 5)

//Special register indecies
#define RV  127
#define SP  126
#define PC  125
#define JM  124

//Screen
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 16
#define SCREEN_START 0

#endif