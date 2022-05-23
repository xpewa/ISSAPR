//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <string>
#include <fstream>
//---------------------------------------------------------------------------

class InspectorQuality {
public:
	InspectorQuality(std::string str);
	void checkAllParametrs();
	int getCountTab() { return count_tab; }
	int getCountEqualSpace() { return count_equal_space; }
	int getCountBraces() { return count_braces; }
	int getCountSpaces() { return count_spaces; }
	int getCount100Symbol() { return count_100_symbol; }
	int getCountEmptyLines() { return count_empty_lines; }
    float getRatio() { return ratio; }
private:
	void setCountTabAndEqualSpace();
	void setCountBraces();
	void setCountSpaces();
	void setCount100Symbol();
	void setCountEmptyLines();
	void setRatio();

	float ratio;
	std::string _str;
	int count_tab;
	int count_equal_space;
	int count_braces;
	int count_spaces;
	int count_100_symbol;
	int count_empty_lines;
};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TEdit *Edit;
	TLabel *Label1;
	TMemo *Memo;
	TButton *Button;
	void __fastcall EditDblClick(TObject *Sender);
	void __fastcall ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
