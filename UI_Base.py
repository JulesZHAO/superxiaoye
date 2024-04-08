# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'UI_Base.ui'
##
## Created by: Qt User Interface Compiler version 6.6.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QCheckBox, QFormLayout, QGroupBox,
    QHBoxLayout, QLabel, QLayout, QLineEdit,
    QProgressBar, QPushButton, QSizePolicy, QTabWidget,
    QVBoxLayout, QWidget)
import image_require

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(848, 688)
        self.horizontalLayout_53 = QHBoxLayout(Form)
        self.horizontalLayout_53.setObjectName(u"horizontalLayout_53")
        self.tabWidget = QTabWidget(Form)
        self.tabWidget.setObjectName(u"tabWidget")
        self.tab_5 = QWidget()
        self.tab_5.setObjectName(u"tab_5")
        self.formLayout_2 = QFormLayout(self.tab_5)
        self.formLayout_2.setObjectName(u"formLayout_2")
        self.verticalLayout_13 = QVBoxLayout()
        self.verticalLayout_13.setObjectName(u"verticalLayout_13")
        self.horizontalLayout_29 = QHBoxLayout()
        self.horizontalLayout_29.setObjectName(u"horizontalLayout_29")
        self.label_27 = QLabel(self.tab_5)
        self.label_27.setObjectName(u"label_27")
        self.label_27.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_29.addWidget(self.label_27)

        self.lineEdit_27 = QLineEdit(self.tab_5)
        self.lineEdit_27.setObjectName(u"lineEdit_27")

        self.horizontalLayout_29.addWidget(self.lineEdit_27)


        self.verticalLayout_13.addLayout(self.horizontalLayout_29)

        self.horizontalLayout_30 = QHBoxLayout()
        self.horizontalLayout_30.setObjectName(u"horizontalLayout_30")
        self.label_28 = QLabel(self.tab_5)
        self.label_28.setObjectName(u"label_28")
        self.label_28.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_30.addWidget(self.label_28)

        self.lineEdit_28 = QLineEdit(self.tab_5)
        self.lineEdit_28.setObjectName(u"lineEdit_28")

        self.horizontalLayout_30.addWidget(self.lineEdit_28)


        self.verticalLayout_13.addLayout(self.horizontalLayout_30)

        self.pushButton_4 = QPushButton(self.tab_5)
        self.pushButton_4.setObjectName(u"pushButton_4")

        self.verticalLayout_13.addWidget(self.pushButton_4)


        self.formLayout_2.setLayout(0, QFormLayout.LabelRole, self.verticalLayout_13)

        self.tabWidget.addTab(self.tab_5, "")
        self.tab_6 = QWidget()
        self.tab_6.setObjectName(u"tab_6")
        self.horizontalLayout_3 = QHBoxLayout(self.tab_6)
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.verticalLayout_14 = QVBoxLayout()
        self.verticalLayout_14.setObjectName(u"verticalLayout_14")
        self.label_3 = QLabel(self.tab_6)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setMaximumSize(QSize(640, 360))
        self.label_3.setPixmap(QPixmap(u":/image_require/\u672a\u547d\u540d\u7684\u8bbe\u8ba1-3.png"))
        self.label_3.setScaledContents(True)

        self.verticalLayout_14.addWidget(self.label_3, 0, Qt.AlignHCenter)

        self.lineEdit_29 = QLineEdit(self.tab_6)
        self.lineEdit_29.setObjectName(u"lineEdit_29")

        self.verticalLayout_14.addWidget(self.lineEdit_29)


        self.horizontalLayout_3.addLayout(self.verticalLayout_14)

        self.tabWidget.addTab(self.tab_6, "")
        self.tab_7 = QWidget()
        self.tab_7.setObjectName(u"tab_7")
        self.horizontalLayout_31 = QHBoxLayout(self.tab_7)
        self.horizontalLayout_31.setObjectName(u"horizontalLayout_31")
        self.verticalLayout_15 = QVBoxLayout()
        self.verticalLayout_15.setObjectName(u"verticalLayout_15")
        self.horizontalLayout_32 = QHBoxLayout()
        self.horizontalLayout_32.setObjectName(u"horizontalLayout_32")
        self.groupBox_23 = QGroupBox(self.tab_7)
        self.groupBox_23.setObjectName(u"groupBox_23")
        self.groupBox_23.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_33 = QHBoxLayout(self.groupBox_23)
        self.horizontalLayout_33.setObjectName(u"horizontalLayout_33")
        self.verticalLayout_16 = QVBoxLayout()
        self.verticalLayout_16.setObjectName(u"verticalLayout_16")
        self.verticalLayout_16.setSizeConstraint(QLayout.SetMinAndMaxSize)
        self.label_17 = QLabel(self.groupBox_23)
        self.label_17.setObjectName(u"label_17")
        self.label_17.setMaximumSize(QSize(160, 90))
        self.label_17.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-001-01.jpg"))
        self.label_17.setScaledContents(True)
        self.label_17.setAlignment(Qt.AlignCenter)
        self.label_17.setWordWrap(False)

        self.verticalLayout_16.addWidget(self.label_17, 0, Qt.AlignHCenter)

        self.horizontalLayout_34 = QHBoxLayout()
        self.horizontalLayout_34.setObjectName(u"horizontalLayout_34")
        self.checkBox_17 = QCheckBox(self.groupBox_23)
        self.checkBox_17.setObjectName(u"checkBox_17")

        self.horizontalLayout_34.addWidget(self.checkBox_17)

        self.lineEdit_17 = QLineEdit(self.groupBox_23)
        self.lineEdit_17.setObjectName(u"lineEdit_17")
        self.lineEdit_17.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_34.addWidget(self.lineEdit_17)


        self.verticalLayout_16.addLayout(self.horizontalLayout_34)


        self.horizontalLayout_33.addLayout(self.verticalLayout_16)


        self.horizontalLayout_32.addWidget(self.groupBox_23)

        self.groupBox_24 = QGroupBox(self.tab_7)
        self.groupBox_24.setObjectName(u"groupBox_24")
        self.groupBox_24.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_35 = QHBoxLayout(self.groupBox_24)
        self.horizontalLayout_35.setObjectName(u"horizontalLayout_35")
        self.verticalLayout_17 = QVBoxLayout()
        self.verticalLayout_17.setObjectName(u"verticalLayout_17")
        self.label_18 = QLabel(self.groupBox_24)
        self.label_18.setObjectName(u"label_18")
        self.label_18.setMaximumSize(QSize(160, 90))
        self.label_18.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-002-01.jpg"))
        self.label_18.setScaledContents(True)

        self.verticalLayout_17.addWidget(self.label_18, 0, Qt.AlignHCenter)

        self.horizontalLayout_36 = QHBoxLayout()
        self.horizontalLayout_36.setObjectName(u"horizontalLayout_36")
        self.checkBox_18 = QCheckBox(self.groupBox_24)
        self.checkBox_18.setObjectName(u"checkBox_18")

        self.horizontalLayout_36.addWidget(self.checkBox_18)

        self.lineEdit_18 = QLineEdit(self.groupBox_24)
        self.lineEdit_18.setObjectName(u"lineEdit_18")
        self.lineEdit_18.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_36.addWidget(self.lineEdit_18)


        self.verticalLayout_17.addLayout(self.horizontalLayout_36)


        self.horizontalLayout_35.addLayout(self.verticalLayout_17)


        self.horizontalLayout_32.addWidget(self.groupBox_24)

        self.groupBox_25 = QGroupBox(self.tab_7)
        self.groupBox_25.setObjectName(u"groupBox_25")
        self.groupBox_25.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_37 = QHBoxLayout(self.groupBox_25)
        self.horizontalLayout_37.setObjectName(u"horizontalLayout_37")
        self.verticalLayout_18 = QVBoxLayout()
        self.verticalLayout_18.setObjectName(u"verticalLayout_18")
        self.label_19 = QLabel(self.groupBox_25)
        self.label_19.setObjectName(u"label_19")
        self.label_19.setMaximumSize(QSize(160, 90))
        self.label_19.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-003-01.jpg"))
        self.label_19.setScaledContents(True)

        self.verticalLayout_18.addWidget(self.label_19, 0, Qt.AlignHCenter)

        self.horizontalLayout_38 = QHBoxLayout()
        self.horizontalLayout_38.setObjectName(u"horizontalLayout_38")
        self.checkBox_19 = QCheckBox(self.groupBox_25)
        self.checkBox_19.setObjectName(u"checkBox_19")

        self.horizontalLayout_38.addWidget(self.checkBox_19)

        self.lineEdit_19 = QLineEdit(self.groupBox_25)
        self.lineEdit_19.setObjectName(u"lineEdit_19")
        self.lineEdit_19.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_38.addWidget(self.lineEdit_19)


        self.verticalLayout_18.addLayout(self.horizontalLayout_38)


        self.horizontalLayout_37.addLayout(self.verticalLayout_18)


        self.horizontalLayout_32.addWidget(self.groupBox_25)


        self.verticalLayout_15.addLayout(self.horizontalLayout_32)

        self.horizontalLayout_39 = QHBoxLayout()
        self.horizontalLayout_39.setObjectName(u"horizontalLayout_39")
        self.groupBox_26 = QGroupBox(self.tab_7)
        self.groupBox_26.setObjectName(u"groupBox_26")
        self.groupBox_26.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_40 = QHBoxLayout(self.groupBox_26)
        self.horizontalLayout_40.setObjectName(u"horizontalLayout_40")
        self.verticalLayout_19 = QVBoxLayout()
        self.verticalLayout_19.setObjectName(u"verticalLayout_19")
        self.label_20 = QLabel(self.groupBox_26)
        self.label_20.setObjectName(u"label_20")
        self.label_20.setMaximumSize(QSize(160, 90))
        self.label_20.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-004-01.jpg"))
        self.label_20.setScaledContents(True)

        self.verticalLayout_19.addWidget(self.label_20, 0, Qt.AlignHCenter)

        self.horizontalLayout_41 = QHBoxLayout()
        self.horizontalLayout_41.setObjectName(u"horizontalLayout_41")
        self.checkBox_20 = QCheckBox(self.groupBox_26)
        self.checkBox_20.setObjectName(u"checkBox_20")

        self.horizontalLayout_41.addWidget(self.checkBox_20)

        self.lineEdit_20 = QLineEdit(self.groupBox_26)
        self.lineEdit_20.setObjectName(u"lineEdit_20")
        self.lineEdit_20.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_41.addWidget(self.lineEdit_20)


        self.verticalLayout_19.addLayout(self.horizontalLayout_41)


        self.horizontalLayout_40.addLayout(self.verticalLayout_19)


        self.horizontalLayout_39.addWidget(self.groupBox_26)

        self.groupBox_27 = QGroupBox(self.tab_7)
        self.groupBox_27.setObjectName(u"groupBox_27")
        self.groupBox_27.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_42 = QHBoxLayout(self.groupBox_27)
        self.horizontalLayout_42.setObjectName(u"horizontalLayout_42")
        self.verticalLayout_20 = QVBoxLayout()
        self.verticalLayout_20.setObjectName(u"verticalLayout_20")
        self.label_29 = QLabel(self.groupBox_27)
        self.label_29.setObjectName(u"label_29")
        self.label_29.setMaximumSize(QSize(160, 90))
        self.label_29.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-005-01.jpg"))
        self.label_29.setScaledContents(True)

        self.verticalLayout_20.addWidget(self.label_29, 0, Qt.AlignHCenter)

        self.horizontalLayout_43 = QHBoxLayout()
        self.horizontalLayout_43.setObjectName(u"horizontalLayout_43")
        self.checkBox_24 = QCheckBox(self.groupBox_27)
        self.checkBox_24.setObjectName(u"checkBox_24")

        self.horizontalLayout_43.addWidget(self.checkBox_24)

        self.lineEdit_30 = QLineEdit(self.groupBox_27)
        self.lineEdit_30.setObjectName(u"lineEdit_30")
        self.lineEdit_30.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_43.addWidget(self.lineEdit_30)


        self.verticalLayout_20.addLayout(self.horizontalLayout_43)


        self.horizontalLayout_42.addLayout(self.verticalLayout_20)


        self.horizontalLayout_39.addWidget(self.groupBox_27)

        self.groupBox_28 = QGroupBox(self.tab_7)
        self.groupBox_28.setObjectName(u"groupBox_28")
        self.groupBox_28.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_44 = QHBoxLayout(self.groupBox_28)
        self.horizontalLayout_44.setObjectName(u"horizontalLayout_44")
        self.verticalLayout_21 = QVBoxLayout()
        self.verticalLayout_21.setObjectName(u"verticalLayout_21")
        self.label_30 = QLabel(self.groupBox_28)
        self.label_30.setObjectName(u"label_30")
        self.label_30.setMaximumSize(QSize(160, 90))
        self.label_30.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-006-01.jpg"))
        self.label_30.setScaledContents(True)

        self.verticalLayout_21.addWidget(self.label_30, 0, Qt.AlignHCenter)

        self.horizontalLayout_45 = QHBoxLayout()
        self.horizontalLayout_45.setObjectName(u"horizontalLayout_45")
        self.checkBox_25 = QCheckBox(self.groupBox_28)
        self.checkBox_25.setObjectName(u"checkBox_25")

        self.horizontalLayout_45.addWidget(self.checkBox_25)

        self.lineEdit_31 = QLineEdit(self.groupBox_28)
        self.lineEdit_31.setObjectName(u"lineEdit_31")
        self.lineEdit_31.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_45.addWidget(self.lineEdit_31)


        self.verticalLayout_21.addLayout(self.horizontalLayout_45)


        self.horizontalLayout_44.addLayout(self.verticalLayout_21)


        self.horizontalLayout_39.addWidget(self.groupBox_28)


        self.verticalLayout_15.addLayout(self.horizontalLayout_39)

        self.horizontalLayout_46 = QHBoxLayout()
        self.horizontalLayout_46.setObjectName(u"horizontalLayout_46")
        self.groupBox_29 = QGroupBox(self.tab_7)
        self.groupBox_29.setObjectName(u"groupBox_29")
        self.groupBox_29.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_47 = QHBoxLayout(self.groupBox_29)
        self.horizontalLayout_47.setObjectName(u"horizontalLayout_47")
        self.verticalLayout_22 = QVBoxLayout()
        self.verticalLayout_22.setObjectName(u"verticalLayout_22")
        self.label_31 = QLabel(self.groupBox_29)
        self.label_31.setObjectName(u"label_31")
        self.label_31.setMaximumSize(QSize(160, 90))
        self.label_31.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-007-01.jpg"))
        self.label_31.setScaledContents(True)

        self.verticalLayout_22.addWidget(self.label_31, 0, Qt.AlignHCenter)

        self.horizontalLayout_48 = QHBoxLayout()
        self.horizontalLayout_48.setObjectName(u"horizontalLayout_48")
        self.checkBox_26 = QCheckBox(self.groupBox_29)
        self.checkBox_26.setObjectName(u"checkBox_26")

        self.horizontalLayout_48.addWidget(self.checkBox_26)

        self.lineEdit_32 = QLineEdit(self.groupBox_29)
        self.lineEdit_32.setObjectName(u"lineEdit_32")
        self.lineEdit_32.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_48.addWidget(self.lineEdit_32)


        self.verticalLayout_22.addLayout(self.horizontalLayout_48)


        self.horizontalLayout_47.addLayout(self.verticalLayout_22)


        self.horizontalLayout_46.addWidget(self.groupBox_29)

        self.groupBox_30 = QGroupBox(self.tab_7)
        self.groupBox_30.setObjectName(u"groupBox_30")
        self.groupBox_30.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_49 = QHBoxLayout(self.groupBox_30)
        self.horizontalLayout_49.setObjectName(u"horizontalLayout_49")
        self.verticalLayout_23 = QVBoxLayout()
        self.verticalLayout_23.setObjectName(u"verticalLayout_23")
        self.label_32 = QLabel(self.groupBox_30)
        self.label_32.setObjectName(u"label_32")
        self.label_32.setMaximumSize(QSize(160, 90))
        self.label_32.setPixmap(QPixmap(u":/image_require/\u4f01\u4e1a\u521b\u65b0\u89c6\u9891-Scene-011-01.jpg"))
        self.label_32.setScaledContents(True)

        self.verticalLayout_23.addWidget(self.label_32, 0, Qt.AlignHCenter)

        self.horizontalLayout_50 = QHBoxLayout()
        self.horizontalLayout_50.setObjectName(u"horizontalLayout_50")
        self.checkBox_27 = QCheckBox(self.groupBox_30)
        self.checkBox_27.setObjectName(u"checkBox_27")

        self.horizontalLayout_50.addWidget(self.checkBox_27)

        self.lineEdit_33 = QLineEdit(self.groupBox_30)
        self.lineEdit_33.setObjectName(u"lineEdit_33")
        self.lineEdit_33.setAlignment(Qt.AlignCenter)

        self.horizontalLayout_50.addWidget(self.lineEdit_33)


        self.verticalLayout_23.addLayout(self.horizontalLayout_50)


        self.horizontalLayout_49.addLayout(self.verticalLayout_23)


        self.horizontalLayout_46.addWidget(self.groupBox_30)

        self.groupBox_31 = QGroupBox(self.tab_7)
        self.groupBox_31.setObjectName(u"groupBox_31")
        self.groupBox_31.setAlignment(Qt.AlignCenter)
        self.horizontalLayout_51 = QHBoxLayout(self.groupBox_31)
        self.horizontalLayout_51.setObjectName(u"horizontalLayout_51")
        self.verticalLayout_24 = QVBoxLayout()
        self.verticalLayout_24.setObjectName(u"verticalLayout_24")
        self.progressBar_2 = QProgressBar(self.groupBox_31)
        self.progressBar_2.setObjectName(u"progressBar_2")
        self.progressBar_2.setValue(24)

        self.verticalLayout_24.addWidget(self.progressBar_2, 0, Qt.AlignHCenter)

        self.label_33 = QLabel(self.groupBox_31)
        self.label_33.setObjectName(u"label_33")
        self.label_33.setAlignment(Qt.AlignCenter)

        self.verticalLayout_24.addWidget(self.label_33, 0, Qt.AlignHCenter)

        self.horizontalLayout_52 = QHBoxLayout()
        self.horizontalLayout_52.setObjectName(u"horizontalLayout_52")
        self.pushButton_5 = QPushButton(self.groupBox_31)
        self.pushButton_5.setObjectName(u"pushButton_5")

        self.horizontalLayout_52.addWidget(self.pushButton_5)

        self.pushButton_6 = QPushButton(self.groupBox_31)
        self.pushButton_6.setObjectName(u"pushButton_6")

        self.horizontalLayout_52.addWidget(self.pushButton_6)


        self.verticalLayout_24.addLayout(self.horizontalLayout_52)


        self.horizontalLayout_51.addLayout(self.verticalLayout_24)


        self.horizontalLayout_46.addWidget(self.groupBox_31)


        self.verticalLayout_15.addLayout(self.horizontalLayout_46)


        self.horizontalLayout_31.addLayout(self.verticalLayout_15)

        self.tabWidget.addTab(self.tab_7, "")
        self.tab_8 = QWidget()
        self.tab_8.setObjectName(u"tab_8")
        self.horizontalLayout_4 = QHBoxLayout(self.tab_8)
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.label_4 = QLabel(self.tab_8)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setMaximumSize(QSize(640, 360))
        self.label_4.setPixmap(QPixmap(u":/image_require/\u672a\u547d\u540d\u7684\u8bbe\u8ba1-3.png"))
        self.label_4.setScaledContents(True)

        self.horizontalLayout_4.addWidget(self.label_4)

        self.tabWidget.addTab(self.tab_8, "")

        self.horizontalLayout_53.addWidget(self.tabWidget)


        self.retranslateUi(Form)

        self.tabWidget.setCurrentIndex(3)


        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Video_Cut", None))
        self.label_27.setText(QCoreApplication.translate("Form", u"\u8d26\u53f7", None))
        self.lineEdit_27.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u5e10\u53f7", None))
        self.label_28.setText(QCoreApplication.translate("Form", u"\u5bc6\u7801", None))
        self.lineEdit_28.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u5bc6\u7801", None))
        self.pushButton_4.setText(QCoreApplication.translate("Form", u"\u767b\u9646", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_5), QCoreApplication.translate("Form", u"\u767b\u9646\u9875\u9762", None))
        self.label_3.setText("")
        self.lineEdit_29.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u5904\u7406\u89c6\u9891\u8def\u5f84", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_6), QCoreApplication.translate("Form", u"\u89c6\u9891\u5bfc\u5165", None))
        self.groupBox_23.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb51", None))
        self.label_17.setText("")
        self.checkBox_17.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_17.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_24.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb52", None))
        self.label_18.setText("")
        self.checkBox_18.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_18.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_25.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb53", None))
        self.label_19.setText("")
        self.checkBox_19.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_19.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_26.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb54", None))
        self.label_20.setText("")
        self.checkBox_20.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_20.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_27.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb55", None))
        self.label_29.setText("")
        self.checkBox_24.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_30.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_28.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb56", None))
        self.label_30.setText("")
        self.checkBox_25.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_31.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_29.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb57", None))
        self.label_31.setText("")
        self.checkBox_26.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_32.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_30.setTitle(QCoreApplication.translate("Form", u"\u89c6\u9891\u7247\u6bb58", None))
        self.label_32.setText("")
        self.checkBox_27.setText(QCoreApplication.translate("Form", u"\u9009\u62e9", None))
        self.lineEdit_33.setPlaceholderText(QCoreApplication.translate("Form", u"\u8bf7\u8f93\u5165\u573a\u666f\u5907\u6ce8", None))
        self.groupBox_31.setTitle(QCoreApplication.translate("Form", u"\u5904\u7406\u4fe1\u606f", None))
        self.label_33.setText(QCoreApplication.translate("Form", u"\u8fdb\u5ea6", None))
        self.pushButton_5.setText(QCoreApplication.translate("Form", u"\u53d6\u6d88", None))
        self.pushButton_6.setText(QCoreApplication.translate("Form", u"\u5408\u6210\u9009\u62e9\u89c6\u9891", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_7), QCoreApplication.translate("Form", u"\u7247\u6bb5\u9009\u62e9", None))
        self.label_4.setText("")
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_8), QCoreApplication.translate("Form", u"\u89c6\u9891\u9884\u89c8", None))
    # retranslateUi

