object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1050#1086#1076#1086#1074#1099#1081' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1100
  ClientHeight = 592
  ClientWidth = 990
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 144
    Top = 25
    Width = 120
    Height = 19
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1082#1086#1076
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 552
    Top = 25
    Width = 121
    Height = 19
    Caption = #1042#1099#1093#1086#1076#1085#1086#1081' '#1082#1086#1076
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 144
    Top = 504
    Width = 136
    Height = 19
    Caption = #1048#1089#1093#1086#1076#1085#1072#1103' '#1087#1072#1087#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 552
    Top = 504
    Width = 140
    Height = 19
    Caption = #1042#1099#1093#1086#1076#1085#1072#1103' '#1087#1072#1087#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object memo_initial: TMemo
    Left = 32
    Top = 50
    Width = 361
    Height = 433
    Lines.Strings = (
      '#include <iostream>'
      'using namespace std;'
      ' '
      'int main() {'
      'int i, j;'
      'for(i=0, j=0; i<10; i++)'#9'{cout<<i; }'
      'int FOR;'
      'int iforex=i;'
      'if(FOR<56, iforex>5){'
      ' sizeof("Hello \'
      'world \'
      '!"),'
      'cout<< "\n" << i,'
      'cout<< FOR;'
      '    }'
      'switch(iforex){'
      '    case 0:'
      'for(i=0, j=0; i<56; i++);'
      '    case 56:'
      '        cout<< FOR;'
      '            cout<< "FOR";'
      '    break;'
      '    default:    '
      '    std::cout << "\nHello World!\n";'
      '}'
      '      return 0;'
      '}')
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object memo_final: TMemo
    Left = 424
    Top = 50
    Width = 361
    Height = 433
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object btn_convert: TButton
    Left = 807
    Top = 50
    Width = 169
    Height = 65
    Caption = #1055#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1100' '#1094#1080#1082#1083#1099' for '#1074' '#1094#1080#1082#1083#1099' while'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    WordWrap = True
    OnClick = btn_convertClick
  end
  object btn_format: TButton
    Left = 807
    Top = 136
    Width = 169
    Height = 65
    Caption = #1054#1090#1092#1086#1088#1084#1072#1090#1080#1088#1086#1074#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = btn_formatClick
  end
  object btn_findIfForSwitch: TButton
    Left = 807
    Top = 224
    Width = 169
    Height = 65
    Caption = #1053#1072#1081#1090#1080' if, for '#1080' switch'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = btn_findIfForSwitchClick
  end
  object initialEdit: TEdit
    Left = 32
    Top = 544
    Width = 361
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Text = 
      'C:\Users\xpewa\OneDrive\'#1056#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083'\'#1059#1095#1077#1073#1072'\'#1089#1077#1084#1077#1089#1090#1088' 6\'#1048#1057#1057#1040#1055#1056'\'#1057#1077#1084#1080 +
      #1085#1072#1088'4'
    OnDblClick = initialEditDblClick
  end
  object finishEdit: TEdit
    Left = 424
    Top = 544
    Width = 361
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    Text = 
      'C:\Users\xpewa\OneDrive\'#1056#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083'\'#1059#1095#1077#1073#1072'\'#1089#1077#1084#1077#1089#1090#1088' 6\'#1048#1057#1057#1040#1055#1056'\'#1057#1077#1084#1080 +
      #1085#1072#1088'4\outputs'
    OnDblClick = finishEditDblClick
  end
  object btn_sem4: TButton
    Left = 807
    Top = 312
    Width = 169
    Height = 65
    Caption = #1053#1072#1081#1090#1080' '#1074#1089#1077' if, for, switch '#1080' '#1091#1073#1088#1072#1090#1100' '#1083#1080#1096#1085#1080#1077' '#1089#1082#1086#1073#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    WordWrap = True
    OnClick = btn_sem4Click
  end
  object OpenDialog1: TOpenDialog
    Title = 'ggg'
    Left = 344
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    Left = 432
    Top = 8
  end
end
