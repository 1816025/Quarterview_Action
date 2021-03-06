#include <Windows.h>
#include <stdexcept>
#include <list>
#include "common.h"
std::list<std::string> pathList;
std::vector<std::string> modelList;
std::vector<std::string> textureList;
//もでるでーた
//てくすちゃ

const void GetFileList(std::string directory)
{
	HANDLE h_find;
	//FindNextFile関数によって検出されたファイルに関する情報が含まれる。
	WIN32_FIND_DATA win32fd;	
	//検出したファイル名を保存する
	std::vector<std::string> file_names;
	if (pathList.empty())
	{
		pathList.push_front(directory + "/");
	}
	auto searchPath = pathList.back() + "/*";
	/*FindFirstFile: 
	 特定の名前と一致する名前を持つディレクトリ内のファイルまたはサブディレクトリを検索する
	 なお名前はワイルドカードでも可*/
	h_find = FindFirstFile(searchPath.c_str(), &win32fd);

	if (h_find == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("file not found");
	}
	/*win32fd.dwFileAttributes: 
	  dwFileAttributesメンバーにFILE_ATTRIBUTE_REPARSE_POINT属性が含まれている場合、
	  このメンバーは以下の再解析ポイントタグを指定する。
	  それ以外の場合、この値は未定義*/

	/*FILE_ATTRIBUTE_REPARSE_POINT:
　	再解析ポイントが関連付けられているファイルまたはディレクトリ、
	またはシンボリックリンクのファイル。*/
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
	 この関数がファイル名を返す順序は、ファイルシステムのタイプによって異なる。
	 NTFSファイルシステムとCDFSファイルシステムでは、名前は通常アルファベット順に返される。
	 FATファイルシステムでは、名前は通常、ファイルがディスクに書き込まれた順序で返される。
	【ただし、これらの動作は保証されない】。
	パスがシンボリックリンクを指している場合、
	WIN32_FIND_DATAバッファには、ターゲットではなくシンボリックリンクに関する情報が含まれている。*/

	/*【返り値】
	関数が成功した場合、戻り値はTRUEが返り、
	引数lpFindFileDataには、次に見つかったファイルまたはディレクトリに関する情報が含まれる。
　  関数が失敗した場合、戻り値はFALSEが返り、引数lpFindFileDataの内容は不定となる。
    拡張エラー情報を取得するには、GetLastError関数を呼び出す。
　  一致するファイルが見つからないために関数が失敗した場合、
    GetLastError関数はERROR_NO_MORE_FILESを返す。*/
	FindClose(h_find);
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
