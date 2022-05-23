//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const std::string ENTER = "\r\n";
//---------------------------------------------------------------------------

InspectorQuality::InspectorQuality(std::string str) {
	_str = str;
	ratio = 0.0;
	count_tab = 0;
	count_equal_space = 0;
	count_braces = 0;
	count_spaces = 0;
	count_100_symbol = 0;
	count_empty_lines = 0;
}

void InspectorQuality::checkAllParametrs() {
	setCountTabAndEqualSpace();
	setCountBraces();
	setCountSpaces();
	setCount100Symbol();
	setCountEmptyLines();
    setRatio();
}

void InspectorQuality::setCountTabAndEqualSpace() {
	int count_open_bracket = 0;
	int count_additional = 0; //for, while, if, do без {}
	int count_colon = 0;
	int count_before = 0; //сколько табуляций должно было быть в предыдущей строке
	int count_space_before = 0; //сколько пробелов было в предыдущей строке
	int count_space_now = 0;
	int pos = 0;

	int tabs[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int count_space_int_tab = 0;

	while (pos <= _str.size()) {
		if (_str[pos] == '}' && _str[pos-1] != '\n') {
			--count_open_bracket;
		}

		if ((((_str.substr(pos, 4)).find("case") != std::string::npos) ||
			((_str.substr(pos, 7)).find("default") != std::string::npos))) {
			count_colon += 1;
		}

		if (((_str.substr(pos, 3)).find("for") != std::string::npos ||
			(_str.substr(pos, 4)).find("while") != std::string::npos ||
			((_str.substr(pos, 2)).find("if") != std::string::npos) ||
			((_str.substr(pos, 2)).find("do") != std::string::npos))) {
			count_additional += 1;
		}

		if (_str[pos-1] == '\n') {
			count_space_now = 0;

            int pos_enter = _str.find(ENTER, pos);
			if (pos_enter != std::string::npos) {
				std::string buf = _str.substr(pos, pos_enter-pos);
				if (buf.length() == 0) {
                	++pos;
					continue;
				}
			}

			while(_str[pos] == ' ') {
				++count_space_now;
                ++pos;
			}

			if (_str[pos] == '}') {
            	++pos;
				--count_open_bracket;
			}

			if (count_space_now < count_open_bracket + count_additional + count_colon) {
				++count_tab;
			}
			else {
				if (count_open_bracket + count_additional + count_colon > count_before &&
				count_space_now <= count_space_before) {
                    ++count_tab;
				}
				else {
					if (count_open_bracket + count_additional + count_colon != 0) {
                        count_space_int_tab = int(count_space_now / (count_open_bracket + count_additional + count_colon));
						if (count_space_int_tab < 10) {
							++tabs[count_space_int_tab];
						}
						else {
							++tabs[9];
						}
					}
				}
			}
			count_before = count_open_bracket + count_additional + count_colon;
			count_space_before = count_space_now;
		}

		if (_str[pos] == ';') {
			count_additional = 0;
		}

		if ((_str.substr(pos, 5)).find("break") != std::string::npos) {
			count_colon = 0;
		}

        if (_str[pos] == '{') {
			++count_open_bracket;
			count_additional = 0;
		}

		++pos;
	}

	int max = tabs[0];
	int max_i = 0;
	for (int i=1; i < 10; ++i) {
		if (tabs[i] > max) {
			max = tabs[i];
			max_i = i;
		}
	}

	tabs[max_i] = 0;

	for (int i=1; i < 10; ++i) {
        count_equal_space += tabs[i];
	}
}

void InspectorQuality::setCountBraces() {
    int pos = 0;
	while (pos != _str.size()-1) {
		if ((_str[pos] == '{' || _str[pos] == '}') &&
			((_str[pos+1] != ' ' && _str.find(ENTER, pos) != pos + 1) ||
			(_str[pos-1] != ' ' && _str.find(ENTER, pos-3) > pos))) {
			++count_braces;
        }

		++pos;
	}
}

void InspectorQuality::setCountSpaces() {
	std::string operands = "+=*/%++--==><>=<=&&||!>><<^~+=-=<<=>>=^=!=";
    int pos = 0;
	while (pos != _str.size()-1) {
		if (operands.find(_str.substr(pos, 2)) != std::string::npos) {
			if ((_str[pos+2] != ' ' && _str.find(ENTER, pos) != pos + 2) ||
				(_str[pos-1] != ' ' && _str.find(ENTER, pos-3) > pos)) {
					++count_spaces;
			}
			pos += 2;
			continue;
		}
		if (operands.find(_str[pos]) != std::string::npos) {
			if ((_str[pos+1] != ' ' && _str.find(ENTER, pos) != pos + 1) ||
				(_str[pos-1] != ' ' && _str.find(ENTER, pos-3) > pos)) {
					++count_spaces;
			}
		}

		++pos;
	}
}

void InspectorQuality::setCount100Symbol() {
	std::string buf = " ";
	int pos = 0;
	int pos_enter = _str.find(ENTER, pos);
	while (pos_enter != std::string::npos) {
		buf = _str.substr(pos, pos_enter-pos);
		if (buf.length() > 100) {
			count_100_symbol += buf.length() / 100;
        }
		pos = pos_enter + ENTER.length();
		pos_enter = _str.find(ENTER, pos);
	}
}

void InspectorQuality::setCountEmptyLines() {
	int pos = 0;
	while (pos != _str.size()-1) {
		if (_str[pos] == '}') {
			int pos_enter = _str.find(ENTER, pos);
			if (pos_enter != pos+1) {
				++count_empty_lines;
                ++pos;
                continue;
			}
			if (_str.find(ENTER, pos_enter+1) >= pos_enter+ENTER.length()+1) {
				++count_empty_lines;
            }
        }

		++pos;
    }
}

void InspectorQuality::setRatio() {
    if (count_tab + count_equal_space + count_braces + count_spaces +
		count_100_symbol + count_empty_lines != 0) {
		ratio = _str.length() / (count_tab + count_equal_space + count_braces + count_spaces +
		count_100_symbol + count_empty_lines);
	}
	else {
        ratio = _str.length();
    }
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditDblClick(TObject *Sender)
{
    AnsiString txt = "";
	if (OpenDialog1->Execute()) {
		txt = OpenDialog1->FileName;
		Edit->Text = txt;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ButtonClick(TObject *Sender)
{
    AnsiString path_ansi = Edit->Text;
	std::string path = path_ansi.c_str();
	ifstream fin(path);
	std::string str;
	std::string buf;
	while (getline(fin, buf)) {
		str += buf + ENTER;
	}
	fin.close();

	InspectorQuality inspector(str);
    inspector.checkAllParametrs();

	str = "";
	str += "Коэффициент отношения ошибок к количеству байт = " +
			std::to_string(inspector.getRatio()) + ENTER + ENTER;
	str += "Таблица распределения ошибок:" + ENTER;
	str += "-------------------------------------------------------------------------------------------" + ENTER;

	str += "| Число нарушений табуляции                                                             | " +
			std::to_string(inspector.getCountTab()) + " |" + ENTER;
	str += "| Число неравного количества пробелов в табуляциях | " +
			std::to_string(inspector.getCountEqualSpace()) + " |" + ENTER;
	str += "| Число неотделённых пробелом фигурных скобок          | " +
			std::to_string(inspector.getCountBraces()) + " |" + ENTER;
	str += "| Число неотделённых пробелом операндов                          | " +
			std::to_string(inspector.getCountSpaces()) + " |" + ENTER;
	str += "| Число строк длиннее 100 символов                                               | " +
			std::to_string(inspector.getCount100Symbol()) + " |" + ENTER;
	str += "| Число отсутствия свободных строк                                              | " +
			std::to_string(inspector.getCountEmptyLines()) + " |" + ENTER;

    str += "-------------------------------------------------------------------------------------------" + ENTER;

    AnsiString finish_string = str.c_str();
	Memo->Text = finish_string;
}
//---------------------------------------------------------------------------


