#ifndef BOARD_IO_H
#define BOARD_IO_H

#define RED (BYTE_BIT_1)
#define BLUE (BYTE_BIT_2)
#define GREEN (BYTE_BIT_3)

//note: they are not bundled into a single function because Unicorn OS tasks currently can't be parameterized
void blinkRed();
void blinkBlue();
void blinkGreen();

#endif //BOARD_IO_H