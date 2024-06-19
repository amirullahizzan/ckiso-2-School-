#pragma once

// ----------------------------------------------------------
//	�J�����N���X
// ----------------------------------------------------------
class Camera
{
public:
	Camera();
	virtual ~Camera();

	void update();
	void render();

	// �J�������ǂ��^�[�Q�b�g�̐ݒ�
	//	������s��Ȃ��Ƌ����I������
	void setTargetPos(const pos* target_pos_address);

	// ���[���h���W����X�N���[�����W�ɕϊ�
	pos convertPosWorldToScreen(const pos& world_pos) const
	{
		return { world_pos.x - screen_pos_.x, world_pos.y - screen_pos_.y };
	}

private:
	const pos* target_pos_ptr_ = nullptr;

	pos pos_		= { 0, 0 };
	pos screen_pos_ = { 0, 0 };

};

