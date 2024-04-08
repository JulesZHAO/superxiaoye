from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QVBoxLayout, QLineEdit
from PySide6.QtCore import Qt
from UI_Base import Ui_Form

class MyWindow(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()

        # 创建一个 Ui_Form 对象，并将其赋值给 self.ui
        # self.ui = Ui_Form()
        self.ui = Ui_Form()

        # 使用 self.ui 对象设置 self 的界面
        self.ui.setupUi(self)

if __name__ == '__main__':
    app=QApplication([])
    window = MyWindow()
    window.show()
    app.exec()