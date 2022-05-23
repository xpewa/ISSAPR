//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sem_1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const std::string TAB = "    ";
const std::string ENTER = "\r\n";
const std::string ERROR_CONVERT = "Sorry, failed to convert";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

std::string SuperCodeEditor::getString() {
	return _string;
}


void SuperCodeEditor::replaceForWithWhile() {
/*
	std::string finish_string = "";
	std::string string = _string;
	int pos_for = string.find(" for");

	while (pos_for > -1) {
		//сохраняем данные до первого for
		finish_string += string.substr(0, pos_for-1);
		string = string.erase(0, pos_for-1);

		//выделяем инструкции, объявляемые до while (1)
		int pos_bracket = string.find("(");
		int pos_point_with_comma = string.find(";");
		if (!pos_bracket || !pos_point_with_comma) {
			return ERROR_CONVERT;
		}
		std::string instruction_1 = string.substr(pos_bracket + 1,
										pos_point_with_comma - pos_bracket);

		string = string.erase(0, pos_point_with_comma);

		//выделяем инструкции, условия while (2)
		pos_point_with_comma = string.find(";");
		std::string instruction_2 = string.substr(0, pos_point_with_comma-1);
		string = string.erase(0, pos_point_with_comma);

		//выделяем инструкции в теле while (3)
		pos_bracket = string.find(")");
		if (!pos_bracket) {
			return ERROR_CONVERT;
		}
		std::string instruction_3 = string.substr(0, pos_bracket-1) + ";";
		string = string.erase(0, pos_bracket);

		//записываем в виде цикла while
		finish_string += ENTER + ENTER + TAB + instruction_1 + ENTER;
		finish_string += TAB + "while (" + instruction_2 + ") {" + ENTER;

		pos_point_with_comma = string.find(";");
		pos_bracket = string.find("{");
		if (!pos_bracket && !pos_point_with_comma) {
			return ERROR_CONVERT;
		}
		//если есть {}
		if (pos_bracket < pos_point_with_comma && pos_bracket > 0) {
			string = string.erase(0, pos_bracket+1);
			pos_bracket = string.find("}");
			finish_string += string.substr(0, pos_bracket-1);

			finish_string += TAB + TAB + instruction_3 + ENTER + TAB + "}";

			string = string.erase(0, pos_bracket);
		}
		//если цикл без тела
		else if (pos_point_with_comma == 1) {
			finish_string += TAB + TAB + instruction_3 + ENTER + TAB + "}";

			string = string.erase(0, pos_point_with_comma);
		}
		//цикл с одним выражение в теле без {}
		else {
			finish_string += TAB + TAB + string.substr(0, pos_point_with_comma)
							+ ENTER;
			finish_string += TAB + TAB + instruction_3 + ENTER + TAB + "}";

			string = string.erase(0, pos_point_with_comma);
		}

		pos_for = string.find(" for");
	}
	finish_string += string;
	return finish_string;
	*/
}

/*
std::string SuperCodeEditor::doLengthLimitForString() {
	std::string string = _string;

	size_t n = 0;
	while (n >= 0 && n < string.size()) {
		size_t n_next = string.find(ENTER, n);
		if (n_next < 0) {
			n_next = string.size() - 1 ;
		}

		std::string now_str = string.substr(n, n_next - n);
		if (now_str.size() > 80) {
			if ()
		}
	}

	_string = string;
}
*/

// Семинар 2

void SuperCodeEditor::trim() {
	std::string string = _string;
	std::string res_string = "";
	int pos_enter = string.find(ENTER);
	while (pos_enter != std::string::npos) {
		int i = 1;
		while (string[i] == ' ' || string[i] == '\t') {
			string = string.erase(1, 1);
		}

		res_string += string.substr(0, string.find(ENTER)+1);
		string = string.erase(0, string.find(ENTER)+1);

		pos_enter = string.find(ENTER);
	}
	_string = res_string;
}

