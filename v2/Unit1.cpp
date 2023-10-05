//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <StrUtils.hpp> //PosEx
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGRA_AND_AFCH_FLASHER *GRA_AND_AFCH_FLASHER;
//---------------------------------------------------------------------------
__fastcall TGRA_AND_AFCH_FLASHER::TGRA_AND_AFCH_FLASHER(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::FlashButtonClick(TObject *Sender)
{
ShowMessage("!");
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::Timer1Timer(TObject *Sender)
{
int curItem;

curItem = COMPortComboBox->ItemIndex;
GetComPorts(COMPortComboBox->Items, "COM");

COMPortComboBox->ItemIndex = curItem;
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::GetComPorts(TStrings *aList, String aNameStart)
{
  TCHAR szDevices[65535];
  DWORD dwChars = QueryDosDevice(NULL, szDevices, 65535);
  if(dwChars)
	{
	aList->BeginUpdate();
	aList->Clear();
	int i=0;
	for (;;)
	  { // Получаем текущее имя устройства
	  TCHAR* pszCurrentDevice = &szDevices[i];
	  // Если похоже на "COMX" выводим на экран
	  //int nLen = _tcslen(pszCurrentDevice);
	  if(/*nLen > 3 &&*/ _tcsnicmp(pszCurrentDevice, aNameStart.w_str(), aNameStart.Length()) == 0)
		{
		aList->Add(pszCurrentDevice);
		}
		// Переходим к следующему символу терминатору
	  while(szDevices[i] != _T('\0')) i++;
	  // Перескакиваем на следующую строку
	  i++;
      // Список завершается двойным симмволом терминатором, так что если символ
	  // NULL, мы дошли до конца
	  if(szDevices[i] == _T('\0')) break;
	  }
	aList->EndUpdate();
	}



/*
  TCHAR vBuf[65535];
  int vRes;
  int vErr;
  int vBufSize;
  int vNameStartPos;
  String vName;

  vBufSize = 1024 * 5;
  vRes = 0;

  while (vRes == 0)
	{
	 // setlength(vBuf, vBufSize) ;
	  //vBuf = new CHAR[vBufSize];
	  SetLastError(ERROR_SUCCESS);
	  //vRes = QueryDosDevice(NULL, vBuf, vBufSize);
	  vRes = QueryDosDevice(NULL, vBuf, 65535);
	  vErr = GetLastError();

	  //for 2000
	  if ((vRes != 0) && (vErr == ERROR_INSUFFICIENT_BUFFER))
		{
		  vBufSize = vRes;
		  vRes = 0;
		};

	  if ((vRes == 0) && (vErr == ERROR_INSUFFICIENT_BUFFER))
		{
		  vBufSize = vBufSize + 1024;
		};

	  if ((vErr != ERROR_SUCCESS) && (vErr != ERROR_INSUFFICIENT_BUFFER))
		{
		  throw Exception(SysErrorMessage(vErr));
		}
	};
  //setlength(vBuf, vRes) ;

  vNameStartPos = 1;
  vName = GetNextSubstring(String(vBuf), &vNameStartPos);
  //Memo1->Text = vBuf;      //DEL THIS !!!!!!!!!!!!!!!!!!!!!

  aList->BeginUpdate();
  try
  {
	aList->Clear();
	while (vName != "")
	  {
		//if (StartsStr(aNameStart, vName)) \
		//if (strncmp(aNameStart->c_str(), vName))
		if (vName.SubString(0, aNameStart.Length()) == aNameStart)
		  aList->Add(vName);
		vName = GetNextSubstring(vBuf, &vNameStartPos);
	  }
  }
  // catch(const Exception& e){int i=0;}
  __finally
  {
	aList->EndUpdate();
  };   */
}

String __fastcall TGRA_AND_AFCH_FLASHER::GetNextSubstring(String aBuf, int *aStartPos)
{
  int vLastPos;
  String Result;

  if (*aStartPos < 1) throw ERangeError("aStartPos must be greate then 0");


  if (*aStartPos > aBuf.Length() )
	{
	  return "";
	}

  vLastPos = PosEx('\0', aBuf, *aStartPos);
  //Result = Copy(aBuf, aStartPos, vLastPos - aStartPos);
  Result = aBuf.SubString(*aStartPos, vLastPos - *aStartPos);
  aStartPos = aStartPos + (vLastPos - *aStartPos) + 1;
  return Result;
}
void __fastcall TGRA_AND_AFCH_FLASHER::SearchPortBitBtnClick(TObject *Sender)
{
	GetComPorts(COMPortComboBox->Items, "COM");
	COMPortComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::FormCreate(TObject *Sender)
{
	GetComPorts(COMPortComboBox->Items, "COM");
	COMPortComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------

