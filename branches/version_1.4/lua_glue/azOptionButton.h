/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include "../stdafx.h"

#ifndef __azOptionButton_H
#define __azOptionButton_H


#include "../OptionButton.h"

#include "azGlobal.h"
#include "azWrapper.h"


class azOptionButton : public azWrapper {

public:

  azOptionButton(OptionButton* button) { buttonId_ = button->GetId(); }
  azOptionButton(lua_State *L);

  int addEventListener(lua_State *L);
  int getToolTip(lua_State *L);
  int setToolTip(lua_State *L);
  int getName(lua_State *L);
  int setName(lua_State *L);
  int getIconFile(lua_State *L);
  int setIconFile(lua_State *L);
  int popupMenu(lua_State *L);
  
  static const char className[];
  static Lunar<azOptionButton>::RegType methods[];

  void OnMenuClick(wxCommandEvent& evt);
  OptionButton* Get() const;

private:

  int buttonId_;

};


#endif // __azOptionButton_H