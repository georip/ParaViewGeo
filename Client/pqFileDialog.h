/*
 * Copyright 2004 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

#ifndef _pqFileDialog_h
#define _pqFileDialog_h

#include "pqFileDialog.ui.h"

class pqFileDialogModel;

class pqFileDialog :
  public QDialog
{
  typedef QDialog base;
  
  Q_OBJECT
  
public:
  pqFileDialog(pqFileDialogModel* Model, const QString& Title, QWidget* Parent, const char* const Name);

signals:
  void fileSelected(const QString&);

private:
  ~pqFileDialog();
  pqFileDialog(const pqFileDialog&);
  pqFileDialog& operator=(const pqFileDialog&);

  pqFileDialogModel* model();

  void accept();
  void reject();
  
  Ui::pqFileDialog ui;
  const QModelIndex* temp;
  
private slots:
  void onDataChanged(const QModelIndex&, const QModelIndex&);
  void onActivated(const QModelIndex&);
  void onNavigateDown();
  void onAutoDelete(); 
};

#endif // !_pqFileDialog_h
