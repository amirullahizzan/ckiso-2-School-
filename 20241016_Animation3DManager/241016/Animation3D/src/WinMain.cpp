#include "DxLib.h"
#include <string>
#include <vector>


static constexpr int WINDOW_W = 1280;
static constexpr int WINDOW_H = 720;



struct Animation
{
	Animation(std::string _name, std::string _path, int _animIndex, const int& _modelHandler)
	{
		modelHandler = _modelHandler;
		animSrcHandler = MV1LoadModel(_path.c_str());
		name = _name;
		animIndex = _animIndex;
	}

	void SetPlayAnim()
	{
		isPlaying = true;

		printf("%f\n", animFrame);
	}

	float animFrame = 0;
	float animTotalFrame = 0;
	int modelHandler = -1;
	int animAttachIndex = 0;
	bool isPlaying = false;
	std::string name = "";
	float animIndex = 0;
	int animSrcHandler = -1;
private:
	std::string playingAnimName = "";
	bool isPlaySame = false;


};

struct AnimationSystem
{
	std::vector<Animation> animations;
	Animation* currentAnim = nullptr;

	void LoadAnim(const Animation _animation)
	{
		animations.emplace_back(_animation);
	}

	void PlayAnim(std::string _animationName)
	{
		if (_animationName == playingAnimName) return;

		int index = 0;
		auto it = std::find_if(animations.begin(), animations.end(), [&](const Animation& _anim)
			{
				return _anim.name == _animationName;
			}
		);

		index = std::distance(animations.begin(), it);
		currentAnim = &animations[index];

		if (currentAnim)
		{
		MV1DetachAnim(currentAnim->modelHandler, currentAnim->animAttachIndex);
		}
		currentAnim->animAttachIndex = MV1AttachAnim(currentAnim->modelHandler, currentAnim->animIndex, currentAnim->animSrcHandler);
		InitAnimTotalFrame(currentAnim);
		MV1SetAttachAnimBlendRate(currentAnim->modelHandler, currentAnim->animAttachIndex, 1.0f);
	}

	void InitAnimTotalFrame(Animation* _animLoaded)
	{
		_animLoaded->animTotalFrame = DxLib::MV1GetAttachAnimTotalTime(_animLoaded->modelHandler, _animLoaded->animIndex);
	}

	void UpdateAnim()
	{
		if (!currentAnim)
		{
			return;
		}

		currentAnim->animFrame += 1.0f;
		if (currentAnim->animFrame >= currentAnim->animTotalFrame)
		{
			currentAnim->animFrame = 0;
		}

		//printf("playing anim %f\n", currentAnim->animFrame);
		DxLib::MV1SetAttachAnimTime(currentAnim->modelHandler, currentAnim->animAttachIndex, currentAnim->animFrame);

		if (currentAnim->name != playingAnimName)
		{

		}

		playingAnimName = currentAnim->name;
	}
		std::string playingAnimName = "";
};

void CreateConsole()
{
	// Allocates a new console for this process
	AllocConsole();

	// Redirect the output to the console
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	CreateConsole();

	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetMainWindowText("3Dアニメーション");
	SetWindowSize(WINDOW_W, WINDOW_H);
	SetBackgroundColor(125, 125, 125);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetCreateDrawValidGraphZBufferBitDepth(32);
	SetZBufferBitDepth(32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);

	int anim1 = -1;
	int anim2 = -1;
	int anim3 = -1;
	int animIndex = -1;
	int model = -1;
	float animTotalFrame = -1;

	model = MV1LoadModel("data/mv1/Nezumi.mv1");

	AnimationSystem animSys;

	Animation kickAnim = Animation("kick", "data/mv1/Kick Martelo 2.mv1", 0, model);
	Animation bootyDanceAnim = Animation("bootydance", "data/mv1/Booty Hip Hop Dance.mv1", 0, model);
	Animation waveDanceAnim = Animation("wavedance", "data/mv1/Wave Hip Hop Dance.mv1", 0, model);

	animSys.LoadAnim(kickAnim);
	animSys.LoadAnim(bootyDanceAnim);
	animSys.LoadAnim(waveDanceAnim);

	float gameTime = 0;

	DxLib::MV1SetPosition(model, VECTOR(WINDOW_W * 0.5f, 300.0f, -400));

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		clsDx();
		ClearDrawScreen();

		////////////////////////////////////
		//Input
		////////////////////////////////////
		if (CheckHitKey(KEY_INPUT_1))
		{
			animSys.PlayAnim("kick");
		}
		else if (CheckHitKey(KEY_INPUT_2))
		{
			animSys.PlayAnim("bootydance");
		}
		else if (CheckHitKey(KEY_INPUT_3))
		{
			animSys.PlayAnim("wavedance");
		}

		////////////////////////////////////
		//Update
		////////////////////////////////////
		animSys.UpdateAnim();
		gameTime++;


		////////////////////////////////////
		//Render
		////////////////////////////////////
		DxLib::MV1DrawModel(model);

		ScreenFlip();
	}


	DxLib_End();

	return 0;
}