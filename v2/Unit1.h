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
	private:	// User declarations
public:		// User declarations
	__fastcall TGRA_AND_AFCH_FLASHER(TComponent* Owner);
	//String __fastcall GetNextSubstring(String aBuf, int *aStartPos);
    void __fastcall GetComPorts(TStrings *aList, String aNameStart);
	void __fastcall RunAvrDude(String Params);
	String __fastcall PrepareString();
	Boolean __fastcall RequirementsCheck();
    void __fastcall DisableAllButtons(boolean Disable);
	String MemoryType;
	String Command;
    String FileName;
};
//---------------------------------------------------------------------------
extern PACKAGE TGRA_AND_AFCH_FLASHER *GRA_AND_AFCH_FLASHER;
//---------------------------------------------------------------------------
#endif
