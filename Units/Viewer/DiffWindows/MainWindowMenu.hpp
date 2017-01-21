#pragma once
#include "App/config.h"
#include "Ini/WindowsPosition.h"
#include "Dialogs/Dialogs.h"
#include "Windows/CrossThresholdWindow.h"
#include "Windows/LongThresholdWindow.h"
#include "Windows/ThicknessThresholdWindow.h"
#include "Windows/Common.h"

namespace MainWindowMenu
{
	struct MainFile{};
	MENU_TEXT(L"����", TopMenu<MainFile>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	struct LoadDateFile: LoadDataDlg{};//{static void Do(HWND h){zprint("");}};
	struct SaveDateFile: StoredDataDlg{};//{static void Do(HWND h){zprint("");}};
	struct Compute     : RecalculationDlg{};//{static void Do(HWND h){zprint("");}};
	struct MainExit
	{
		static void Do(HWND h)
		{
			TClose c = {h, WM_CLOSE, 0, 0};
			SendMessage(MESSAGE(c));
		}
	};

	MENU_ITEM(L"��������� ������", LoadDateFile)
	MENU_ITEM(L"��������� ������", SaveDateFile)
	MENU_ITEM(L"����������", Compute)
	MENU_ITEM(L"�����", MainExit)

	template<>struct TopMenu<MainFile>
	{
		typedef TL::MkTlst<
			MenuItem<LoadDateFile>
			//, MenuItem<SaveDateFile>
			, Separator<0>
			, MenuItem<Compute>
			, Separator<1>
			, MenuItem<MainExit>
		>::Result list;
	};
	//------------------------------------------------------------------------
	struct MainOptionTypeSize{};
	MENU_TEXT(L"����������", TopMenu<MainOptionTypeSize>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
	struct Tresholds {};
	struct Thickness{};
	struct DeadZones         : DeadZonesDlg{};//{static void Do(HWND h){zprint("");}};
	//struct AllowableThickness{static void Do(HWND h){zprint("");}};
	//struct RotationalSpeed   {static void Do(HWND h){zprint("");}};
							 						

	struct CrossThresholdWindow__: Common::OpenWindow<CrossThresholdWindow>{};
	struct LongThresholdWindow__: Common::OpenWindow<LongThresholdWindow>{};
	struct ThicknessThresholdWindow__: Common::OpenWindow<ThicknessThresholdWindow>{};

	struct BrackStrobe2__: BrackStrobe2Dlg{};//{static void Do(HWND h){zprint("");}};

	struct MedianFiltre           : MedianFiltreDlg{};//{static void Do(HWND h){zprint("");}};

	template<>struct SubMenu<Tresholds>
	{
		typedef TL::MkTlst<
			MenuItem<CrossThresholdWindow__>
			, MenuItem<LongThresholdWindow__>
			, SubMenu<Thickness>
		>::Result list;
	};

   // MENU_ITEM(L"������ ����������", ThicknessTreshold)
	MENU_TEXT(L"������ ����������", SubMenu<Tresholds>)
	MENU_ITEM(L"���������� ������", CrossThresholdWindow__)
	MENU_ITEM(L"���������� ������", LongThresholdWindow__)
	MENU_ITEM(L"������ �������", ThicknessThresholdWindow__)
	MENU_ITEM(L"̸����� ����", DeadZones)

	MENU_ITEM(L"��������� ������", MedianFiltre)
	MENU_ITEM(L"����������", BrackStrobe2__)
	MENU_TEXT(L"�������", SubMenu<Thickness>)

	

	template<>struct TopMenu<MainOptionTypeSize>
	{
		typedef TL::MkTlst<
		     SubMenu<Tresholds>
			, MenuItem<DeadZones>
			//, MenuItem<AllowableThickness>
			, MenuItem<MedianFiltre>
			//, MenuItem<RotationalSpeed>
			//, Separator<0>
			//, MenuItem<MainCreateTypesize>
			//, MenuItem<MainDeleteTypeSize>
		>::Result list;
	 };
	//--------------------------------------------------------------------------------
	struct Options{};
	MENU_TEXT(L"���������", TopMenu<Options>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	struct WindowPosition    : WindowPositionDlg<MainWindow>{};//{static void Do(HWND h){zprint("");}};

	MENU_ITEM(L"��������� ���������� ����", WindowPosition)

	template<>struct TopMenu<Options>
	{
		typedef TL::MkTlst<
			MenuItem<WindowPosition>
		>::Result list;		
	};
	//-------------------------------------------------------------------------------------------------------
	struct Setting{};
	MENU_TEXT(L"���������", TopMenu<Setting>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	struct AnalogPlate            : AnalogPlateDlg{};//{static void Do(HWND h){zprint("");}};
	struct DiscretePlate	      {};//static void Do(HWND h){zprint("");}};
	struct DiscretePlateInputs    : InputsDlg{};//{static void Do(HWND h){zprint("");}};
	struct DiscretePlateOutputs   : OutputsDlg{};//{static void Do(HWND h){zprint("");}};
	struct ColorItems             : ColorItemsDlg{};//{static void Do(HWND h){zprint("");}};
	struct Coefficient            {static void Do(HWND h){zprint("");}};
	//struct MedianFiltre           : MedianFiltreDlg{};//{static void Do(HWND h){zprint("");}};
	struct Signal                 {static void Do(HWND h){zprint("");}};
	struct ACFBorder              {static void Do(HWND h){zprint("");}};
	//struct TestTab                : TestTabsDlg{};//{static void Do(HWND h){zprint("");}};
	struct OffsetsSensors: OffsetsSensorsDlg{};
	struct BaseLength : BaseLengthDlg{};
	
	MENU_TEXT(L"���������� �����", SubMenu<DiscretePlate>)
	MENU_ITEM(L"������� �����", DiscretePlateInputs)
	MENU_ITEM(L"������� �����", DiscretePlateOutputs)
	MENU_ITEM(L"������������ ���������", Coefficient)
	
	MENU_ITEM(L"���������� �����", AnalogPlate)
	MENU_ITEM(L"��������� �������", Signal)
	MENU_ITEM(L"������� ���", ACFBorder)
	MENU_ITEM(L"�����", ColorItems)
	//MENU_ITEM(L"������������ ���� � ����������", TestTab)
	MENU_ITEM(L"�������� ��������", OffsetsSensors)
	MENU_ITEM(L"������� ����������", BaseLength)
	

	template<>struct TopMenu<Setting>
	{
		typedef TL::MkTlst<
			MenuItem<OffsetsSensors>
			, MenuItem<BaseLength>
			, MenuItem<ColorItems>
		>::Result list;		
	};
	// ----------------------------------------------------------------------------------------------------
	struct MainAbout : AboutWindowDlg{};//{static void Do(HWND h){zprint("");}};
	MENU_TEXT(L"� ���������", TopMenu<MainAbout>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	MENU_ITEM(L"� ���������", MainAbout)

	template<>struct TopMenu<MainAbout>
	{
		typedef TL::MkTlst<
			MenuItem<MainAbout>
		>::Result list;
	};
	// --------------------------------------------------------------------------------------------------------- 
	/// \brief	�������� ���� ������ �������������
	//struct TestMenu{};
	//MENU_TEXT(L"TestMenu", TopMenu<TestMenu>)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//struct TestSubMenu0{};
	//struct TestSubMenu1{static void Do(HWND){zprint("");}};
	//struct TestSubMenu2{static void Do(HWND){zprint("");}};
	//struct TestSubMenu3{static void Do(HWND){zprint("");}};
	//struct TestSubMenu4{static void Do(HWND){zprint("");}};
	//
	//MENU_ITEM(L"TestSubMenu0", TestSubMenu0)
	//MENU_ITEM(L"TestSubMenu1", TestSubMenu1)
	//MENU_ITEM(L"TestSubMenu2", TestSubMenu2)
	//MENU_ITEM(L"TestSubMenu3", TestSubMenu3)
	//MENU_ITEM(L"TestSubMenu4", TestSubMenu4)
	//
	//template<>struct TopMenu<TestMenu>
	//{
	//	typedef TL::MkTlst<
	//		MenuItem<TestSubMenu0>
	//		, MenuItem<TestSubMenu1>
	//		, MenuItem<TestSubMenu2>
	//		, MenuItem<TestSubMenu3>
	//		, MenuItem<TestSubMenu4>
	//	>::Result list;
	//};
	//---------------------------------------------------------------------------------------------------------------
	typedef TL::MkTlst<
		TopMenu<MainFile>
		, TopMenu<MainOptionTypeSize>
		, TopMenu<Options>
		, TopMenu<Setting>
		, TopMenu<MainAbout>
	>::Result MainMenu;	
	}
