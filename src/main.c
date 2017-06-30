#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

#define EXIT_COMBO (SCE_CTRL_START | SCE_CTRL_SELECT)

#define BLACK   RGBA8(  0,   0,   0, 255)
#define WHITE   RGBA8(255, 255, 255, 255)
#define RED     RGBA8(255,   0,   0, 255)
#define ORANGE  RGBA8(255, 165,   0, 255)
#define YELLOW  RGBA8(255, 255,   0, 255)
#define GREEN   RGBA8(  0, 255,   0, 255)
#define CYAN    RGBA8(  0, 255, 255, 255)
#define BLUE    RGBA8(  0,   0, 255, 255)
#define PURPLE  RGBA8(128,   0, 128, 255)

SceCtrlData pad;

int display_warning() {
	vita2d_pgf *pgf;
	pgf = vita2d_load_default_pgf();

	while (1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);

		vita2d_start_drawing();
		vita2d_clear_screen();

		vita2d_pgf_draw_text(pgf, 30, 30, RED, 1.0f, "WARNING: This application flashes colors in an attempt to fix dead pixels");
		vita2d_pgf_draw_text(pgf, 30, 30+30, RED, 1.0f, "If you suffer from photosensitive epilepsy, please look away.");
		vita2d_pgf_draw_text(pgf, 30, 30+30+30, WHITE, 1.0f, "Press X to continue.");
		vita2d_end_drawing();
		vita2d_swap_buffers();

		if (pad.buttons == SCE_CTRL_CROSS) {
			sceKernelDelayThread(3000000); // Delay for 3 seconds
			vita2d_free_pgf(pgf);
			break;
		}
	}

	return 0;
}

int main() {
	vita2d_init();

	display_warning();

	while(1) {
		sceKernelPowerTick(0); // prevent screen from dimming

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

	sceKernelExitProcess(0);
	
	return 0;
}
