#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include "constants.h"

GsOT orderingTable[2];
short currentBuffer;
char drawText[100] = "";

int main() {
    init();

    while (1) {
        FntPrint("Hello World");
        drawScreen();
    }

    return 0;
}

void init() {
    initializeScreen();
    initializeDebugFont();
}

void drawScreen() {
    currentBuffer = GsGetActiveBuff();
    FntFlush(-1);
    GsClearOt(0, 0, &orderingTable[currentBuffer]);
    DrawSync(0);
    VSync(0);
    GsSwapDispBuff();
    GsSortClear(255, 0, 0, &orderingTable[currentBuffer]);
    GsDrawOt(&orderingTable[currentBuffer]);
}
