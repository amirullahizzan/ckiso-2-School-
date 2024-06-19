#pragma once
// ----------------------------------------------------------
//	�摜�N���X
// ----------------------------------------------------------
class Image
{
public:
	Image(const char* img_fname);
	virtual ~Image();

	void update() {}
	void render();
	void attachCamera(const Camera* camera);

private:
	const float BG_EX_RATE = 1.44f;

	img image_;	// �摜�֌W
	pos pos_;	// ���W�֌W

	const Camera* camera_ = nullptr;

};
