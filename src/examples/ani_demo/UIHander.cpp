#include "StdAfx.h"
#include "UIHander.h"

#include "MainDlg.h"

CUIHander::CUIHander(CMainDlg * pMainDlg) : m_pMainDlg(pMainDlg)
{
}

CUIHander::~CUIHander(void)
{
}

LRESULT CUIHander::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_pMainDlg->AnimateHostWindow(200,AW_HOR_NEGATIVE|AW_SLIDE);
	m_pMainDlg->FindChildByName("grp_animode")->CheckRadioButton(m_pMainDlg->FindChildByName("ani_slide"));
	m_pMainDlg->FindChildByName("grp_hor_mode")->CheckRadioButton(m_pMainDlg->FindChildByName("slide_hor_nagetive"));

    return 0; 
}

void CUIHander::OnBtnAnimate()
{
	CDuiWindow * pImg=m_pMainDlg->FindChildByName("img_tst");
	if(pImg)
	{
		DWORD dwFlag=0;
		CDuiWindow * pRadio=m_pMainDlg->FindChildByName("grp_animode")->GetCheckedRadioButton();
		if(strcmp(pRadio->GetName(),"ani_slide")==0)
			dwFlag|=AW_SLIDE;
		if(strcmp(pRadio->GetName(),"ani_center")==0)
			dwFlag|=AW_CENTER;
		if(strcmp(pRadio->GetName(),"ani_blend")==0)
			dwFlag|=AW_BLEND;
		if(dwFlag & AW_SLIDE)
		{
			CDuiWindow * pRadioHor=m_pMainDlg->FindChildByName("grp_hor_mode")->GetCheckedRadioButton();
			if(pRadioHor)
			{
				if(strcmp(pRadioHor->GetName(),"slide_hor_nagetive")==0) dwFlag|=AW_HOR_NEGATIVE;
				else dwFlag |= AW_HOR_POSITIVE;
			}
			CDuiWindow * pRadioVer=m_pMainDlg->FindChildByName("grp_ver_mode")->GetCheckedRadioButton();
			if(pRadioVer)
			{
				if(strcmp(pRadioVer->GetName(),"slide_ver_nagetive")==0) dwFlag|=AW_VER_NEGATIVE;
				else dwFlag |= AW_VER_POSITIVE;
			}
		}
		
		if(pImg->IsVisible(TRUE)) dwFlag |= AW_HIDE;

		pImg->AnimateWindow(200,dwFlag);
	}
}

void CUIHander::OnBtnClose()
{
	m_pMainDlg->AnimateHostWindow(200,AW_VER_NEGATIVE|AW_SLIDE|AW_HIDE);
	m_pMainDlg->EndDialog(0);
}