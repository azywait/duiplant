#include <dui/duistd.h>
#include <dui/DuiImgDecoder_Def.h>

#pragma warning(disable:4996)

namespace DuiEngine
{

CDuiImgDecoder_Def::CDuiImgDecoder_Def(void)
{
    CDuiImgX::GdiplusStartup();
}

CDuiImgDecoder_Def::~CDuiImgDecoder_Def(void)
{
    CDuiImgX::GdiplusShutdown();
}


DuiEngine::CDuiImgBase* CDuiImgDecoder_Def::CreateDuiImage( LPCTSTR pszType )
{
    if(_tcsicmp(pszType,_T("bmp"))==0) return new CDuiBitmap;
    else if(_tcsicmp(pszType,_T("imgx"))==0) return new CDuiImgX;
    else return NULL;
}

void CDuiImgDecoder_Def::DestoryDuiImage( CDuiImgBase* pImg )
{
    pImg->Release();
}


}//end of namespace DuiEngine