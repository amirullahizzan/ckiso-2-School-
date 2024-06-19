#pragma once
// ----------------------------------------------------------
//	‰æ‘œƒNƒ‰ƒX
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

	img image_;	// ‰æ‘œŠÖŒW
	pos pos_;	// À•WŠÖŒW

	const Camera* camera_ = nullptr;

};
