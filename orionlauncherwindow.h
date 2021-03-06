/***********************************************************************************
**
** OrionLauncherWindow.h
**
** Copyright (C) December 2016 Hotride
** Copyright (C) December 2018 Danny Angelo Carminati Grein
**
************************************************************************************
*/
#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>
#include "changelogform.h"
#include "updatemanager.h"
#include <QTimer>

namespace Ui
{
class OrionLauncherWindow;
}

class OrionLauncherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrionLauncherWindow(QWidget *parent = nullptr);
    ~OrionLauncherWindow();

protected:
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_lw_ServerList_clicked(const QModelIndex &index);
    void on_lw_ServerList_doubleClicked(const QModelIndex &index);
    void on_cb_ServerShowPassword_clicked();
    void on_pb_ServerAdd_clicked();
    void on_pb_ServerSave_clicked();
    void on_pb_ServerRemove_clicked();
    void on_le_CommandLine_textChanged(const QString &arg1);
    void on_lw_ProxyList_clicked(const QModelIndex &index);
    void on_cb_ProxyShowPassword_clicked();
    void on_pb_ProxyAdd_clicked();
    void on_pb_ProxySave_clicked();
    void on_pb_ProxyRemove_clicked();
    void on_tb_SetOrionPath_clicked();
    void on_pb_Launch_clicked();
    void on_cb_LaunchAutologin_clicked();
    void on_cb_LaunchSavePassword_clicked();
    void on_cb_LaunchSaveAero_clicked();
    void on_cb_LaunchFastLogin_clicked();
    void on_cb_LaunchRunUOAM_clicked();
    void on_lw_OAFeaturesOptions_clicked(const QModelIndex &index);
    void on_lw_OAFeaturesScripts_clicked(const QModelIndex &index);
    void on_rb_OAFeaturesSphere_clicked();
    void on_rb_OAFeaturesRunUO_clicked();
    void on_rb_OAFeaturesPOL_clicked();
    void on_pb_CheckUpdates_clicked();
    void on_cb_OrionPath_currentIndexChanged(int index);
    void on_pb_ApplyUpdates_clicked();
    void on_pb_ConfigureClientVersion_clicked();
    void on_pb_RestoreSelectedVersion_clicked();
    void on_pb_ShowChangelog_clicked();
    void on_lw_Backups_doubleClicked(const QModelIndex &index);
    void on_lw_OrionFeaturesOptions_clicked(const QModelIndex &index);
    void on_rb_OrionFeaturesSphere_clicked();
    void on_rb_OrionFeaturesRunUO_clicked();
    void on_rb_OrionFeaturesPOL_clicked();
    void on_pb_Process_clicked();
    void on_tb_SetManifestPath_clicked();

    void onUpdatesListReceived(const QList<CFileInfo> &list);
    void onBackupsListReceived(const QList<CFileInfo> &list);
    void onFileReceived(const QString &name);
    void onUpdatesTimer();
    void onCheckClientCuoTimer();
    void onDownloadProgress(qint64 bytesRead, qint64 totalBytes);

    void unzipPackage(const QString &filename, const QString &toPath);

signals:
    void updatesListReceived(const QList<CFileInfo> &);
    void backupsListReceived(const QList<CFileInfo> &);
    void changelogReceived(const QString &);
    void fileReceived(const QDir &);
    void autoUpdateProgress(int);
    void autoUpdateNotification();

private:
    Ui::OrionLauncherWindow *ui = nullptr;
    int m_FilesToUpdateCount = 0;
    bool m_Loading = true;
    bool m_LauncherFoundInUpdates = false;
    ChangelogForm *m_ChangelogForm = nullptr;
    UpdateManager *m_UpdateManager = nullptr;
    QTimer m_UpdatesTimer;
    QTimer m_CheckClientCuoTimer;

    void updateServerFields(const int &index);
    QString boolToText(const bool &value);

    bool rawStringToBool(QString value);
    void saveProxyList();
    void saveServerList();
    void loadProxyList();
    void loadServerList();

    QString decodeArgumentString(const char *text, const int &length);
    QString encodeArgumentString(const char *text, const int &length);

    void runProgram(const QString &exePath, const QString &directory);
    void updateOAFeaturesCode();
    void updateOrionFeaturesCode();
};
