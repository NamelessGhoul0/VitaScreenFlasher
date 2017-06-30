#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

#define EXIT_COMBO (SCE_CTRL_START | SCE_CTRL_SELECT)

#define BLACK   RGBA8(  0,   0,   0, 255)
#define RED     RGBA8(255,   0,   0, 255)
#define ORANGE  RGBA8(255, 165,   0, 255)
#define YELLOW  RGBA8(255, 255,   0, 255)
#define GREEN   RGBA8(  0, 255,   0, 255)
#define CYAN    RGBA8(  0, 255, 255, 255)
#define BLUE    RGBA8(  0,   0, 255, 255)
#define PURPLE  RGBA8(128,   0, 128, 255)

extern unsigned char warning_image[];

int main()
{
    vita2d_init();
	vita2d_set_clear_color(BLACK);

    vita2d_start_drawing();
    vita2d_clear_screen();
    vita2d_texture *warning = vita2d_load_PNG_buffer(warning_image);
    vita2d_draw_texture(warning, 0, 0);
    vita2d_end_drawing();
    vita2d_swap_buffers();

    sceKernelDelayThread(10 * 1000 * 1000); // Delay 10 seconds

    SceCtrlData pad;

    while(1) {
		sceKernelPowerTick(0);

        sceCtrlPeekBufferPositive(0, &pad, 1);

        if (pad.buttons == EXIT_COMBO) { break; }

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, RED);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, ORANGE);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, YELLOW);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, GREEN);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, CYAN);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, BLUE);
        vita2d_end_drawing();
        vita2d_swap_buffers();

        vita2d_start_drawing();
        vita2d_clear_screen();
        vita2d_draw_rectangle(0, 0, 960, 544, PURPLE);
        vita2d_end_drawing();
        vita2d_swap_buffers();
    }

    vita2d_fini();
    vita2d_free_texture(warning);

	sceKernelExitProcess(0);

    return 0;
}
