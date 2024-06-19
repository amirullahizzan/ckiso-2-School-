#include "WinMain.h"


namespace
{
	// ------------------------------
	//	定数
	// ------------------------------
	constexpr int MAP_X = (WINDOW_W / IMG_SIZE);	// 多次元配列の横のサイズ
	constexpr int MAP_Y = (WINDOW_H / IMG_SIZE);	// 多次元配列の縦のサイズ

	constexpr int MAX_MAP1_IMG_NUM = 18;		// マップ1のチップ画像のサイズ
	constexpr float MAP_START_Y = 10;		// マップ開始位置

	// ------------------------------
	//	変数
	// ------------------------------
	img img_bg;	// 背景画像
	const int TOTAL_IMG = 18;
	img imgPalette[TOTAL_IMG];	// 背景画像

	img img_map[MAX_MAP1_IMG_NUM]{ 0 };	// マップチップの画像
	int map[MAP_Y][MAP_X]{ 0 };			// マップ管理用の二次元配列

	// ------------------------------
	//	関数
	// ------------------------------
	/////////////////////////////////
	// プレイヤー関係
	/////////////////////////////////
	// マップ関係
	/////////////////////////////////
	// マップチップ画像の読み込み関数
	void loadMapChip(img* chip_imgs, int size, const char* map_name);
	// マップチップ画像の破棄関数
	void deleteMapChip(img* chip_imgs, int size);
	// マップ1の描画関数
	void map1Render(const img* chip_imgs, int size);
}

// =====================================================
//		初期化
// =====================================================
void GameInit()
{
	img_bg.ghandle = DxLib::LoadGraph("../data/map/map1/BG/BG01.png");

	scanf_s("../data/map/map1/Tiles/%d.png", i);
	sprintf();
	for (int i = 0; i < TOTAL_IMG; i++)
	{
		imgPalette[TOTAL_IMG].ghandle = DxLib::LoadGraph();
	}
}

// =====================================================
//		更新
// =====================================================
void GameUpdate()
{


}

// =====================================================
//		描画
// =====================================================
void GameDraw()
{
	//Find the first black gap

	//DxLib::DrawGraphF(, , img_bg, false);
	for (int i = 0; i < TOTAL_IMG; i++)
	{
		pos position = pos{ imgPalette[i].w * i , imgPalette[i].h * i };
		DxLib::DrawGraphF(position.x, position.y, imgPalette[i].ghandle, false);
	}

#ifndef NDEBUG
	// ------------------------------
	//	Debug用
	// ------------------------------
	// グリッドの描画
	for (int y = 0; y <= MAP_Y; ++y)
	{
		DrawLine(0, 0 + IMG_SIZE * y, WINDOW_W, 0 + IMG_SIZE * y, GetColor(255, 0, 0), 1);
	}
	for (int x = 1; x < MAP_X; ++x)
	{
		DrawLine(x * IMG_SIZE, 0, x * IMG_SIZE, WINDOW_H, GetColor(255, 0, 0), 1);
	}
#endif
}

// =====================================================
//		終了
// =====================================================
void GameExit()
{


}
