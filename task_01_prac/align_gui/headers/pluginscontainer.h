#ifndef PLUGINSCONTAINER_H
#define PLUGINSCONTAINER_H

#include <QHBoxLayout>
#include <QPushButton>
#include "../../shared/headers/pluginfilter.h"
#include "imageholder.h"
#include "../../shared/headers/model.h"
#include <QVector>
#include <QButtonGroup>
#include <QQueue>
#include <QComboBox>
#include <QDoubleSpinBox>

class PluginsContainer : public QHBoxLayout
{
    Q_OBJECT

    QVector<PluginFilter*> plugins;
    QVector<ImageHolder*> imageHolders;
    QBoxLayout* imageHoldersLayout;
    QProgressBar* progressBar;
    Model* model;
    Logger& Log;
    QComboBox* comboBox;
    QPushButton* applyButton;
    QLabel* paramsLabel;
    QDoubleSpinBox* param1;
    double params[1];

private:
    void CleanUp();

public:
    PluginsContainer(Model *model, QBoxLayout *layout, QProgressBar *progressBar, Logger& logger);
    ~PluginsContainer();

public slots:
    void ShowPlugins(QVector<PluginFilter*>);
    void ApplyButtonClicked();
    void FilterApplied(PluginFilter* filter, QImage *img);
    void ClearFilters();
    void RemoveLastFilter();
};

#endif // PLUGINSCONTAINER_H
