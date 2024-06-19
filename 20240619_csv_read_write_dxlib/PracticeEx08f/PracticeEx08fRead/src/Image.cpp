#include "WinMain.h"
#include "../src/Common.h"
#include "Camera.h"
#include "Image.h"
#include <cassert>

// ----------------------------------------------------------
//	画像クラス
// ----------------------------------------------------------
Image::Image(const char* img_fname)
{
	image_.ghandle = LoadGraph(img_fname);
	GetGraphSizeF(image_.ghandle, &image_.w, &image_.h);
	image_.w *= BG_EX_RATE;
	image_.h *= BG_EX_RATE;

	pos_ = { image_.w / 2, image_.h / 2 };
}

Image::~Image()
{
	DeleteGraph(image_.ghandle);
}

void Image::render()
{
	assert(camera_ != nullptr);
	assert(image_.ghandle != -1);

	// 現在の座標をスクリーン座標に変換して描画する
	pos conv_bg_pos = camera_->convertPosWorldToScreen({ pos_.x, pos_.y });
	DrawRotaGraphF(conv_bg_pos.x, conv_bg_pos.y, (double)BG_EX_RATE, 0, image_.ghandle, FALSE);

}

void Image::attachCamera(const Camera* camera)
{
	camera_ = camera;
}
