#include "OptionPanel.h"
#include "Controller.h"
#include "FilePaths.h"
#include "Styles.h"
#include "MainFrame.h"
#include "Localization.h"


extern Controller gController;
extern MainFrame* gMainFrame;


OptionPanel::OptionPanel(wxWindow *owner, int id, wxPoint point, wxSize size):
NineSlicesPanel(owner, id, point, size) {
  configDialog_ = NULL;

  LoadImage(FilePaths::SkinDirectory + _T("/OptionPanel.png"));

  wxStringList buttonNames;
  buttonNames.Add(_T("Close"));
  buttonNames.Add(_T("Minimize"));
  buttonNames.Add(_T("Eject"));
  //buttonNames.Add(_T("AddShortcut"));
  buttonNames.Add(_T("Config"));
  //buttonNames.Add(_T("Help"));
  //buttonNames.Add(_T("Key"));
  buttonNames.Add(_T("MultiLaunch"));

  for (int i = 0; i < buttonNames.size(); i++) {
    OptionButton* button = new OptionButton(this, wxID_ANY);
    wxString n = buttonNames[i];
    button->SetName(n);
    button->SetIcon(new wxBitmap(FilePaths::IconsDirectory + _T("/ButtonIcon_") + n + _T(".png"), wxBITMAP_TYPE_PNG));
    button->Enable(n != _T("AddShortcut") && n != _T("Help") && n != _T("Key"));
    buttons_.push_back(button);

    button->Connect(
      wxID_ANY, 
      wxeEVT_CLICK,
      wxCommandEventHandler(OptionPanel::OnImageButtonClick),
      NULL,
      this);
  }

  Localize();
}


void OptionPanel::Localize() {
  if (configDialog_) configDialog_->Localize();

  for (int i = 0; i < buttons_.size(); i++) {
    OptionButton* button = buttons_.at(i);
    wxString buttonName = button->GetName();
    wxString stringId = _T("OptionPanel.");
    stringId += buttonName;
    stringId += _T("ToolTip");

    wxString toolTip = LOC(stringId);
    button->SetToolTip(toolTip);
  }
}


int OptionPanel::GetRequiredWidth() {
  return requiredWidth_;
}


void OptionPanel::InvalidateLayout() {
  layoutInvalidated_ = true;
  Refresh();
}


void OptionPanel::OnPaint(wxPaintEvent& evt) {
  BitmapControl::OnPaint(evt);
  
  if (layoutInvalidated_) UpdateLayout();
}


void OptionPanel::OnSize(wxSizeEvent& evt) {
  BitmapControl::OnSize(evt);

  InvalidateLayout();
}


void OptionPanel::UpdateLayout() {
  layoutInvalidated_ = false;
  
  int x = Styles::OptionPanel.PaddingLeft;
  int y = Styles::OptionPanel.PaddingTop;

  for (int i = 0; i < buttons_.size(); i++) {
    OptionButton* b = buttons_[i];

    int newX = x;
    int newY = y;

    if (newY + b->GetSize().GetHeight() > GetSize().GetHeight() - Styles::OptionPanel.PaddingBottom) {
      newY = Styles::OptionPanel.PaddingTop;
      newX = newX + b->GetSize().GetWidth() + Styles::OptionPanel.ButtonHGap;
    }

    b->Move(newX, newY);

    requiredWidth_ = newX + b->GetSize().GetWidth() + Styles::OptionPanel.PaddingRight;

    x = newX;
    y = newY + b->GetSize().GetHeight() + Styles::OptionPanel.ButtonVGap;
  }
}


void OptionPanel::OnImageButtonClick(wxCommandEvent& evt) {
  wxWindow* w = static_cast<wxWindow*>(evt.GetEventObject());
  wxString buttonName = w->GetName();

  if (buttonName == _T("Close")) {
    //***************************************************************************
    // CLOSE
    //***************************************************************************
    gMainFrame->Close();

  } else if (buttonName == _T("Minimize")) {
    //***************************************************************************
    // MINIMIZE
    //***************************************************************************
    gMainFrame->Hide();

  } else if (buttonName == _T("Eject")) {
    //***************************************************************************
    // EJECT
    //***************************************************************************
    gMainFrame->Close();
    #ifdef __WIN32__
    wxExecute(_T("RunDll32.exe shell32.dll,Control_RunDLL hotplug.dll"));
    #else
    wxLogDebug(_T("TO BE IMPLEMENTED"));
    #endif

  } else if (buttonName == _T("MultiLaunch")) {
    //***************************************************************************
    // MULTI-LAUNCH
    //***************************************************************************
    gController.GetUser()->DoMultiLaunch();

  } else if (buttonName == _T("Config")) {
    //***************************************************************************
    // CONFIG
    //***************************************************************************
    if (!configDialog_) configDialog_ = new ConfigDialog();
    configDialog_->LoadSettings();
    configDialog_->ShowModal();
  }
}


ConfigDialog* OptionPanel::GetConfigDialog() {
  return configDialog_;
}


OptionPanel::~OptionPanel() {
  if (configDialog_) {
    configDialog_->Destroy();
    configDialog_ = NULL;
  }
}