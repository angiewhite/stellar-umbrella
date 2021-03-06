object PostfixExpressions: TPostfixExpressions
  Left = 0
  Top = 0
  Caption = 'PostfixExpressions'
  ClientHeight = 250
  ClientWidth = 731
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 258
    Top = 43
    Width = 97
    Height = 14
    Caption = 'Infix Expression'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 243
    Top = 97
    Width = 112
    Height = 14
    Caption = 'Postfix Expression'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 395
    Top = 189
    Width = 39
    Height = 14
    Caption = 'Result'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Infix: TEdit
    Left = 368
    Top = 33
    Width = 201
    Height = 21
    TabOrder = 0
  end
  object Postfix: TEdit
    Left = 368
    Top = 87
    Width = 201
    Height = 21
    TabOrder = 1
  end
  object Translate: TButton
    Left = 616
    Top = 31
    Width = 75
    Height = 25
    Caption = 'Translate'
    TabOrder = 2
    OnClick = TranslateClick
  end
  object Calculate: TButton
    Left = 616
    Top = 85
    Width = 75
    Height = 25
    Caption = 'Calculate'
    TabOrder = 3
    OnClick = CalculateClick
  end
  object Result: TPanel
    Left = 496
    Top = 162
    Width = 185
    Height = 41
    TabOrder = 4
  end
  object Operands: TStringGrid
    Left = 40
    Top = 31
    Width = 137
    Height = 162
    ColCount = 2
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ScrollBars = ssVertical
    TabOrder = 5
  end
end