void SuperCodeEditor::doEnters() {
	int count_open_bracket = 0; //открывающаяся скобка
	bool count_quote = false; //кавычка
	bool is_multiline_comment = false; //многострочный комментарий
	bool is_singleline_comment = false; //комментарий
	int pos = 0;
	std::string string = _string;

	while (pos != string.size()-1) {
		if (string[pos] == '"') {
			count_quote = !count_quote;
        }
		if (string[pos] == '/' && string[pos+1] == '*') {
			is_multiline_comment = true;
		}
		if (string[pos] == '*' && string[pos+1] == '/') {
			is_multiline_comment = false;
		}
		if (string[pos] == '/' && string[pos+1] == '/') {
			is_singleline_comment = true;
		}
		if ((string.substr(pos, 2)).find(ENTER) != std::string::npos) {
			is_singleline_comment = false;
		}
		if (!is_multiline_comment && !is_singleline_comment) {
            if (string[pos] == '(')
				++count_open_bracket;
			if (string[pos] == ')')
				--count_open_bracket;

			//enter после ;
			if (string[pos] == ';' &&
			(string.find(ENTER, pos+1) > string.find_first_not_of(ENTER + " ", pos+1))) {
				if (!count_open_bracket) {
					while (string[pos+1] == ' ') {
                        ++pos;
                    }
					string.insert(string.find_first_not_of(ENTER + " ,", pos+1), ENTER);
				}
				if (count_open_bracket) {
					if (string.find(')', pos) > string.find(ENTER, pos)) {
						string.erase(string.find(ENTER, pos), ENTER.size());
					}
				}
			}

			if (string[pos] == ';' &&
			(string.find(ENTER, pos+1) < string.find_first_not_of(ENTER + " ", pos+1)) &&
			count_open_bracket) {
				string.erase(string.find(ENTER, pos+1), ENTER.size());
			}

			if ((count_quote) && (string[pos] == '\\') &&
			(string.find(ENTER, pos+1) < string.find_first_not_of(ENTER + " ", pos+1))) {
				string.erase(pos, ENTER.size() + 1);
            }

			//enter после {
			if (string[pos] == '{' &&
			((string.substr(pos - ENTER.size(), 2)).find(ENTER) != std::string::npos)) {
				string.erase(pos - ENTER.size(), ENTER.size());
				pos -= 2;
			}
			if (string[pos] == '{' &&
			(string.find(ENTER, pos+1) > string.find_first_not_of(ENTER + " ", pos+1))) {
				string.insert(string.find_first_not_of(ENTER + " ,", pos+1), ENTER);
			}
			if (string[pos] == ')' &&
			(string.find(';', pos+1) > string.find_first_not_of('{', pos+1)) &&
			(string.find(ENTER, pos+1) > string.find_first_not_of(ENTER + " ,", pos+1))) {
				string.insert(string.find_first_not_of(ENTER + " ,", pos+1), ENTER);
            }
		}
		++pos;
	}

	_string = string;
}

void SuperCodeEditor::doTabs() {
	std::string string = _string;
	int count_open_bracket = 0;
	int count_additional = 0; //for, while, if, do без {}
	int pos = 0;
	int count_colon = 0;

	while (pos <= string.size()) {
		if (string[pos] == '{') {
			++count_open_bracket;
			count_additional = 0;
		}

		if ((((string.substr(pos, 4)).find("case") != std::string::npos) ||
			((string.substr(pos, 7)).find("default") != std::string::npos)) &&
			(string.find_first_of(ENTER, pos - ENTER.size()) == pos - ENTER.size())) {
			count_colon = 1;
            for (int i = 0; i < count_open_bracket + count_additional; ++i) {
				string.insert(pos, TAB);
			}
            while (string[pos] != ':') {
				++pos;
			}
		}

		if (((string.substr(pos, 3)).find("for") != std::string::npos ||
			(string.substr(pos, 4)).find("while") != std::string::npos ||
			((string.substr(pos, 2)).find("if") != std::string::npos) ||
			((string.substr(pos, 2)).find("do") != std::string::npos)) &&
			(string.find_first_of(ENTER, pos - ENTER.size()) == pos - ENTER.size())) {
			for (int i = 0; i < count_open_bracket + count_additional + count_colon; ++i) {
				string.insert(pos, TAB);
			}
			count_additional += 1;
            while (string[pos] != ')') {
				++pos;
			}
		}

		if (string[pos-1] == '\n') {
			if (string[pos] == '}') {
				--count_open_bracket;
				for (int i = 0; i < count_open_bracket + count_additional - 1; ++i) {
					string.insert(pos, TAB);
				}
			}
			else {
                for (int i = 0; i < count_open_bracket + count_additional + count_colon; ++i) {
					string.insert(pos, TAB);
				}
			}
		}

		if (string[pos] == ';') {
			count_additional = 0;
		}

        if ((string.substr(pos, 5)).find("break") != std::string::npos &&
		string.find_first_of(ENTER, pos - ENTER.size()) == pos - ENTER.size()) {
			count_colon = 0;
		}

		++pos;
	}

	_string = string;
}

