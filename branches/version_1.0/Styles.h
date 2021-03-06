﻿/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include "precompiled.h"

#ifndef __Styles_H
#define __Styles_H

#include "utilities/XmlUtil.h"


class PaddingStyle {
 
public:

  int Left;
  int Right;
  int Bottom;
  int Top;
  int Width;
  int Height;
  void FromRect(const wxRect& rect);

};

class MainPanelStyle { public:
  PaddingStyle Padding;
  wxRect ScaleGrid;
};

class InnerPanelStyle { public:
  PaddingStyle Padding;
  wxRect ScaleGrid;
};

class OptionPanelStyle { public:
  PaddingStyle Padding;
  int ArrowButtonWidth;
  wxRect ArrowButtonScaleGrid;
  wxRect ScaleGrid;
  int ButtonHGap;
  int ButtonVGap;
  wxPoint ButtonDownIconOffset;
  wxColour ButtonIconColor;
};

class IconStyle { public:
  PaddingStyle Padding;
};

struct SkinMetadata {
  wxString Name;
  wxString CompatibleVersion;
  wxString Author;
};


class Styles {

public:

  static MainPanelStyle MainPanel;
  static InnerPanelStyle InnerPanel;
  static IconStyle Icon;
  static OptionPanelStyle OptionPanel;

  static void GetSkinMetadata(TiXmlElement* skinDocumentRoot, SkinMetadata& skinMetadata);
  static void GetSkinMetadata(const wxString& filePath, SkinMetadata& skinMetadata);
  static void LoadSkinFile(const wxString& filePath);
  static bool IsSkinVersionCompatible(const wxString& skinVersion);

};

#endif // __Styles_H