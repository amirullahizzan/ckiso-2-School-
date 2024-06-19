#include "WinMain.h"
#include "Camera.h"
#include "Image.h"
#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>

namespace
{
	// ------------------------------
	//	�萔
	// ------------------------------
	constexpr int MAP_X = (FIELD_W / IMG_SIZE);	// �������z��̉��̃T�C�Y
	constexpr int MAP_Y = (FIELD_H / IMG_SIZE);	// �������z��̏c�̃T�C�Y

	constexpr int MAX_MAP1_IMG_NUM = 18;		// �}�b�v1�̃`�b�v�摜�̃T�C�Y
	constexpr float MAP_START_Y = 10;		// �}�b�v�J�n�ʒu

	// ------------------------------
	//	�ϐ�
	// ------------------------------
	Image* img_bg = nullptr;	// �w�i�摜
	Camera camera;				// �J����
	pos	   pos_player;			// �v���C���[�̍��W(���E�Ɉړ��̂�)

	img img_map[MAX_MAP1_IMG_NUM]{ 0 };	// �}�b�v�`�b�v�̉摜
	int map[MAP_Y][MAP_X]{ 0 };			// �}�b�v�Ǘ��p�̓񎟌��z��

	// ------------------------------
	//	�֐�
	// ------------------------------
	/////////////////////////////////
	// �v���C���[�֌W
	/////////////////////////////////
	void playerInit();
	void playerUpdate();
	void playerRender();
	void playerExit();
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
	playerInit();

	camera.setTargetPos(&pos_player);

	loadMapChip(img_map, MAX_MAP1_IMG_NUM, "map1");

	img_bg = new Image("../data/map/map1/BG/BG01.png");
	img_bg->attachCamera(&camera);


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//	�������z��umap�v�Ƀt�@�C������ǂݍ��񂾃f�[�^��
	//	������邱�ƂŃ}�b�v���`�悳���
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	std::vector<std::string> fileLines;
	/////////////////////////////////////////////////
	//FILE MANAGER
	{
		std::ifstream ifile;
		ifile.open("../data/csv/map1.csv");
		if (ifile.is_open())
		{
			std::string line;

			while (getline(ifile, line))
			{
				fileLines.push_back(line);
			}
		}
		else
		{
			assert(false && "Failed to open file");
		}
		ifile.close();
	}

	/////////////////////////////////////////////////
	//FIT DATA TO MAP SIZE

	/////////////////////////////////////////////////
	//TAKE DATA TO ACTUAL MAP
	std::vector<std::string> mapData;

	int h = 0;
	for (const auto& fileLine : fileLines)
	{
		if (h >= MAP_Y) break;
		std::istringstream ss(fileLine);
		std::string filtered;
		int w = 0;
		while (std::getline(ss, filtered, ',') && w < MAP_X)
		{
			map[h][w] = std::stoi(filtered);
			w++;
		}
		h++;
	}

}

// =====================================================
//		�X�V
// =====================================================
void GameUpdate()
{
	playerUpdate();

	img_bg->update();

	camera.update();
}

// =====================================================
//		�`��
// =====================================================
void GameDraw()
{
	img_bg->render();

	map1Render(img_map, MAX_MAP1_IMG_NUM);

	playerRender();

#ifndef NDEBUG
	// ------------------------------
	//	Debug�p
	// ------------------------------
	// �J�����̕`��̈�̕`��
	camera.render();
	// �O���b�h�̕`��
	for (int y = 0; y <= MAP_Y; ++y)
	{
		DrawLine(0, 10 + IMG_SIZE * y, WINDOW_W, 10 + IMG_SIZE * y, GetColor(255, 0, 0), 1);
	}
	for (int x = 1; x < MAP_X; ++x)
	{
		DrawLine(x * IMG_SIZE, 10, x * IMG_SIZE, WINDOW_H, GetColor(255, 0, 0), 1);
	}
#endif

}

// =====================================================
//		�I��
// =====================================================
void GameExit()
{
	playerExit();

	deleteMapChip(img_map, MAX_MAP1_IMG_NUM);

	delete img_bg;
	img_bg = nullptr;
}

namespace
{
	/////////////////////////////////
	// �v���C���[�֌W
	/////////////////////////////////
	void playerInit()
	{
		pos_player = { 100, WINDOW_H - 100 };
	}
	void playerUpdate()
	{
		if (IsKeyRepeat(KEY_INPUT_RIGHT))
		{
			pos_player.x += 4;
		}
		if (IsKeyRepeat(KEY_INPUT_LEFT))
		{
			pos_player.x -= 4;
		}
	}
	void playerRender()
	{
		pos conv_player_pos = camera.convertPosWorldToScreen({ pos_player.x, pos_player.y });
		DrawCircleAA(conv_player_pos.x, conv_player_pos.y, 10, 64, GetColor(255, 125, 0), TRUE);
	}
	void playerExit()
	{

	}
	/////////////////////////////////
	// �}�b�v�֌W
	/////////////////////////////////
	// �}�b�v�`�b�v�ǂݍ��݊֐�
	// �߂�l: �Ȃ�
	// ����1: �}�b�v�`�b�v�p�̉摜�z��
	// ����2: �}�b�v�`�b�v�p�̉摜�z��̃T�C�Y
	// ����3: �}�b�v�̃f�[�^�������Ă���t�H���_��
	void loadMapChip(img* chip_imgs, int size, const char* map_name)
	{
		for (int i = 0; i < size; ++i)
		{
			char fname[64];
			sprintfDx(fname, "../data/map/%s/Tiles/%d.png", map_name, (i + 1));
			chip_imgs[i].ghandle = LoadGraph(fname);
			GetGraphSizeF(chip_imgs[i].ghandle, &chip_imgs[i].w, &chip_imgs[i].h);
		}
	}
	// �}�b�v�`�b�v�摜�̔j���֐�
	// �߂�l: �Ȃ�
	// ����1: �}�b�v�`�b�v�p�̉摜�z��
	// ����2: �}�b�v�`�b�v�p�̉摜�z��̃T�C�Y
	void deleteMapChip(img* chip_imgs, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			DeleteGraph(chip_imgs[i].ghandle);
		}
	}
	// �}�b�v1�̕`��֐�
	// �߂�l: �Ȃ�
	// ����1: �}�b�v�`�b�v�p�̉摜�z��
	// ����2: �}�b�v�`�b�v�p�̉摜�z��̃T�C�Y
	void map1Render(const img* chip_imgs, int size)
	{
		for (int y = 0; y < MAP_Y; ++y)
		{
			for (int x = 0; x < MAP_X; ++x)
			{
				int index = map[y][x] - 1;
				if (index < 0)
					continue;
				if (index >= size)
					index = 0;

				pos conv_map_pos = camera.convertPosWorldToScreen({ (float)(IMG_SIZE / 2 + x * IMG_SIZE), (float)(MAP_START_Y + IMG_SIZE / 2 + y * IMG_SIZE) });
				DrawRotaGraphF(conv_map_pos.x, conv_map_pos.y, 1, 0, chip_imgs[index].ghandle, TRUE);
			}
		}

	}

}