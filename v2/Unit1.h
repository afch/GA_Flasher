//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TGRA_AND_AFCH_FLASHER : public TForm
{
__published:	// IDE-managed Components
	TButton *FlashButton;
	TComboBox *COMPortComboBox;
	TBitBtn *SearchPortBitBtn;
	TLabel *Label1;
	TEdit *OpenFileEdit;
	TBitBtn *OpenHEXBitBtn;
	TLabel *Label2;
	TLabel *Label3;
	TComboBox *DevicesComboBox;
	TOpenDialog *OpenDialog1;
	TMemo *Memo1;
	TTimer *Timer1;
	TSpeedButton *HintSpeedButton;
	TLinkLabel *LinkLabel1;
	TButton *ReadFlashButton;
	TButton *ReadEEPROMButton;
	TButton *WriteEEPROMButton;
	TImage *Image1;
	TSaveDialog *SaveDialog1;
	TButton *CancelButton;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TCheckBox *BootloaderCheckBox;
	TGroupBox *GroupBox3;
	TButton *SaveFBLButton;
	TImageList *ImageList1;
	TGroupBox *GroupBox4;
	TSaveDialog *FixedBLSaveDialog;
	TMainMenu *MainMenu1;
	TMenuItem *Help1;
	TMenuItem *HowtoburnBootloaderinArduinoIDE1;
	TMenuItem *N1;
	TMenuItem *About1;
	TMenuItem *File1;
	TMenuItem *SaveFixedATmega2560Bootloader1;
	void __fastcall FlashButtonClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall SearchPortBitBtnClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall HintSpeedButtonClick(TObject *Sender);
	void __fastcall OpenHEXBitBtnClick(TObject *Sender);
	void __fastcall LinkLabel1Click(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall ReadFlashButtonClick(TObject *Sender);
	void __fastcall ReadEEPROMButtonClick(TObject *Sender);
	void __fastcall WriteEEPROMButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall DevicesComboBoxChange(TObject *Sender);
	void __fastcall SaveFBLButtonClick(TObject *Sender);
	void __fastcall HowtoburnBootloaderinArduinoIDE1Click(TObject *Sender);
	void __fastcall SaveFixedATmega2560Bootloader1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	private:	// User declarations
public:		// User declarations
	__fastcall TGRA_AND_AFCH_FLASHER(TComponent* Owner);
	//String __fastcall GetNextSubstring(String aBuf, int *aStartPos);
    void __fastcall GetComPorts(TStrings *aList, String aNameStart);
	void __fastcall RunAvrDude(String Params);
	String __fastcall PrepareString();
	Boolean __fastcall RequirementsCheck();
	void __fastcall DisableAllButtons(boolean Disable);
	Boolean __fastcall ReplaceBootLoader(String strFileName);
	String __fastcall OpenFBLSaveDialog();
	String __fastcall LookingForDefaultBootLoader();
	String MemoryType;
	String Command;
	String FileName;
	TProcessInformation ProcessInfo;
	Boolean bAvrDudeRunning;
	String CPU;
	String Programmer;
};
//---------------------------------------------------------------------------
extern PACKAGE TGRA_AND_AFCH_FLASHER *GRA_AND_AFCH_FLASHER;
//---------------------------------------------------------------------------
#endif
