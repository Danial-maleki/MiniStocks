#!/bin/bash
make clean
qmake StockTicker.pro
sed -i 's/#include <QtWidgets\/QAction>/#include <QAction>/g' ui_settingsdialog.h 2>/dev/null || true
make
