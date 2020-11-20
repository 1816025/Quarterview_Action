#pragma once
#include <DxLib.h>
#include <vector>
#include <string>

constexpr auto WINDOW_NAME	 = ("Quarterview_Action");
//âÊñ ÉTÉCÉY
constexpr auto SCREEN_SIZE_X = 1024;
constexpr auto SCREEN_SIZE_Y = 600;

constexpr auto FIELD_SIZE_X = 10;
constexpr auto FIELD_SIZE_Z = 30;
constexpr auto BLOCK_SIZE = 100.0f;
struct ShadowParam
{
	int id;
	VECTOR pos;
	VECTOR rol;
	VECTOR scl;
};

struct Param
{
	int id;
	int dir;
	float speed;
	VECTOR pos;	//à íu
	VECTOR rol;	//âÒì]
	VECTOR scl;	//ägèk

};

enum class STATE
{
	JUMP,
	FALL,
	LANDING
};

std::vector<std::string> GetFileList(std::string directory);
const std::vector<std::string> GetTextureList();
const std::vector<std::string> GetModelList();
const VECTOR operator+(const VECTOR& vec, const VECTOR& vec2);
const VECTOR operator*(const VECTOR& vec, const float& value);
