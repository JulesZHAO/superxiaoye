from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QVBoxLayout, QLineEdit
from PySide6.QtCore import Qt
from UI_Base import Ui_Form

class MyWindow(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()

        # ����һ�� Ui_Form ���󣬲����丳ֵ�� self.ui
        # self.ui = Ui_Form()
        self.ui = Ui_Form()

        # ʹ�� self.ui �������� self �Ľ���
        self.ui.setupUi(self)

if __name__ == '__main__':
    app=QApplication([])
    window = MyWindow()
    window.show()
    app.exec()