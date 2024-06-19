#pragma once

// ----------------------------------------------------------
//	カメラクラス
// ----------------------------------------------------------
class Camera
{
public:
	Camera();
	virtual ~Camera();

	void update();
	void render();

	// カメラが追うターゲットの設定
	//	これを行わないと強制終了する
	void setTargetPos(const pos* target_pos_address);

	// ワールド座標からスクリーン座標に変換
	pos convertPosWorldToScreen(const pos& world_pos) const
	{
		return { world_pos.x - screen_pos_.x, world_pos.y - screen_pos_.y };
	}

private:
	const pos* target_pos_ptr_ = nullptr;

	pos pos_		= { 0, 0 };
	pos screen_pos_ = { 0, 0 };

};

