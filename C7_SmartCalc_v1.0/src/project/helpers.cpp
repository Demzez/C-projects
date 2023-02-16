#include "helpers.h"

void errorMsg(QString textError) {
    QMessageBox errorMsgBox;
    errorMsgBox.setText(textError);
    errorMsgBox.exec();
}

int verification(QString str) {
    int flag = 1;
    int dot_count = 0;
    for (int i = 0; i < str.length(); i++) {
        QChar ch = str[i];
        if (!ch.isDigit() && ch != '.' && ch != '-') {
            flag = 0;
            break;
        }
        if (i == 0 && ch == '.') {
            flag = 0;
            break;
        }
        if (ch == '-' && i != 0) {
            flag = 0;
            break;
        }
        if (ch == '.')
            dot_count++;
    }
    if (str.length() > 2)
        if (str[0] == '-' && str[1] == '0' && str[2] != '.')
            flag = 0;
    if (str.length() > 1)
        if ((str[0] == '0' && str[1] != '.') || (str[0] == '-' && str[1] == '.'))
            flag = 0;
    if (dot_count > 1)
        flag = 0;
    return flag;
}

int verification_digit(QString str) {
    int flag = 1;
    if (!str.isEmpty()) {
        for (int i = 0; i < str.length(); i++) {
            if (!str[i].isDigit()) {
                flag = 0;
                break;
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}
