#include "WinMain.h"
#include <ctime>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("Map Make");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ---------------
	// ‰Šú‰»ˆ—
	// ---------------
	SRand((int)time(NULL));
	InputKeyInit();
	InputPadInit();
	InputMouseInit();
	GameInit();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		clsDx();
		// ---------------
		// XVˆ—
		// ---------------
		InputKeyUpdate();
		InputPadUpdate();
		InputMouseUpdate();
		GameUpdate();

		// ---------------
		// •`‰æˆ—
		// ---------------
		GameDraw();
		ScreenFlip();
	}

	// ---------------
	// I—¹ˆ—
	// ---------------
	InputKeyExit();
	InputPadExit();
	InputMouseExit();
	GameExit();

	DxLib_End();

	return 0;
}