void SuperCodeEditor::delete_extra_curly_braces() {
	std::string string = _string;
	bool open_bracket = false; //открытая скобка
	bool is_quote = false; //кавычка
	bool is_multiline_comment = false; //многострочный комментарий
	bool is_singleline_comment = false; //комментарий
	int count_point_with_comma = 0;
	int pos_open_bracket = 0;
	int pos = 0;

	while (pos != string.size()-1) {
		if (string[pos] == '"') {
			is_quote = !is_quote;
		}
		if (string[pos] == '/' && string[pos+1] == '*') {
			is_multiline_comment = true;
		}
		if (string[pos] == '*' && string[pos+1] == '/') {
			is_multiline_comment = false;
		}
		if (string[pos] == '/' && string[pos+1] == '/') {
			is_singleline_comment = true;
		}
		if ((string.substr(pos, 2)).find(ENTER) != std::string::npos) {
			is_singleline_comment = false;
		}
		if (!is_multiline_comment && !is_singleline_comment && !is_quote) {
			if (string[pos] == '{') {
				open_bracket = true;
				count_point_with_comma = 0;
				pos_open_bracket = pos;
			}
			if (string[pos] == '}') {
				open_bracket = false;
				if (count_point_with_comma == 1) {
					string.erase(pos, 1);
					string.erase(pos_open_bracket, 1);
                }
			}
			if (open_bracket && string[pos] == ';') {
				++count_point_with_comma;
            }
		}
		++pos;
	}
    _string = string;
}


void SuperCodeEditor::formatString() {
	trim();
	doEnters();
	doTabs();
    delete_extra_curly_braces();
}

// Семинар 3

void Instruction::setHead(std::string initial_string) {
    int pos_instruction = initial_string.find(ENTER + instruction);
	if (pos_instruction != -1) {
		int pos_close_bracket = initial_string.find(')', pos_instruction);
		if (pos_close_bracket != -1) {
			head = initial_string.substr(pos_instruction,
					pos_close_bracket - pos_instruction + 1);
		}
	}
}

void Instruction::setBody(std::string initial_string) {
	int pos_instruction = initial_string.find(ENTER + instruction);
	if (pos_instruction != -1) {
		int pos_close_bracket = initial_string.find(')', pos_instruction);
		if (pos_close_bracket != -1) {
			int pos_open_bracket = initial_string.find('{', pos_close_bracket);
			int pos_point_with_comma = initial_string.find(';', pos_close_bracket);
			if (pos_open_bracket < pos_point_with_comma && pos_open_bracket != -1) {
				pos_close_bracket = initial_string.find('}', pos_open_bracket);
				if (pos_close_bracket != -1) {
					body = initial_string.substr(pos_open_bracket,
					pos_close_bracket - pos_open_bracket + 1);
				}
			}
			else {
				body = initial_string.substr(pos_close_bracket + 1,
					pos_point_with_comma - pos_close_bracket + 1);
            }
		}
	}
}

If::If(std::string str) {
	instruction = "if";
	setHead(str);
	setBody(str);
}

For::For(std::string str) {
	instruction = "for";
	setHead(str);
	setBody(str);
}

Switch::Switch(std::string str) {
    instruction = "switch";
    setHead(str);
	setBody(str);
}

std::string Instruction::print() {
	return "//Инструкция " + instruction + head + ENTER + body + ENTER + ENTER;
}


List::List() {
	head = nullptr;
    tail = nullptr;
}

