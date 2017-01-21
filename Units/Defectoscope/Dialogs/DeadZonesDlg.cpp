#include "stdafx.h"
#include "Dialogs/Dialogs.h"
#include "DlgTemplates\ParamDlg.h"
#include "DlgTemplates\ParamDlg.hpp"
#include "App/AppBase.h"
#include "DiffApp/App.h"

MIN_EQUAL_VALUE(DeadAreaMM0<Cross>, 0)
MAX_EQUAL_VALUE(DeadAreaMM0<Cross>, 500)
PARAM_TITLE(    DeadAreaMM0<Cross>, L"���������� �������� ������ �����")

MIN_EQUAL_VALUE(DeadAreaMM1<Cross>, 0)
MAX_EQUAL_VALUE(DeadAreaMM1<Cross>, 500)
PARAM_TITLE(    DeadAreaMM1<Cross>, L"���������� �������� ����� �����")

MIN_EQUAL_VALUE(DeadAreaMM0<Long>, 0)
MAX_EQUAL_VALUE(DeadAreaMM0<Long>, 500)
PARAM_TITLE(    DeadAreaMM0<Long>, L"���������� �������� ������ �����")
							
MIN_EQUAL_VALUE(DeadAreaMM1<Long>, 0)
MAX_EQUAL_VALUE(DeadAreaMM1<Long>, 500)
PARAM_TITLE(    DeadAreaMM1<Long>, L"���������� �������� ����� �����")

MIN_EQUAL_VALUE(DeadAreaMM0<Thickness>, 0)
MAX_EQUAL_VALUE(DeadAreaMM0<Thickness>, 500)
PARAM_TITLE(    DeadAreaMM0<Thickness>, L"�������� ������� ������ �����")
							
MIN_EQUAL_VALUE(DeadAreaMM1<Thickness>, 0)
MAX_EQUAL_VALUE(DeadAreaMM1<Thickness>, 500)
PARAM_TITLE(    DeadAreaMM1<Thickness>, L"�������� ������� ����� �����")

void DeadZonesDlg::Do(HWND h)
{
	if(TemplDialog<ParametersBase, DeadAreaTable>(Singleton<DeadAreaTable>::Instance()).Do(h, L"̸����� ����"))
	{
	}
}