#include <Windows.h>
#include <stdexcept>
#include <list>
#include "common.h"
std::list<std::string> pathList;
std::vector<std::string> modelList;
std::vector<std::string> textureList;
//���ł�Ł[��
//�Ă�������

std::vector<std::string> GetFileList(std::string directory)
{
	HANDLE h_find;
	//FindNextFile�֐��ɂ���Č��o���ꂽ�t�@�C���Ɋւ����񂪊܂܂��B
	WIN32_FIND_DATA win32fd;	
	//���o�����t�@�C������ۑ�����
	std::vector<std::string> file_names;
	if (pathList.empty())
	{
		pathList.push_front(directory + "/");
	}
	auto searchPath = pathList.back() + "/*";
	/*FindFirstFile: 
	 ����̖��O�ƈ�v���閼�O�����f�B���N�g�����̃t�@�C���܂��̓T�u�f�B���N�g������������
	 �Ȃ����O�̓��C���h�J�[�h�ł���*/
	h_find = FindFirstFile(searchPath.c_str(), &win32fd);

	if (h_find == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("file not found");
	}
	/*win32fd.dwFileAttributes: 
	  dwFileAttributes�����o�[��FILE_ATTRIBUTE_REPARSE_POINT�������܂܂�Ă���ꍇ�A
	  ���̃����o�[�͈ȉ��̍ĉ�̓|�C���g�^�O���w�肷��B
	  ����ȊO�̏ꍇ�A���̒l�͖���`*/

	/*FILE_ATTRIBUTE_REPARSE_POINT:
�@	�ĉ�̓|�C���g���֘A�t�����Ă���t�@�C���܂��̓f�B���N�g���A
	�܂��̓V���{���b�N�����N�̃t�@�C���B*/
	do {
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (win32fd.cFileName[0] == '.')
			{
				continue;
			}
			pathList.push_front(directory+"/"+ win32fd.cFileName);
		}
		else {
			std::string file_name = win32fd.cFileName;
			
			if (file_name.find("mv1") != std::string::npos)
			{
				modelList.push_back(file_name);
			}
			else if (searchPath.find("texture") != std::string::npos)
			{
				textureList.push_back(file_name);
			}
			file_names.push_back(file_name.c_str());
		}
	} while (FindNextFile(h_find, &win32fd));
	pathList.pop_back();
	if (!pathList.empty())
	{
		GetFileList(pathList.back());
	}
	/*FindNextFile:
	 ���̊֐����t�@�C������Ԃ������́A�t�@�C���V�X�e���̃^�C�v�ɂ���ĈقȂ�B
	 NTFS�t�@�C���V�X�e����CDFS�t�@�C���V�X�e���ł́A���O�͒ʏ�A���t�@�x�b�g���ɕԂ����B
	 FAT�t�@�C���V�X�e���ł́A���O�͒ʏ�A�t�@�C�����f�B�X�N�ɏ������܂ꂽ�����ŕԂ����B
	�y�������A�����̓���͕ۏ؂���Ȃ��z�B
	�p�X���V���{���b�N�����N���w���Ă���ꍇ�A
	WIN32_FIND_DATA�o�b�t�@�ɂ́A�^�[�Q�b�g�ł͂Ȃ��V���{���b�N�����N�Ɋւ����񂪊܂܂�Ă���B*/

	/*�y�Ԃ�l�z
	�֐������������ꍇ�A�߂�l��TRUE���Ԃ�A
	����lpFindFileData�ɂ́A���Ɍ��������t�@�C���܂��̓f�B���N�g���Ɋւ����񂪊܂܂��B
�@  �֐������s�����ꍇ�A�߂�l��FALSE���Ԃ�A����lpFindFileData�̓��e�͕s��ƂȂ�B
    �g���G���[�����擾����ɂ́AGetLastError�֐����Ăяo���B
�@  ��v����t�@�C����������Ȃ����߂Ɋ֐������s�����ꍇ�A
    GetLastError�֐���ERROR_NO_MORE_FILES��Ԃ��B*/
	FindClose(h_find);

	return textureList;
}

const std::vector<std::string> GetTextureList()
{
	return textureList;
}

const std::vector<std::string> GetModelList()
{
	return modelList;
}

const VECTOR operator+(const VECTOR& vec, const VECTOR& vec2)
{
	VECTOR v;
	v.x = vec.x + vec2.x;
	v.y = vec.y + vec2.y;
	v.z = vec.z + vec2.z;
	return v;
}

const VECTOR operator*(const VECTOR& vec, const float& value)
{
	VECTOR v;
	v.x = vec.x * value;
	v.y = vec.y * value;
	v.z = vec.z * value;
	return v;
}
