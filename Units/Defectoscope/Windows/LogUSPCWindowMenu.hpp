#pragma once
#include "Dialogs/Dialogs.h"
#include "Ini/WindowsPosition.h"
namespace LogUSPCWindowMenu
{
struct MainFile{};
struct MainOptionUnits{};
struct SaveCoordinateWindow: StoredWindowPosition<LogUSPCWindow>{}; 
struct MainExit{static void Do(HWND h){DestroyWindow(h);}};

template<>struct TopMenu<MainFile>
{
	typedef TL::MkTlst<
	    MenuItem<MainExit>
	>::Result list;
};

template<>struct TopMenu<MainOptionUnits>
{
	typedef TL::MkTlst<	
		MenuItem<SaveCoordinateWindow>
	>::Result list;
};

typedef TL::MkTlst<
	TopMenu<MainFile>
	, TopMenu<MainOptionUnits>
>::Result MainMenu;
//--------------------------------------------------------------------------------------------------------
MENU_TEXT(L"����", TopMenu<MainFile>)	
MENU_TEXT(L"���������", TopMenu<MainOptionUnits>)

MENU_ITEM(L"�����", MainExit)
MENU_ITEM(L"��������� ���������� ����", SaveCoordinateWindow)
//MENU_ITEM(L"��������� ���������", SaveDateFile)
}
