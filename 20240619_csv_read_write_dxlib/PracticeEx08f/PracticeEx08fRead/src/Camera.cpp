#include "WinMain.h"
#include "../src/Common.h"
#include "Camera.h"
#include <cassert>

// ----------------------------------------------------------
//	カメラクラス
// ----------------------------------------------------------
Camera::Camera()
{
	pos_ = { WINDOW_W, WINDOW_H };
	screen_pos_ = { pos_.x - WINDOW_W / 2, pos_.y - WINDOW_H / 2 };
}

Camera::~Camera()
{

}

void Camera::setTargetPos(const pos* target_pos_address)
{
	target_pos_ptr_ = target_pos_address;
}

void Camera::update()
{
	assert(target_pos_ptr_ != nullptr);

	pos_ = { target_pos_ptr_->x, target_pos_ptr_->y };

	// カメラをはみ出させない
	if (pos_.x - WINDOW_W / 2 <= 0.0f)
	{
		pos_.x = WINDOW_W / 2;
	}
	else if (pos_.x + WINDOW_W / 2 >= FIELD_W)
	{
		pos_.x = FIELD_W - WINDOW_W / 2;
	}

	if (pos_.y - WINDOW_H / 2 <= 0.0f)
	{
		pos_.y = WINDOW_H / 2;
	}
	else if (pos_.y + WINDOW_H / 2 >= FIELD_H)
	{
		pos_.y = FIELD_H - WINDOW_H / 2;
	}

	screen_pos_ = { pos_.x - WINDOW_W / 2, pos_.y - WINDOW_H / 2 };
}

void Camera::render()
{
#ifndef NDEBUG
	pos conv_pos = convertPosWorldToScreen(screen_pos_);
	DrawBoxAA(conv_pos.x, conv_pos.y,
			  conv_pos.x + WINDOW_W, conv_pos.y + WINDOW_H,
			  RED, FALSE);

	printfDx("target_pos: %.2f, %.2f\n", target_pos_ptr_->x, target_pos_ptr_->y);
#endif

}

