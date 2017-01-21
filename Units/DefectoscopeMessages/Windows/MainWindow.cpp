#include "stdafx.h"
#include "MainWindow.h"
#include "MenuApi.h"
#include "EmptyWindow.h"
#include "LogBuffer.h"
#include "MainWindowMenu.hpp"

#include "DebugMess.h"
//------------------------------------------------------------------------
MainWindow::MainWindow()
{
	lastIndex = -1;
}
//---------------------------------------------------------------------------
void MainWindow::operator()(TSize &m)
{
	if(m.resizing == SIZE_MINIMIZED || 0 == m.Width || 0 == m.Height) return;
	RECT r;
	GetClientRect(m.hwnd, &r);
	MoveWindow(mainWindowGrid.hWnd, 0,  0, r.right, r.bottom, TRUE);
}
//------------------------------------------------------------------------
void MainWindow::operator()(TCommand &m)
{
	//GetMenuToolBarEvent(m);
	EventDo(m);
}
//-------------------------------------------------------------------------------------------
unsigned MainWindow::operator()(TNotify &m)
{
	NotifyHandler *x = (NotifyHandler *)GetWindowLongPtr(m.pnmh->hwndFrom, GWLP_USERDATA);
	if(0 == IsBadReadPtr(x, sizeof(x)))return (*x)(m);
	return 0;
}
//------------------------------------------------------------------------
void MainWindow::operator()(TGetMinMaxInfo &m)
{
	if(NULL != m.pMinMaxInfo)
	{
		m.pMinMaxInfo->ptMinTrackSize.x = 300;
		m.pMinMaxInfo->ptMinTrackSize.y = 200;
		m.pMinMaxInfo->ptMaxTrackSize.x = 2000;
		m.pMinMaxInfo->ptMaxTrackSize.y = 2000;		
	}		
}
//------------------------------------------------------------------------
unsigned MainWindow::operator()(TCreate &m)
{
	Menu<MainWindowMenu::MainMenu>().Init(m.hwnd);
	mainWindowGrid.Init(m.hwnd);
	SetTimer(m.hwnd,             // ����� �������� ����
		IDT_TIMER1,            // ������������� �������
		300,                 // �������� - 1 ������
		(TIMERPROC) NULL);     // ��������� ������� ���
	return 0;
}
//------------------------------------------------------------------------
void MainWindow::operator()(TDestroy &m)
{
	KillTimer(m.hwnd, IDT_TIMER1);
	PostQuitMessage(0);
}
//-------------------------------------------------------------------------
void MainWindow::operator()(TTimer &m)
{
	switch(m.ID)
	{
	case IDT_TIMER1:
		{
			unsigned last = Log::LastMessageIndex();
			if(lastIndex == last) break;
			lastIndex = last;
			int i = ListView_GetTopIndex(mainWindowGrid.hWnd);
			int count = i + ListView_GetCountPerPage(mainWindowGrid.hWnd);
			for(int z = i; z < count; ++z)
			{
				ListView_Update(mainWindowGrid.hWnd, z);
			}
		}
		break;
	}
}

