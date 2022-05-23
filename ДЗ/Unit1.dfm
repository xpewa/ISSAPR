object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 544
  ClientWidth = 818
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 29
    Width = 183
    Height = 19
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1072#1076#1088#1077#1089' '#1092#1072#1081#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit: TEdit
    Left = 16
    Top = 67
    Width = 777
    Height = 21
    TabOrder = 0
    Text = 'D:\test.txt'
    OnDblClick = EditDblClick
  end
  object Memo: TMemo
    Left = 16
    Top = 111
    Width = 777
    Height = 409
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Dubai'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Button: TButton
    Left = 560
    Top = 8
    Width = 233
    Height = 53
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonClick
  end
  object OpenDialog1: TOpenDialog
    Left = 280
    Top = 16
  end
end
