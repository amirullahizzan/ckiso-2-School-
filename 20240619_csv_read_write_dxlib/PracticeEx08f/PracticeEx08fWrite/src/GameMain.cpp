#include "WinMain.h"


namespace
{
	// ------------------------------
	//	�萔
	// ------------------------------
	constexpr int MAP_X = (WINDOW_W / IMG_SIZE);	// �������z��̉��̃T�C�Y
	constexpr int MAP_Y = (WINDOW_H / IMG_SIZE);	// �������z��̏c�̃T�C�Y

	constexpr int MAX_MAP1_IMG_NUM = 18;		// �}�b�v1�̃`�b�v�摜�̃T�C�Y
	constexpr float MAP_START_Y = 10;		// �}�b�v�J�n�ʒu

	// ------------------------------
	//	�ϐ�
	// ------------------------------
	img img_bg;	// �w�i�摜
	const int TOTAL_IMG = 18;
	img imgPalette[TOTAL_IMG];	// �w�i�摜

	img img_map[MAX_MAP1_IMG_NUM]{ 0 };	// �}�b�v�`�b�v�̉摜
	int map[MAP_Y][MAP_X]{ 0 };			// �}�b�v�Ǘ��p�̓񎟌��z��

	// ------------------------------
	//	�֐�
	// ------------------------------
	/////////////////////////////////
	// �v���C���[�֌W
	/////////////////////////////////
	// �}�b�v�֌W
	/////////////////////////////////
	// �}�b�v�`�b�v�摜�̓ǂݍ��݊֐�
	void loadMapChip(img* chip_imgs, int size, const char* map_name);
	// �}�b�v�`�b�v�摜�̔j���֐�
	void deleteMapChip(img* chip_imgs, int size);
	// �}�b�v1�̕`��֐�
	void map1Render(const img* chip_imgs, int size);
}

// =====================================================
//		������
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
//		�X�V
// =====================================================
void GameUpdate()
{


}

// =====================================================
//		�`��
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
	//	Debug�p
	// ------------------------------
	// �O���b�h�̕`��
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
//		�I��
// =====================================================
void GameExit()
{


}
