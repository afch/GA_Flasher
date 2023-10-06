object GRA_AND_AFCH_FLASHER: TGRA_AND_AFCH_FLASHER
  Left = 0
  Top = 0
  Margins.Right = 0
  Caption = 'GRA & AFCH Nixie Tubes Clocks / Arduino Flasher v2'
  ClientHeight = 387
  ClientWidth = 485
  Color = clBtnFace
  Constraints.MinHeight = 374
  Constraints.MinWidth = 473
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnCreate = FormCreate
  DesignSize = (
    485
    387)
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 11
    Width = 87
    Height = 13
    Caption = 'Select the port:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 51
    Width = 82
    Height = 13
    Caption = 'Select .HEX file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 88
    Width = 79
    Height = 13
    Caption = 'Select Device:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object HintSpeedButton: TSpeedButton
    Left = 356
    Top = 47
    Width = 23
    Height = 22
    Cursor = crHelp
    Hint = 'Choose only those *.HEX files that do NOT contain Bootloader!'
    Anchors = [akTop, akRight]
    BiDiMode = bdLeftToRight
    Glyph.Data = {
      42040000424D4204000000000000420000002800000020000000100000000100
      10000300000000040000C30E0000C30E00000000000000000000007C0000E003
      00001F000000FF7FFF7FFF7FFF7FF75E4A2900000000000000004A29F75EFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75E4A2900000000000000004A29F75EFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F6B2D00002104AD35524A524AAD35210400006B2D
      FF7FFF7FFF7FFF7FFF7FFF7F6B2D00002104AD35524A524AAD35210400006B2D
      FF7FFF7FFF7FFF7FFF7FC6180000734EFF7FFF7FFF7FFF7FFF7FFF7F734E0000
      C618FF7FFF7FFF7FFF7FC6180000734EFF7FFF7FFF7FFF7FFF7FFF7F734E0000
      C618FF7FFF7FFF7F6B2D00003967FF7FFF7FFF7FAD35AD35FF7FFF7FFF7F3967
      00006B2DFF7FFF7F6B2D00003967FF7FFF7FFF7FAD35AD35FF7FFF7FFF7F3967
      00006B2DFF7F39670000734EFF7FFF7FFF7FFF7F524A524AFF7FFF7FFF7FFF7F
      734E0000396739670000734EFF7FFF7FFF7FFF7F524A524AFF7FFF7FFF7FFF7F
      734E0000396708214208FF7FFF7FFF7FFF7FFF7FB556D65AFF7FFF7FFF7FFF7F
      FF7F4208082108214208FF7FFF7FFF7FFF7FFF7FB556D65AFF7FFF7FFF7FFF7F
      FF7F420808210000AD35FF7FFF7FFF7FFF7FFF7F2104630CFF7FFF7FFF7FFF7F
      FF7FAD3500000000AD35FF7FFF7FFF7FFF7FFF7F2104630CFF7FFF7FFF7FFF7F
      FF7FAD3500000000734EFF7FFF7FFF7FFF7FFF7FCE390000F75EFF7FFF7FFF7F
      FF7F734E00000000734EFF7FFF7FFF7FFF7FFF7FCE390000F75EFF7FFF7FFF7F
      FF7F734E00000000734EFF7FFF7FFF7FFF7FFF7FFF7F082100001863FF7FFF7F
      FF7F734E00000000734EFF7FFF7FFF7FFF7FFF7FFF7F082100001863FF7FFF7F
      FF7F734E00000000AD35FF7FFF7FFF7FEF3D524AFF7FFF7F8410C618FF7FFF7F
      FF7FAD3500000000AD35FF7FFF7FFF7FEF3D524AFF7FFF7F8410C618FF7FFF7F
      FF7FAD35000008214208FF7FFF7FFF7F84100000FF7FFF7F630CC618FF7FFF7F
      FF7F4208082108214208FF7FFF7FFF7F84100000FF7FFF7F630CC618FF7FFF7F
      FF7F4208082139670000734EFF7FFF7F186300008410841000001863FF7FFF7F
      734E0000396739670000734EFF7FFF7F186300008410841000001863FF7FFF7F
      734E00003967FF7F6B2D00003967FF7FFF7F1863082108211863FF7FFF7F3967
      00006B2DFF7FFF7F6B2D00003967FF7FFF7F1863082108211863FF7FFF7F3967
      00006B2DFF7FFF7FFF7FC6180000734EFF7FFF7FFF7FFF7FFF7FFF7F734E0000
      C618FF7FFF7FFF7FFF7FC6180000734EFF7FFF7FFF7FFF7FFF7FFF7F734E0000
      C618FF7FFF7FFF7FFF7FFF7F6B2D00002104AD35734E734EAD35420800006B2D
      FF7FFF7FFF7FFF7FFF7FFF7F6B2D00002104AD35734E734EAD35420800006B2D
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75E4A2900000000000000004A29F75EFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FF75E4A2900000000000000004A29F75EFF7F
      FF7FFF7FFF7F}
    NumGlyphs = 2
    ParentShowHint = False
    ParentBiDiMode = False
    ShowHint = True
    OnClick = HintSpeedButtonClick
  end
  object Image1: TImage
    Left = 199
    Top = 134
    Width = 82
    Height = 48
    Cursor = crHandPoint
    Picture.Data = {
      0A544A504547496D616765FE0A0000FFD8FFE100224578696600004D4D002A00
      000008000101120003000000010001000000000000FFFE003350726F63657373
      65642042792065426179207769746820496D6167654D616769636B2C207A312E
      312E302E207C7C423200FFDB0043000201010201010202020202020202030503
      030303030604040305070607070706070708090B0908080A0807070A0D0A0A0B
      0C0C0C0C07090E0F0D0C0E0B0C0C0CFFDB004301020202030303060303060C08
      07080C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
      0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0CFFC0001108002E0052030122
      00021101031101FFC4001D000003000203010100000000000000000006070800
      040305090201FFC4003210000202010303030303030305000000000102030405
      060711001221081331142241151632235281175161627191B1F0FFC4001B0100
      0105010100000000000000000000000400010305060207FFC4002D1100010302
      0404040701000000000000000102031100040512213106134151072232711461
      8191A1B1C123FFDA000C03010002110311003F00F23E0D3113A7DB0B1FF1D7EC
      DA5C246CFEC95551C9247803FDFAAB313E9EA8A44098C7FE3AD8CE6C5E3A2D3F
      900214E7E965FC7FD0DD141AA1798296527A32C57EC59F1D3EADD3D8CDC4A159
      B293E16EC53C7290AAC5A97BC15A157112ACCAC5BB58BF672A7CF413B23E9632
      1BBB66C642C7D362F4B637917F256ED475234729CA448D2101A53CAB7673FC55
      8FE3A766D07A9DC0EE0365B4D8D0D847CFFE8091477DDED7F41EA44E2575ED75
      28D2C2BDCCC59D4B70A540F3D7DDFDCED35E9DD7218FCF69AB1AA31D9DAB14D5
      2835E92B5192EC6CC226B088397555327C3023BBAE5372DBAB3947A6348FB7BC
      F5ABA7303B96D6DB6A1AAC1235EDA9A9C376BD2C6A5DA0CF57A3948F1B6E2BF0
      1B78FC8632E25DA394AFEE3462682543C3277A38F20302A7903A0FB1B459197C
      FB2C3FC7575EF7697D317374EE53D398FF00D33158EA550474FEAA59D69B4917
      B8F08128EE8BB1D9818F960ADC8EE3D0566F465587156997EC6485D832F82A42
      920823F23A4D04B884B88D94011EC751BD575EDB396AFAEDDDF524C1FA54F57B
      D006E147A07F707E817DA18EB2E46C5711FF005A0A321ED8AD15F96476571C2F
      2C813960A08241315E9B735A9F295A8D0A566EDDB7208A182089A592463F80AA
      093FE3F1D7A01B81B7D8BD270D3DD5B13EE063B557D0D7CB3E47F4658E852B76
      13DB8FB42CE1D44A819964552BE416F2C0117D989A2D03ABDAC45ABF0BB7EF72
      9FE9A99DC83585140CAC0F31FB2ADF7B08CA7DE3B42B93E0F07A643B6EE49428
      109D0C19D7F86887F0CBA69686D6820A84811BC6F151AEAEF48D98D19A8E7C75
      A46668C2CB0CDEDB225A85D43472C7DC0128CA7907E0F9EB517D33DE2BCF1D5C
      3BE4225D4B5F4F0DC2D2BB96B8B1259390C524E8F8E69385FA3EC9628FDA897B
      03AA2164E5C91DA49E42E4C15703F8F5200DAFCC8D8ED41BC871A596D6208DEA
      523E99EEF3F03ACEAA6FD1ABFF0068EB3A7E50A8F39A7549977A69C30E08EB6F
      03A57506E3E9BCD5CC36366BD8FC5D73F57655956188B290ABDCC40673E7845E
      58804F1C0E85B1BBA183C2EB1AA721AD701A3EC634A6452CE4F1A32918F6D83A
      A3566568DC4857B3FABC20EEE49F1C74DA97D6956DC9D6F929A1DEAD39364AE4
      C979A378E1C7D189A648C3CD0472288A40EA8510C7CA47C13C73C7363656E871
      639AA091DE81714A4A65024D448BBDD5EAE9AA1A1D3019DC3CD56DB1B196A134
      71D2BF2CAC0092D318BBDE2080291DFDAAABE07249E89FD59E131C8B85B5AC7F
      5CC4E1102A8B14EB06B11BB8731C8A9215EF4E40E7820F07E7E01E0D59BF7A79
      B29A9A0A580A8D8C7CFA5C4C6A646465991246EE48C2C9ED76C83B89EE07E538
      3F23A727ACEDCDD3591C0E86C9E4932326464B026C7C48D1C91B572AAEF1C85D
      244001F6D79ED3C79E0100F5ECCAF0BF00B7B8B2B5B471C02EB395194AC85280
      CB024441F54988D40D22BB5F1BE28F3A9B97909259000104023AFDE83703BBF5
      B7831B8BBF4AC642E263711570F2DEBEAB1DAC8C95CB832BA827F8ABA460924B
      08B9E49E78F99AECF92C1DCF7A4A0F2FB32A9353BC46DF69E0F0EC58371E0FE3
      90780074E0F417B9585B10EA814F17505DC864C12991C7C17239602584622291
      AA8457F70332A283C83C7C00E6D0BA9B4E6E0E929EA56D298B8B1024742D7EA4
      02E3485072ABED77F0A094657EEE78041407C8C9711708D861D79736760A3919
      53691313A2617A031EA122361DB6A85EC76E2F5D375729014E4A8C7E3F1521CB
      A926C96CC67A7D6F1E90B946AE3055D2B9A82DC2D9B8A7EF291E3A58C377BA80
      CEBC3C7CC6382AFC0009BEC260309573D96CDEA2A194CD56D158D5D49062B1B1
      AC96F2335790246B1860C084799656FB5BEC85B90473D2132FB27A4696E64AB2
      EA1A09A8A7D56B4DF20AD63BCC6D21479FEE1EC7786E7ED2FDDF91CF93D3CFD7
      46D7AE84DBFC2E474BCB96A1157B6B0DDB942E08321076AAFB72444B0E59BB5F
      BC861E58F8E0F008C77C20430FB7676B74926F33A84A568484C7F98920995EC4
      888519001AD2B7E21F3EE2DEE5E64816E329D412644288DB41B8FD9A1FDCED0B
      061B7CEDCF05CC9DE933D84A79C9DB28813251359E5FB2D28F025E7963C7860E
      1801DDC0D33A70B0F83D76DE82F6AE0D779BD5D94D4126772F8E774097F21924
      194B73BF0C0CA4173DA13B8FDC792587F6F4EFDC9F4FF8BD39A72CEA0A363E8B
      0741D69B4576CFBF7325725526086B762AA2850AEF29939E123247961D62B11E
      0FB8C05470E7169739500A9274EFD40DA76A0B16E206B15BE5DEA1253CC8201F
      603A7B54EA74B127E0F59D1EFE8EBFFC3ACEA9A858A4EEBFBDA676E35847ABF2
      AD365E9548254B788832068CB607D3C8913472A8E7B925649382403D9C7E7A52
      DDF54184D21AAF6D751E5B134B5053ABA1E1C5C9472521B2B9311CB6E30B33D7
      95248002C8E57F9168D4F1C1E4F65EA47D3EFEE3B12586C8C8A78F0BC9E3A446
      A8F4F870F511E3BB1920727ED3E7A16E119968540F293DFA823BD4F6CE14A149
      0778FD835C93EB7C165E79679E6A934D6243348F2C4CACEEC7924920F249FF00
      9EB8F1B99A5767B286E40D109D8C29F55DA15485E38048E07CF40194D3926326
      286446E0F1E39EB4E4AAD18E491D482E149DB4F634B940F5A76696DF1D57B0F6
      EDE4B4CEA8D49A70CF344B1BE3F212C42F8ED3C2F70255911C124F9E0F8F04F2
      2C7DA9F533955DAA81AC6BFD4A9F55177D98D9EACC8EEC3EE6E2485883FF0062
      08FC75E67CF94B56A957AD2D99E4AF579F6226909487B8F27B47C0E49E4F1F9E
      BB3877072D571BF4896E45840E3807A76EF1D0A5296B267E64D74F212A4A5294
      8D3E5BD559FE9969FD73BA95B0781CDE6FF6CCC4D8BD3DA68646AB2221208501
      01059557F27EE27C7CF47DEA5B70B51FA80A187A57B33B7B564D37338A9671F4
      ECD3B1312157BA61EEBA3370807207E4F523EC8EBFBB839EC9591DDA407924F4
      2BAC7545FF00DC761D2D4E9DCE5B80E7E7A32DF8D31817A857C42E591E424C94
      F4D26634AD762DC3783B7C3D6F7B6E097DC52B383E98E91007F4FD34ABC7D248
      D45B337B51E4619B4E6A4CDE7224AEC92E5EC4213B5FB848488994F2C5B95E01
      00900F445B87EA7F3FBA3BA1B4FA77334F0D8B8F4FD69F2562AE2F20D663B16E
      78A48DEC4818065664687B1587845F07A8536237F725B75AEF1D6AC4F6ACD416
      E169D15B9664EF1DC07240E78FF9E9A5B43AAA2D69EABB2799AE278E261042AB
      2801F98E08E227C123E50F1E7E38EA2C5388311C4B10CF78E15E704A89804905
      206D1D3E558E6AC986ADCAD09850200F6833576AC20A8F1D675A95EE13027CFF
      0011FF00AEB3A542EBDEBFFFD9}
    OnClick = Image1Click
  end
  object FlashButton: TButton
    Left = 287
    Top = 118
    Width = 185
    Height = 87
    Hint = 'Choose only those *.HEX files that do NOT contain Bootloader!'
    Align = alCustom
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Upload FLASH (Firmware) to Device'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = FlashButtonClick
    ExplicitWidth = 181
  end
  object COMPortComboBox: TComboBox
    Left = 101
    Top = 8
    Width = 180
    Height = 21
    Align = alCustom
    Style = csDropDownList
    Anchors = [akLeft, akTop, akRight]
    Sorted = True
    TabOrder = 3
    ExplicitWidth = 176
  end
  object SearchPortBitBtn: TBitBtn
    Left = 287
    Top = 6
    Width = 186
    Height = 25
    Align = alCustom
    Anchors = [akTop, akRight]
    Caption = 'Search for available ports'
    TabOrder = 4
    OnClick = SearchPortBitBtnClick
    ExplicitLeft = 283
  end
  object OpenFileEdit: TEdit
    Left = 101
    Top = 48
    Width = 255
    Height = 21
    Hint = 'Choose only those *.HEX files that do NOT contain Bootloader!'
    Align = alCustom
    Anchors = [akLeft, akTop, akRight]
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    ExplicitWidth = 251
  end
  object OpenHEXBitBtn: TBitBtn
    Left = 385
    Top = 47
    Width = 88
    Height = 23
    Align = alCustom
    Anchors = [akTop, akRight]
    Caption = 'Open *.HEX File'
    TabOrder = 0
    OnClick = OpenHEXBitBtnClick
    ExplicitLeft = 381
  end
  object DevicesComboBox: TComboBox
    Left = 100
    Top = 85
    Width = 372
    Height = 21
    Align = alCustom
    Style = csDropDownList
    Anchors = [akLeft, akTop, akRight]
    ItemIndex = 3
    TabOrder = 1
    Text = 'Arduino Shield NCS314 / NCS312 - Arduino UNO (Atmega328p)'
    Items.Strings = (
      'MCU 105 (Atmega328p)'
      'MCU 107 (Atmega328p)'
      'MCU 109 (Atmega328p)'
      'Arduino Shield NCS314 / NCS312 - Arduino UNO (Atmega328p)'
      'Arduino Shield NCS314 / NCS312 - Arduino Mega 2560 (Atmega2560)')
    ExplicitWidth = 368
  end
  object Memo1: TMemo
    Left = 0
    Top = 220
    Width = 488
    Height = 169
    Margins.Right = 0
    TabStop = False
    Align = alCustom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Cascadia Mono'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 6
    ExplicitWidth = 484
    ExplicitHeight = 168
  end
  object LinkLabel1: TLinkLabel
    Left = 209
    Top = 188
    Width = 72
    Height = 17
    Caption = '<a href="http://www.gra-afch.com">GRA && AFCH</a>'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = LinkLabel1Click
  end
  object ReadFlashButton: TButton
    Left = 8
    Top = 118
    Width = 185
    Height = 25
    Caption = 'Backup FLASH (Firmware) to File'
    TabOrder = 8
    OnClick = ReadFlashButtonClick
  end
  object ReadEEPROMButton: TButton
    Left = 8
    Top = 149
    Width = 185
    Height = 25
    Caption = 'Backup EEPROM (Settings) to File'
    TabOrder = 9
    OnClick = ReadEEPROMButtonClick
  end
  object WriteEEPROMButton: TButton
    Left = 8
    Top = 180
    Width = 185
    Height = 25
    Caption = 'Upload EEPROM (Settings) to Device'
    TabOrder = 10
    OnClick = WriteEEPROMButtonClick
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '.hex'
    Filter = 'Arduinno compiled sketch or EEPROM|*.hex;*.epp'
    Left = 27
    Top = 223
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 91
    Top = 226
  end
  object SaveDialog1: TSaveDialog
    FileName = 'backup.hex'
    Filter = 'FLASH or EEPROM Files|*.hex; *.epp'
    Left = 145
    Top = 225
  end
end
