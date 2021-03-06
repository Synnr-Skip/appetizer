#include "MessageBoxes.h"
#include "Localization.h"
#include <wx/msgdlg.h>


int MessageBoxes::ShowError(const wxString& message, long style) {
  wxMessageDialog dialog(NULL, message, LOC(_T("MessageBox.Error")), style | wxICON_ERROR);
  return dialog.ShowModal();
}


int MessageBoxes::ShowWarning(const wxString& message, long style) {
  wxMessageDialog dialog(NULL, message, LOC(_T("MessageBox.Warning ")), style | wxICON_EXCLAMATION);
  return dialog.ShowModal();
}


int MessageBoxes::ShowConfirmation(const wxString& message, long style) {
  wxMessageDialog dialog(NULL, message, LOC(_T("MessageBox.Confirmation")), style | wxICON_QUESTION);
  return dialog.ShowModal();
}