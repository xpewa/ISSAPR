//---------------------------------------------------------------------------

#ifndef Sem_1H
#define Sem_1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>

#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
//---------------------------------------------------------------------------

class SuperCodeEditor {
public:
	SuperCodeEditor() : _string("") {}
	SuperCodeEditor(std::string string) : _string(string) {}
	~SuperCodeEditor() = default;

	void replaceForWithWhile();
	void formatString();
	std::string getString();
private:
	//std::string doLengthLimitForString();
	void trim();
	void doEnters();
	void doTabs();
	void delete_extra_curly_braces();

	std::string _string;
};

class Instruction {
public:
	std::string print();
    void setHead(std::string initial_string);
	void setBody(std::string initial_string);

protected:
	std::string instruction;
	std::string head;
	std::string body;
};

class If : public Instruction {
public:
	If(std::string str);
	~If() = default;
};

class For : public Instruction {
public:
	For(std::string str);
	~For() = default;
};

class Switch : public Instruction {
public:
	Switch(std::string str);
	~Switch() = default;
};


struct Node {
	Instruction *instruction;
	Node *next, *prev;
};

class List {
public:
	List();
	~List();
	void add(Instruction *instruction);
	//void add(NodeEntry *file);
	Instruction* getData(int number);
private:
	Node *head, *tail;
};

class NodeEntry {
	FileEntry *fileEntry;
	NodeEntry *next, *prev;
}

class FileEntry {
	std::string fileName;
	unsigned fileSize;
};



class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *memo_initial;
	TMemo *memo_final;
	TLabel *Label1;
	TLabel *Label2;
	TButton *btn_convert;
	TButton *btn_format;
	TButton *btn_findIfForSwitch;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TEdit *initialEdit;
	TEdit *finishEdit;
	TLabel *Label3;
	TLabel *Label4;
	TButton *btn_sem4;
	void __fastcall btn_convertClick(TObject *Sender);
	void __fastcall btn_formatClick(TObject *Sender);
	void __fastcall btn_findIfForSwitchClick(TObject *Sender);
	void __fastcall initialEditDblClick(TObject *Sender);
	void __fastcall finishEditDblClick(TObject *Sender);
	void __fastcall btn_sem4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
