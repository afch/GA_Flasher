//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <StrUtils.hpp> //PosEx
#include <IOUtils.hpp> //getpath
#include <dirent.h> //DIR type

#include <cstddef>
#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define FLASH_MEMORY "flash"
#define EEPROM_MEMORY "eeprom"

#define READ_COMMAND "r"
#define WRITE_COMMAND "w"

TGRA_AND_AFCH_FLASHER *GRA_AND_AFCH_FLASHER;
//---------------------------------------------------------------------------
__fastcall TGRA_AND_AFCH_FLASHER::TGRA_AND_AFCH_FLASHER(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::FlashButtonClick(TObject *Sender)
{
	MemoryType = FLASH_MEMORY;
	Command = WRITE_COMMAND;

    FileName = OpenFileEdit->Text;

  if (!RequirementsCheck()) return;

  DisableAllButtons(true);
  Memo1->Clear();
  RunAvrDude(PrepareString());
  DisableAllButtons(false);
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::Timer1Timer(TObject *Sender)
{
int curItem;

curItem = COMPortComboBox->ItemIndex;
GetComPorts(COMPortComboBox->Items, "COM");

COMPortComboBox->ItemIndex = curItem;
if (COMPortComboBox->ItemIndex == -1) COMPortComboBox->ItemIndex = 0;
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
	  {
	  TCHAR* pszCurrentDevice = &szDevices[i];
	  //int nLen = _tcslen(pszCurrentDevice);
	  if(/*nLen > 3 &&*/ _tcsnicmp(pszCurrentDevice, aNameStart.w_str(), aNameStart.Length()) == 0)
		{
		aList->Add(pszCurrentDevice);
		}

	  while(szDevices[i] != _T('\0')) i++;
	  i++;
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

/*String __fastcall TGRA_AND_AFCH_FLASHER::GetNextSubstring(String aBuf, int *aStartPos)
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
}    */

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

	TResourceStream *rstrmAvr_conf = new TResourceStream((int)HInstance, L"Avrdude_conf", RT_RCDATA);
	rstrmAvr_conf->SaveToFile(TPath::GetTempPath() + "avrdude.conf");

	TResourceStream *rstrmAvr_exe = new TResourceStream((int)HInstance, L"Avrdude_exe", RT_RCDATA);
	rstrmAvr_exe->SaveToFile(TPath::GetTempPath() + "avrdude.exe");

	TResourceStream *rstrmAvr_rc = new TResourceStream((int)HInstance, L"Avrdude_rc", RT_RCDATA);
	rstrmAvr_rc->SaveToFile(TPath::GetTempPath() + "avrdude.rc");

	PrepareString();
}
//---------------------------------------------------------------------------


void __fastcall TGRA_AND_AFCH_FLASHER::HintSpeedButtonClick(TObject *Sender)
{
  TForm* dlg = CreateMessageDialog("Choose only those *.HEX files that do NOT contain a Bootloader!", mtConfirmation, TMsgDlgButtons() << mbOK);
  dlg->Caption = "Warning";
  dlg->ShowModal();
  delete dlg;
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::OpenHEXBitBtnClick(TObject *Sender)
{
	if (OpenDialog1->Execute()) OpenFileEdit->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------


void __fastcall TGRA_AND_AFCH_FLASHER::RunAvrDude(String Params)
{
#define READ_BUFFER_SIZE 1024

//String AppName = L"c:\\avrdude.exe -Cc:\\avrdude.conf -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:\"C:\\fw.hex\":i";

//Params = StringReplace(Params, "\\", "\\\\", TReplaceFlags() << rfReplaceAll );

String AppName = TPath::GetTempPath() + L"avrdude.exe " +  Params;
Memo1->Lines->Add(AppName);

SECURITY_ATTRIBUTES Security;
HANDLE ReadPipe, WritePipe;
STARTUPINFO Start;
//TProcessInformation ProcessInfo;
char *Buffer, Data;
DWORD BytesRead, Apprunning;
int Result, DataSize;

Security.nLength = sizeof(TSecurityAttributes);
Security.bInheritHandle = true;
Security.lpSecurityDescriptor = NULL;

if (CreatePipe(&ReadPipe, &WritePipe, &Security, 0))
  {
  Buffer = new char[READ_BUFFER_SIZE + 1];

  memset(&Start, 0, sizeof(Start));
  Start.cb = sizeof(Start) ;
  Start.hStdOutput = WritePipe;
  Start.hStdInput = ReadPipe;
  Start.hStdError = WritePipe;
  Start.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
  Start.wShowWindow = SW_HIDE;

  if (CreateProcess(NULL, AppName.c_str(), &Security, &Security, true, NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE, NULL, NULL, &Start, &ProcessInfo))
	{
	CancelButton->Enabled = true;
    do
      {
	  Apprunning = WaitForSingleObject(ProcessInfo.hProcess, 1);
	  Application->ProcessMessages();
	  do
        {
        Result = PeekNamedPipe(ReadPipe, NULL, 0, NULL, (LPDWORD) &DataSize, NULL);
		if ((Result) && (DataSize))
          {
          if (DataSize > READ_BUFFER_SIZE) DataSize = READ_BUFFER_SIZE;
          ReadFile(ReadPipe, Buffer, DataSize, &BytesRead, NULL);
		  Buffer[BytesRead] = 0;
		  OemToAnsi(Buffer, Buffer);
		  Memo1->SelStart = Memo1->GetTextLen();
		  Memo1->SelText = (AnsiString) Buffer;
		  }
		}
	  while ((Result) && (DataSize));
      }
    while (Apprunning == WAIT_TIMEOUT);
	while ((Result) && (DataSize));
    }

  delete [] Buffer;

  CloseHandle(ProcessInfo.hProcess);
  CloseHandle(ProcessInfo.hThread);
  CloseHandle(ReadPipe);
  CloseHandle(WritePipe);

  CancelButton->Enabled = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::LinkLabel1Click(TObject *Sender)
{
	ShellExecute(0, 0, L"http://www.gra-afch.com", 0, 0, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::Image1Click(TObject *Sender)
{
	ShellExecute(0, 0, L"http://www.gra-afch.com", 0, 0, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::ReadFlashButtonClick(TObject *Sender)
{
	SaveDialog1->FileName = "FlashBackup.hex";
	//SaveDialog1->DefaultExt = "*.hex";
	SaveDialog1->Title ="Select where to Save the Flash (Firmware) from your Device";
	if (!SaveDialog1->Execute()) return;
	FileName = SaveDialog1->FileName;
	MemoryType = FLASH_MEMORY;
	Command = READ_COMMAND;

    if (!RequirementsCheck()) return;

	DisableAllButtons(true);
	Memo1->Clear();
	RunAvrDude(PrepareString());
	DisableAllButtons(false);
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::ReadEEPROMButtonClick(TObject *Sender)
{
	if (CPU == "atmega328p" || CPU == "ATmega328P_except_bootloader")
	{
		UnicodeString Text = "EEPROM Reading is not supported by default Optiboot bootloader! Do You want to try anyway?";
		if (MessageDlg(Text, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0, mbNo) != mrYes)
		{
			return;
		}
	}

	SaveDialog1->FileName = "EEPROMBackup.eep";
	//SaveDialog1->DefaultExt = "*.eep";
	SaveDialog1->Title ="Select where to Save the EEPROM (Settings) from your Device";
	if (!SaveDialog1->Execute()) return;
	FileName = SaveDialog1->FileName;
	MemoryType = EEPROM_MEMORY;
	Command = READ_COMMAND;

    if (!RequirementsCheck()) return;

	DisableAllButtons(true);
	Memo1->Clear();
	RunAvrDude(PrepareString());
	DisableAllButtons(false);
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::WriteEEPROMButtonClick(TObject *Sender)
{
	if (CPU == "atmega328p" || CPU == "ATmega328P_except_bootloader")
	{
		UnicodeString Text = "EEPROM Writing is not supported by default Optiboot bootloader! Do You want to try anyway?";
		if (MessageDlg(Text, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0, mbNo) != mrYes)
		{
			return;
		}
	}

	if (CPU == "atmega2560" || CPU == "ATmega2560_except_bootloader")
	{
		UnicodeString Text = "The default bootloader has an error preventing correct EEPROM reading, so verification will never pass, even if writing is successful!";
		MessageDlg(Text, mtInformation, TMsgDlgButtons() << mbOK, 0);
	}

	MemoryType = EEPROM_MEMORY;
	Command = WRITE_COMMAND;
	FileName = OpenFileEdit->Text;

	if (!RequirementsCheck()) return;

	DisableAllButtons(true);
    Memo1->Clear();
	RunAvrDude(PrepareString());
  	DisableAllButtons(false);
}
//---------------------------------------------------------------------------

String __fastcall TGRA_AND_AFCH_FLASHER::PrepareString()
{
    if (BootloaderCheckBox->Checked == true)
		switch (DevicesComboBox->ItemIndex)
		{
			case 0: case 1: case 2: case 3: CPU ="atmega328p"; Programmer=" -carduino"; break;
			case 4: CPU="atmega2560"; Programmer=" -cwiring"; break;
		} else
		switch (DevicesComboBox->ItemIndex)
		{
			case 0: case 1: case 2: case 3: CPU ="ATmega328P_except_bootloader"; Programmer=" -carduino"; break;
			case 4: CPU="ATmega2560_except_bootloader"; Programmer=" -cwiring"; break;
		}

	return "-C" + TPath::GetTempPath() + "avrdude.conf -v -p" + CPU + Programmer + " -P" + COMPortComboBox->Text + " -b115200 -D -U"+ MemoryType +":" + Command + ":\"" + FileName + "\":i";
}

// TRUE - ALL is OK, FALSE - Something is missing
Boolean __fastcall TGRA_AND_AFCH_FLASHER::RequirementsCheck()
{
  if (COMPortComboBox->ItemIndex == -1)
  {
	ShowMessage("COM Port NOT Selected!");
	return false;
  }

  if((!FileExists(TPath::GetTempPath() + "avrdude.conf")) || (!FileExists(TPath::GetTempPath() + "avrdude.exe")))
  {
	ShowMessage("File \"avrdude.conf\" or \"avrdude.exe\" not found!");
	return false;
  }

  if ((MemoryType == FLASH_MEMORY) && (AnsiUpperCase(ExtractFileExt(FileName)) != ".HEX"))
  {
	ShowMessage("Select FIRMWARE *.HEX file (WITHOUT a bootloader)!");
	return false;
  }
  if ((MemoryType == EEPROM_MEMORY) && (AnsiUpperCase(ExtractFileExt(FileName)) != ".EEP"))
  {
	ShowMessage("Select EEPROM *.EEP file (with settings)");
	return false;
  }

  return true;
}

void __fastcall TGRA_AND_AFCH_FLASHER::DisableAllButtons(boolean Disable)
{
	FlashButton->Enabled = !Disable;
	ReadFlashButton->Enabled = !Disable;
	ReadEEPROMButton->Enabled = !Disable;
	WriteEEPROMButton->Enabled = !Disable;
}
void __fastcall TGRA_AND_AFCH_FLASHER::CancelButtonClick(TObject *Sender)
{
		  TerminateProcess(ProcessInfo.hProcess, 1);
		  CancelButton->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::FormPaint(TObject *Sender)
{
	Image1->Left = GRA_AND_AFCH_FLASHER->Width/2 - Image1->Width/2;
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::FormResize(TObject *Sender)
{
       Image1->Left = GRA_AND_AFCH_FLASHER->Width/2 - Image1->Width/2;
}
//---------------------------------------------------------------------------


void __fastcall TGRA_AND_AFCH_FLASHER::DevicesComboBoxChange(TObject *Sender)
{
	PrepareString();
	if (DevicesComboBox->ItemIndex == 4) SaveFBLButton->Enabled = true;
	else SaveFBLButton->Enabled = false;
}
//---------------------------------------------------------------------------



String __fastcall TGRA_AND_AFCH_FLASHER::OpenFBLSaveDialog()
{
	FixedBLSaveDialog->Title ="Select where to Save FIXED Bootloader for ATmega2560";
	if (FixedBLSaveDialog->Execute()) return FixedBLSaveDialog->FileName;
	return "";
}

// true if ok, false if error
Boolean __fastcall TGRA_AND_AFCH_FLASHER::ReplaceBootLoader(String strFileName)
{
	 //ShowMessage(strFileName);
	TResourceStream *rstrmFBL_HEX = new TResourceStream((int)HInstance, L"Fixed_Bootloader_HEX", RT_RCDATA);
	try
	{
		rstrmFBL_HEX->SaveToFile(strFileName);
	} catch (const Exception& e)
	{
		ShowMessage("Failed to write the file: " + e.Message);
		return false;
	}

	return true;
	/*UnicodeString Text = "EEPROM Writing is not supported by default Optiboot bootloader! Do You want to try anyway?";
	if (MessageDlg(Text, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0, mbNo) != mrYes) */
}

String __fastcall TGRA_AND_AFCH_FLASHER::LookingForDefaultBootLoader()
{
    char* appdata = std::getenv("APPDATA");
	String strAppData = String(appdata).SubString(0, string(appdata).find_last_of("\\"));
	String strFullPath="";
	String strPkgVer;
	strAppData = strAppData + "\\Local\\Arduino15\\packages\\arduino\\hardware\\avr\\";
	DIR *dir;
	try
	{
		dir = opendir(AnsiString(strAppData).c_str());
		readdir(dir);   //.
		readdir(dir);   //..
		strPkgVer = readdir(dir)->d_name;  // Package version (if exist)
	} catch (const Exception& e)
	{
		return "";
	}
	strFullPath = strAppData + strPkgVer + "\\bootloaders\\stk500v2\\stk500boot_v2_mega2560.hex";
	if (FileExists(strFullPath))
	{
		return strFullPath;
	}  else
	{
		return "";
	}
}
void __fastcall TGRA_AND_AFCH_FLASHER::SaveFBLButtonClick(TObject *Sender)
{
	UnicodeString Text = "Replace \"stk500boot_v2_mega2560.hex\" Bootloader in Arduino IDE for ATmega2560 with Fixed version?";
	int ReplaceAnswer, MoreInfoAnswer;
	String strPath, FileName;

	ReplaceAnswer = MessageDlg(Text, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0, mbYes);

	if (ReplaceAnswer == mrYes)
	{
	  strPath = LookingForDefaultBootLoader();
	  if (strPath == "")
	  {
		ShowMessage("Arduino IDE or AVR Package NOT Found!");
		return;
	  }
	  if (ReplaceBootLoader(strPath))
	  {
		Text = "File with bootloader was replaced by fixed version. Now you need to burn the bootloader using Arduino IDE and an external hardware programmer, such as \"USBasp\" or another Arduino with the \"ArduinoISP\" sketch loaded. Do you need additional information?";
		MoreInfoAnswer = MessageDlg(Text, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0, mbYes);
		if (MoreInfoAnswer == mrYes) ShellExecute(0, 0, L"https://gra-afch.com/how-it-works/how-to-burn-or-update-bootloader-in-arduino-ide/", 0, 0, SW_SHOW); //добавить прямую ссылку на страницу с описаснием обновления бутлоадера
		return;
	  }
	  else return;
	}

	if (ReplaceAnswer == mrNo)
	{
	  FileName = OpenFBLSaveDialog();
	  if (FileName != "")
	  {
		try
			{
			TResourceStream *rstrmFixed_Bootloader_HEX = new TResourceStream((int)HInstance, L"Fixed_Bootloader_HEX", RT_RCDATA);
			rstrmFixed_Bootloader_HEX->SaveToFile(FileName);
			} catch(const Exception& e)
			{
				ShowMessage(e.Message);
				return;
			}
		ShowMessage("Saved");
	  }
	}

}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::HowtoburnBootloaderinArduinoIDE1Click(TObject *Sender)
{
	ShellExecute(0, 0, L"https://gra-afch.com/how-it-works/how-to-burn-or-update-bootloader-in-arduino-ide/", 0, 0, SW_SHOW);
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::SaveFixedATmega2560Bootloader1Click(TObject *Sender)

{
	SaveFBLButtonClick(NULL);
	/*FileName = OpenFBLSaveDialog();
	  if (FileName != "")
	  {
		try
			{
			TResourceStream *rstrmFixed_Bootloader_HEX = new TResourceStream((int)HInstance, L"Fixed_Bootloader_HEX", RT_RCDATA);
			rstrmFixed_Bootloader_HEX->SaveToFile(FileName);
			} catch(const Exception& e)
			{
				ShowMessage(e.Message);
				return;
			}
		ShowMessage("Saved");
	  }  */
}
//---------------------------------------------------------------------------

void __fastcall TGRA_AND_AFCH_FLASHER::About1Click(TObject *Sender)
{
    ShowMessage("Arduino Flasher v2.2 by GRA & AFCH.\ngra-afch.com\nfominalec@gra-afch.com");
}
//---------------------------------------------------------------------------