List::~List() {
	while(head) {
		tail = head->next;
		delete head->instruction;
		delete head;
        head = tail;
    }
}

void List::add(Instruction *instruction) {
	Node *tmp = new Node;
	tmp->next = nullptr;
	tmp->instruction = instruction;

	if (!head) {
		tmp->prev = nullptr;
		head = tail = tmp;
	}
	else {
		tmp->prev = tail;
		tail->next = tmp;
        tail = tmp;
    }
}

Instruction* List::getData(int number) {
	Node *tmp = head;
	int i = 0;
	while (i < number && tmp->next) {
		tmp = tmp->next;
        ++i;
	}
	if (tmp && i == number) {
		return tmp->instruction;
	}
	else {
		return nullptr;
    }
}


void __fastcall TForm1::btn_convertClick(TObject *Sender) {
	AnsiString initial_string = memo_initial->Text;
	std::string s = initial_string.c_str();
	SuperCodeEditor code(s);
	code.replaceForWithWhile();
	s = code.getString();
	AnsiString finish_string = s.c_str();
	memo_final->Text = finish_string;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_formatClick(TObject *Sender) {
	AnsiString initial_string = memo_initial->Text;
	std::string s = initial_string.c_str();
	SuperCodeEditor code(s);
	code.formatString();
	s = code.getString();
	AnsiString finish_string = s.c_str();
	memo_final->Text = finish_string;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_findIfForSwitchClick(TObject *Sender)
{
    AnsiString initial_string = memo_initial->Text;
	std::string s = initial_string.c_str();
	For _for(s);
	std::string res = _for.print();
	If _if(s);
	res += _if.print();
	Switch _switch(s);
	res += _switch.print();
	SuperCodeEditor code(res);
	code.formatString();
	res = code.getString();
	AnsiString finish_string = res.c_str();
	memo_final->Text = finish_string;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::initialEditDblClick(TObject *Sender)
{
	AnsiString txt = "";
	if (OpenDialog1->Execute()) {
		txt = OpenDialog1->FileName;
		initialEdit->Text = txt;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::finishEditDblClick(TObject *Sender)
{
	AnsiString txt = "";
	if (SaveDialog1->Execute()) {
		txt = SaveDialog1->FileName;
		finishEdit->Text = txt;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::btn_sem4Click(TObject *Sender)
{
	AnsiString path_ansi = initialEdit->Text;
	std::string path = path_ansi.c_str();
	int number_output = 1;
	for (const auto & entry : fs::directory_iterator(path)) {
		ifstream fin(entry.path());
		std::string str;
		std::string buf;
		while (getline(fin, buf)) {
			str += buf + ENTER;
		}
		fin.close();

		List global_list;
		std::size_t pos_if = str.find(ENTER + "if");
		std::size_t pos_for = str.find(ENTER + "for");
		std::size_t pos_switch = str.find(ENTER + "switch");
		while (pos_if !=std::string::npos || pos_for !=std::string::npos || pos_switch !=std::string::npos) {
			if (pos_if && pos_if < pos_for && pos_if < pos_switch) {
				If *_if = new If(str);
				global_list.add(_if);
				str.erase(0, pos_if + 4);
			}
			if (pos_for && pos_for < pos_if && pos_for < pos_switch) {
				For *_for = new For(str);
				global_list.add(_for);
				str.erase(0, pos_for + 5);
			}
			if (pos_switch && pos_switch < pos_for && pos_switch < pos_if) {
				Switch *_switch = new Switch(str);
				global_list.add(_switch);
				str.erase(0, pos_switch + 9);
			}
			pos_if = str.find(ENTER + "if");
			pos_for = str.find(ENTER + "for");
			pos_switch = str.find(ENTER + "switch");
		}

		AnsiString out_file_ansi = finishEdit->Text + "\\output" + number_output + ".txt";
		std::string out_file = out_file_ansi.c_str();
		ofstream fout(out_file, ios::app);
		int i = 0;
		while(global_list.getData(i)) {
			SuperCodeEditor code(global_list.getData(i)->print());
			code.formatString();
			fout << code.getString();
			++i;
		}
		fout.close();
		++number_output;
	}
}
//---------------------------------------------------------------------------


