#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QCompleter>
#include <QLabel>
#include <QMenu>
#include <QFile>
#include <QUrl>
#include <QSplitter>
#include <QCompleter>

#include "avrprogrammer.h"
#include "settings.h"
#include "avrpart.h"
#include "bitfielddelegate.h"
#include "bitfieldmodel.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    AvrPart *avrPart;
    AvrProgrammer *avrProgrammer;
    QStringList deviceNames;
    QCompleter *nameCompleter;
    Settings *settings;
    QButtonGroup *dataSourceButtonGroup;

    QLabel *statusBarLabel;

    BitFieldDelegate *lockFieldDelegate, *fuseFieldDelegate;
    RegisterValueDelegate *fuseValueDelegate;

    QCompleter *programmerArgumentsCompleter;

    void fillDeviceList();
    void calculateArgumentsLabelText();
    void fillDefaultTabComboBox();
    void programmerSelected();

    QProcess *m_programmerListQueryProcess;
    QString signatureToString(quint8 s0, quint8 s1, quint8 s2);

private slots:
    void on_horizontalSliderVTarget_sliderMoved(int position);
    void on_pushButtonProgramLockbits_clicked();
    void on_pushButtonReadLockbits_clicked();
    void on_checkBoxNoIcons_toggled(bool checked);
    void on_comboBoxFuseDisplaymode_activated(int index);
    void on_textEditMessages_anchorClicked(QUrl );
    void on_pushButtonReadReadEEPROM_clicked();
    void on_pushButtonVerifyEEPROM_clicked();
    void on_pushButtonProgramEEPROM_clicked();
    void on_comboBoxDefaultTab_activated(int index);
    void on_checkBoxLastTabRemember_toggled(bool checked);
    void on_pushButtonAboutQt_clicked();
    void on_pushButtonReadFuses_clicked();
    void on_pushButtonProgramFuses_clicked();
    void on_pushButtonReadReadFlash_clicked();
    void on_pushButtonVerifyFlash_clicked();
    void on_pushButtonProgramFlash_clicked();
    void on_lineEditEEPROMHex_textEdited(QString );
    void on_lineEditFlashHex_textEdited(QString );
    void on_pushButtonErase_clicked();
    void on_comboBoxDevice_activated(int index);
    void on_comboBoxProgrammer_activated(int index);
    void on_lineEditProgrammerPort_textEdited(QString );
    void on_lineEditProgOptions_textEdited(QString );
    void on_checkBoxOverrideProgrammersOptions_toggled(bool checked);
    void on_pushButtonReadSignature_clicked();
    void on_pushButtonAvrDude_clicked();
    void on_lineEditAvrDudePath_textEdited(QString );
    void on_lineEditXmlsPath_textEdited(QString );
    void on_pushButtonBrowseXmls_clicked();
    void on_checkBoxShowAvrDudeOutput_toggled(bool checked);
    void on_pushButtonClearAvrDudeOutput_clicked();
    void showFlashHexFileBrowse();
    void showEEPROMHexFileBrowse();
    void clearMessages();
    void avrDudeOut(QString str);
    void signatureRead(quint8 s0, quint8 s1, quint8 s2);
    void logMessage(QString msg);
    void logError(QString msg);
    void progressStep();
    void verifyFailed(QString what, int offset, int value_read, int value_waited);
    void deviceChanged(); // a slot to open all delegate on the fuse and lockbytefield tableviews
    void on_pushButtonVerifyFuses_clicked();
    void on_pushButtonReadVoltages_clicked();
    void on_pushButtonWriteVoltages_clicked();
    void on_radioButtonUseXML_clicked();
    void on_radioButtonUseSqlite_clicked();
    void on_pushButtonBrowseSqlite_clicked();
    void on_lineEditProgOptions_editingFinished();
    void on_textEditMessages_customContextMenuRequested(const QPoint &pos);
    void programmerQueryFinished(int status, QProcess::ExitStatus exitStatus);
};

#endif // MAINWINDOW_H
