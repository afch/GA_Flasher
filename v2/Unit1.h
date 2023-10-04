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
	void __fastcall FlashButtonClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall GetComPorts(TStrings *aList, String aNameStart);
    String __fastcall GetNextSubstring(String aBuf, int *aStartPos);
	void __fastcall SearchPortBitBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TGRA_AND_AFCH_FLASHER(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGRA_AND_AFCH_FLASHER *GRA_AND_AFCH_FLASHER;
//---------------------------------------------------------------------------
#endif
