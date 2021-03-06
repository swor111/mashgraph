#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "pluginfilter.h"
#include "logger.h"
#include <QVector>
#include <vector>

class PluginManager : public Manager
{
    QVector<PluginFilter*> plugins;
    void* libHandles[256] = {};  //QVector<void*> and std::vector<void*> - runtime error - ???
    int nLibHandles = 0;
    Logger& Log;

private:
    void CleanUp();

public:
    PluginManager(Logger& log);
    virtual void RegisterPlugin(Singleton* singleton) override;
    void LoadPlugins(const QString& dirpath);
    QVector<PluginFilter*> GetPlugins();
    ~PluginManager();
};

#endif // PLUGINMANAGER_H
